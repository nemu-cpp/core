/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_ROUTE_H_
#define _NEMU_CPP_CORE_ROUTE_H_

#include "Logger.hpp"
#include "WebRequest.hpp"
#include "WebResponseBuilder.hpp"
#include <string>
#include <memory>

namespace Nemu
{

/// A request routing specification for a web application.
class Route
{
public:
    /// The type definition for the request handlers.
    /**
        @param request The request that was received from the client.
        @param response This argument is used to build the response that will be returned to the client.
        @param handlerData Additional data required by the handler. This data can be stored in the route at construction
        time and retrieved with the Route::handlerData() accessor.
    */
    typedef void (*RequestHandler)(const WebRequest& request, WebResponseBuilder& response, void* handlerData,
        Logger& logger);

    /// Constructor.
    /**
        @param path The handler handles requests that match this path.
        @param handler The request handler.
    */
    Route(const std::string& path, RequestHandler handler);
    Route(const std::string& path, RequestHandler handler, std::shared_ptr<void> handlerData);

    /// Returns the path.
    const std::string& path() const;
    /// Returns the handler.
    RequestHandler handler() const;
    void* handlerData() const;

    void runHandler(const WebRequest& request, WebResponseBuilder& response, Logger& logger) const;

private:
    std::string m_path;
    RequestHandler m_handler;
    std::shared_ptr<void> m_handlerData;
};

}

#endif
