/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_WEBRESPONSEBUILDER_HPP_
#define _NEMU_CPP_CORE_WEBRESPONSEBUILDER_HPP_

#include "Web/Views.hpp"
#include <Ishiko/Time.hpp>
#include <string>

namespace Nemu
{

/// An interface to create the response that will be sent back to the client.
class WebResponseBuilder
{
public:
    WebResponseBuilder();

    virtual void setStatus(unsigned int status) = 0;
    virtual void setDateHeader(const Ishiko::UTCTime& time) = 0;
    virtual std::string& body() = 0;

    /// Renders a page using the default templating engine.
    /**
        @param viewName The name of the view to render. How this name is used to find the right template depends on the
        engine and its options.
    */
    void view(const std::string& viewName);

    void redirect();

    void state();

public:
    const Views* m_views;
};

}

#endif
