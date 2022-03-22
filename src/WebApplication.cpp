/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "WebApplication.hpp"

namespace Nemu
{

WebApplication::WebApplication(Logger& logger, Ishiko::Error& error)
    : Application(logger), m_routes(std::make_shared<Routes>())
{
}

WebApplication::WebApplication(Logger& logger, std::shared_ptr<Routes> routes, Ishiko::Error& error)
    : Application(logger), m_routes(routes)
{
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
