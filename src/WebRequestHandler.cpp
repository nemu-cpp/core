/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "WebRequestHandler.hpp"

namespace Nemu
{

WebRequestHandler::WebRequestHandler(RequestHandler handler)
    : m_handler(handler)
{
}

WebRequestHandler::WebRequestHandler(RequestHandler handler, std::shared_ptr<void> handlerData)
    : m_handler(handler), m_handlerData(handlerData)
{
}

void WebRequestHandler::run(const WebRequest& request, WebResponseBuilder& response, Ishiko::Logger& logger) const
{
    m_handler(request, response, m_handlerData.get(), logger);
}

}
