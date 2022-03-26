/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "Application.h"
#include "Applications.h"
#ifdef _WIN32
#include "ControlHandlerRegistration.h"
#endif
#include "LoggingMacros.hpp"
#include <algorithm>

using namespace Ishiko;

namespace Nemu
{

void Application::Observer::onApplicationStarting(const Application& source)
{
}

void Application::Observer::onApplicationStarted(const Application& source)
{
}

void Application::Observer::onApplicationStopping(const Application& source)
{
}

void Application::Observer::onApplicationStopped(const Application& source)
{
}

void Application::Observers::add(std::shared_ptr<Observer> observer)
{
    auto it = std::find_if(m_observers.begin(), m_observers.end(),
        [&observer](const std::pair<std::weak_ptr<Observer>, size_t>& o)
        {
            return (o.first.lock() == observer);
        }
    );
    if (it != m_observers.end())
    {
        ++it->second;
    }
    else
    {
        m_observers.push_back(std::pair<std::weak_ptr<Observer>, size_t>(observer, 1));
    }
}

void Application::Observers::remove(std::shared_ptr<Observer> observer)
{
    auto it = std::find_if(m_observers.begin(), m_observers.end(),
        [&observer](const std::pair<std::weak_ptr<Observer>, size_t>& o)
        {
            return (o.first.lock() == observer);
        }
    );
    if (it != m_observers.end())
    {
        --it->second;
        if (it->second == 0)
        {
            m_observers.erase(it);
        }
    }
}

void Application::Observers::notify(void (Observer::*fct)(const Application& source), const Application& source)
{
    for (std::pair<std::weak_ptr<Observer>, size_t>& o : m_observers)
    {
        std::shared_ptr<Observer> observer = o.first.lock();
        if (observer)
        {
            ((*observer).*fct)(source);
        }
        else
        {
            removeDeletedObservers();
        }
    }
}

void Application::Observers::removeDeletedObservers()
{
    auto it = std::remove_if(m_observers.begin(), m_observers.end(),
        [](const std::pair<std::weak_ptr<Observer>, size_t>& o)
        {
            return o.first.expired();
        }
    );
    m_observers.erase(it, m_observers.end());
}

Application::Application(Logger& logger)
    : m_logger(logger)
{
    Applications::set(this);
}

Application::~Application()
{
    Applications::unset(this);
}

void Application::run()
{
    // The "logger" alias is what is used by the MENU_LOG_lvl macros
    Logger& logger = m_logger;

    NEMU_LOG_INFO("Application starting");
    
    m_observers.notify(&Observer::onApplicationStarting, *this);

#ifdef _WIN32
    m_controlHandlerRegistration = std::make_unique<ControlHandlerRegistration>();
#endif

    // First we start all the servers, note that the Servers::startAll() function does not block
    servers().startAll();

    size_t running = m_servers.numberOfRunningServers();
    NEMU_LOG_INFO("Application started ({} server{} running", running, ((running != 1) ? "s" : ""));

    m_observers.notify(&Observer::onApplicationStarted, *this);

    // By default we want the Application::start() function to block so we call Servers::joinAll() which will do a join
    // on all the servers
    servers().joinAll();

    running = m_servers.numberOfRunningServers();
    NEMU_LOG_INFO("Application stopped ({} server{} running", running, ((running != 1) ? "s" : ""));

    m_observers.notify(&Observer::onApplicationStopped, *this);
}

void Application::stop()
{
    // The "logger" alias is what is used by the MENU_LOG_lvl macros
    Logger& logger = m_logger;

    NEMU_LOG_INFO("Application stopping");

    m_observers.notify(&Observer::onApplicationStopping, *this);

    servers().stopAll();

#ifdef _WIN32
    m_controlHandlerRegistration.reset();
#endif
}

const Servers& Application::servers() const
{
    return m_servers;
}

Application::Observers& Application::observers()
{
    return m_observers;
}

Servers& Application::servers()
{
    return m_servers;
}

}
