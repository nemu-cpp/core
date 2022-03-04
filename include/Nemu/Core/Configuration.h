/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_CONFIGURATION_H_
#define _NEMU_CPP_CORE_CONFIGURATION_H_

#include <string>

namespace Nemu
{

class Configuration
{
public:
    Configuration(int argc, const char* argv[], const std::string& defaultAddress = "0.0.0.0", unsigned short defaultPort = 80);
    Configuration(const std::string& address, unsigned short port);

    size_t numberOfThreads() const;
    const std::string& address() const;
    unsigned short port() const;

private:
    size_t m_numberOfThreads;
    std::string m_address;
    unsigned short m_port;
};

}

#endif
