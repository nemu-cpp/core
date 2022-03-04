/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "WebApplication.hpp"

namespace Nemu
{

WebApplication::WebApplication(const Configuration& configuration, Logger& logger, std::shared_ptr<Observer> observer,
    Ishiko::Error& error)
    : Application(logger, observer), m_routes(std::make_shared<Routes>())
{
    // TODO: construct server entirely outside of WebApplication to give maximu flexibility
    //servers().append(std::make_shared<BeastServer>(configuration.numberOfThreads(), configuration.address(),
    //    configuration.port(), *m_routes, m_views, observer, error));
}

WebApplication::WebApplication(const Configuration& configuration, Logger& logger, std::shared_ptr<Routes> routes,
    std::shared_ptr<Observer> observer, Ishiko::Error& error)
    : Application(logger, observer), m_routes(routes)
{
    // TODO: construct server entirely outside of WebApplication to give maximu flexibility
    //servers().append(std::make_shared<BeastServer>(configuration.numberOfThreads(), configuration.address(),
    //    configuration.port(), *m_routes, m_views, observer, error));
}

Routes& WebApplication::routes()
{
    return *m_routes;
}

Views& WebApplication::views()
{
    return m_views;
}

}
