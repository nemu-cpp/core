/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "Route.h"

using namespace Ishiko;

namespace Nemu
{

Route::Route(const std::string& path, RequestHandler handler)
    : m_path(path), m_handler(handler)
{
}

Route::Route(const std::string& path, RequestHandler handler, std::shared_ptr<void> handlerData)
    : m_path(path), m_handler(handler), m_handlerData(handlerData)
{
}

const std::string& Route::path() const
{
    return m_path;
}

Route::RequestHandler Route::handler() const
{
    return m_handler;
}

void* Route::handlerData() const
{
    return m_handlerData.get();
}

void Route::runHandler(const WebRequest& request, WebResponseBuilder& response, Logger& logger) const
{
    m_handler(request, response, m_handlerData.get(), logger);
}

}
