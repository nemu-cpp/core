/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "Server.hpp"
#include <algorithm>

namespace Nemu
{

void Server::Observer::onServerStarted(const Server& source)
{
}

void Server::Observer::onServerStopped(const Server& source)
{
}

void Server::Observer::onConnectionOpened(const Server& source, const std::string& sourceAddress)
{
}

void Server::Observer::onConnectionClosed(const Server& source, const std::string& sourceAddress)
{
}

void Server::Observers::add(std::shared_ptr<Observer> observer)
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

void Server::Observers::remove(std::shared_ptr<Observer> observer)
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

void Server::Observers::notify(void (Observer::*fct)(const Server& source), const Server& source)
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

void Server::Observers::notify(void (Observer::*fct)(const Server& source, const std::string& sourceAddress),
    const Server& source, const std::string& sourceAddress)
{
    for (std::pair<std::weak_ptr<Observer>, size_t>& o : m_observers)
    {
        std::shared_ptr<Observer> observer = o.first.lock();
        if (observer)
        {
            ((*observer).*fct)(source, sourceAddress);
        }
        else
        {
            removeDeletedObservers();
        }
    }
}

void Server::Observers::removeDeletedObservers()
{
    auto it = std::remove_if(m_observers.begin(), m_observers.end(),
        [](const std::pair<std::weak_ptr<Observer>, size_t>& o)
        {
            return o.first.expired();
        }
    );
    m_observers.erase(it, m_observers.end());
}

Server::Server(std::shared_ptr<Observer> observer)
{
    m_observers.add(observer);
}

Server::Observers& Server::observers()
{
    return m_observers;
}

}
