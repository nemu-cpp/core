/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_ROUTE_H_
#define _NEMU_CPP_CORE_ROUTE_H_

#include "WebRequest.hpp"
#include "Web/RequestHandlers/WebRequestHandler.hpp"
#include "WebResponseBuilder.hpp"
#include <Ishiko/Logging.hpp>
#include <string>

namespace Nemu
{

/// A request routing specification for a web application.
class Route
{
public:
    /// Constructor.
    /**
        @param path The handler handles requests that match this path.
        @param handler The request handler.
    */
    Route(const std::string& path, WebRequestHandler handler);
    
    /// Returns the path.
    const std::string& path() const;

    void runHandler(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger) const;

private:
    std::string m_path;
    WebRequestHandler m_handler;
};

}

#endif
