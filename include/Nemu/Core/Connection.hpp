/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_CONNECTION_HPP_
#define _NEMU_CPP_CORE_CONNECTION_HPP_

#include <Ishiko/Networking.hpp>

namespace Nemu
{

// TODO: represents an established connection between a client and a server e.g. a TCP connection. At the moment this
// is just a wrapper around a TCP socket and I'm unsure whether it can be successful as an abstraction or if it will 
// differ too much across connection types. Also investigate overhead.
// For now only cope with TCP
class Connection
{
};

}

#endif
