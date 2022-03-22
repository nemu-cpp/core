/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "WebApplication.hpp"

using namespace Ishiko;
using namespace std;

namespace Nemu
{

WebApplication::WebApplication(shared_ptr<Server> server, Logger& logger, Error& error)
    : Application(logger), m_routes(std::make_shared<Routes>())
{
    server->m_logger = &logger;
    server->m_routes = m_routes.get();
    servers().append(server);
}

WebApplication::WebApplication(shared_ptr<Server> server, Logger& logger, shared_ptr<Routes> routes, Error& error)
    : Application(logger), m_routes(routes)
{
    server->m_logger = &logger;
    server->m_routes = m_routes.get();
    servers().append(server);
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
