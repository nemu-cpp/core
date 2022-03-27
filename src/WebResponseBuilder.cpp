/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "WebResponseBuilder.hpp"

namespace Nemu
{

WebResponseBuilder::WebResponseBuilder()
    : m_views(nullptr)
{
}

void WebResponseBuilder::view(const std::string& viewName)
{
    body() = m_views->engine().render();
}

void WebResponseBuilder::redirect()
{
}

void WebResponseBuilder::state()
{
}

}
