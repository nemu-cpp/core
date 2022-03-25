/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_WEBREQUESTHANDLER_HPP_
#define _NEMU_CPP_CORE_WEBREQUESTHANDLER_HPP_

#include "WebRequest.hpp"
#include "WebResponseBuilder.hpp"
#include <Ishiko/Logging.hpp>
#include <memory>

namespace Nemu
{

class WebRequestHandler
{
public:
    // TODO: update comment
    /// The type definition for the request handlers.
    /**
        @param request The request that was received from the client.
        @param response This argument is used to build the response that will be returned to the client.
        @param handlerData Additional data required by the handler. This data can be stored in the route at construction
        time and retrieved with the Route::handlerData() accessor.
    */
    typedef void (*RequestHandler)(const WebRequest& request, WebResponseBuilder& response, void* handlerData,
        Ishiko::Logger& logger);

    WebRequestHandler(RequestHandler handler);
    template<class Callable> WebRequestHandler(Callable handler);
    WebRequestHandler(RequestHandler handler, std::shared_ptr<void> handlerData);

    void run(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger) const;

private:
    // TODO: std::function and _data are redundant but before I change this I want to understand the performance implications better
    std::function<void(const WebRequest& request, WebResponseBuilder& response, void* handlerData, Ishiko::Logger& logger)> m_handler;
    std::shared_ptr<void> m_handlerData;
};

template<class Callable>
WebRequestHandler::WebRequestHandler(Callable handler)
    : m_handler(handler)
{
}

}

#endif
