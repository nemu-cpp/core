/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "Route.h"

using namespace Ishiko;

namespace Nemu
{

Route::Route(const std::string& path, WebRequestHandler handler)
    : m_path(path), m_handler(handler)
{
}

const std::string& Route::path() const
{
    return m_path;
}

void Route::runHandler(const WebRequest& request, WebResponseBuilder& response, Logger& logger) const
{
    m_handler.run(request, response, logger);
}

}
