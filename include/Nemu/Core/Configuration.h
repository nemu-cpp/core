/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_CONFIGURATION_H_
#define _NEMU_CPP_CORE_CONFIGURATION_H_

#include <Ishiko/Networking.hpp>

namespace Nemu
{

class Configuration
{
public:
    Configuration(int argc, char* argv[], Ishiko::Networking::IPv4Address defaultAddress,
        Ishiko::Networking::Port defaultPort);
    Configuration(int argc, const char* argv[], Ishiko::Networking::IPv4Address defaultAddress,
        Ishiko::Networking::Port defaultPort);
    Configuration(Ishiko::Networking::IPv4Address address, Ishiko::Networking::Port port);

    size_t numberOfThreads() const;
    Ishiko::Networking::IPv4Address ipAddress() const;
    Ishiko::Networking::Port port() const;

private:
    size_t m_numberOfThreads;
    Ishiko::Networking::IPv4Address m_ipAddress;
    Ishiko::Networking::Port m_port;
};

}

#endif
