/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "Web/RequestHandlers/HardcodedWebRequestHandler.hpp"

using namespace Ishiko;

namespace Nemu
{

HardcodedWebRequestHandler::HardcodedWebRequestHandler(unsigned int statusCode, const char* responseBody)
    : m_statusCode(statusCode), m_responseBody(responseBody)
{
}

void HardcodedWebRequestHandler::run(const WebRequest& request, WebResponseBuilder& response, Logger& logger)
{
    // TODO
    //session.response().setStatusCode(m_statusCode);
    //session.response().sendBuffer();
}

}
