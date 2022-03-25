/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_WEBREQUEST_HPP_
#define _NEMU_CPP_CORE_WEBREQUEST_HPP_

#include <string>

namespace Nemu
{

/// An interface to the request that was received from the client.
class WebRequest
{
public:
    /// Returns the URI part of the request.
    // TODO: can we avoid the copy here
    virtual std::string URI() const = 0;
};

}

#endif
