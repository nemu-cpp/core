/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "Routes.h"

namespace Nemu
{

Routes::Routes()
    : m_defaultRoute("",
        [](const WebRequest& request, WebResponseBuilder& response, void* handlerData, Logger& logger)
        {
            response.setStatus(404);
        })
{
}

void Routes::append(const Route& route)
{
    m_routes.push_back(route);
}

const Route& Routes::match(const std::string& path) const
{
    for (const Route& route : m_routes)
    {
        if (route.path() == path)
        {
            return route;
        }
    }
    return m_defaultRoute;
}

const Route& Routes::defaultRoute() const
{
    return m_defaultRoute;
}

void Routes::setDefaultRoute(const Route& route)
{
    m_defaultRoute = route;
}

}
