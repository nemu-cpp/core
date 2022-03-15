/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "Configuration.h"
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>

using namespace Ishiko;
using namespace Ishiko::Networking;
using namespace std;

namespace Nemu
{

Configuration::Configuration(int argc, char* argv[], IPv4Address defaultAddress, Port defaultPort)
    : m_port(defaultPort)
{
    string ipAddress;
    unsigned short port;

    boost::program_options::options_description description("Command line arguments");
    description.add_options()
        ("address", boost::program_options::value<std::string>(&ipAddress)->value_name("str")->default_value(defaultAddress.toString()),
            "the listening IP address")
        ("port", boost::program_options::value<unsigned short>(&port)->value_name("p")->default_value(defaultPort.number()),
            "the listening port")
        ("threads", boost::program_options::value<size_t>(&m_numberOfThreads)->value_name("n")->default_value(1),
            "the number of threads that will be used to process incoming requests");

    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, description), vm);
    boost::program_options::notify(vm);

    // TODO: handle error
    Error error;
    m_ipAddress = IPv4Address(ipAddress, error);
    m_port = Port(port);
}

Configuration::Configuration(int argc, const char* argv[], IPv4Address defaultAddress, Port defaultPort)
    : m_port(defaultPort)
{
    string ipAddress;
    unsigned short port;

    boost::program_options::options_description description("Command line arguments");
    description.add_options()
        ("address", boost::program_options::value<std::string>(&ipAddress)->value_name("str")->default_value(defaultAddress.toString()),
            "the listening IP address")
        ("port", boost::program_options::value<unsigned short>(&port)->value_name("p")->default_value(defaultPort.number()),
            "the listening port")
        ("threads", boost::program_options::value<size_t>(&m_numberOfThreads)->value_name("n")->default_value(1),
            "the number of threads that will be used to process incoming requests");

    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, description), vm);
    boost::program_options::notify(vm);

    // TODO: handle error
    Error error;
    m_ipAddress = IPv4Address(ipAddress, error);
    m_port = Port(port);
}

Configuration::Configuration(IPv4Address address, Port port)
    : m_ipAddress(address), m_port(port)
{
}

size_t Configuration::numberOfThreads() const
{
    return m_numberOfThreads;
}

IPv4Address Configuration::ipAddress() const
{
    return m_ipAddress;
}

Port Configuration::port() const
{
    return m_port;
}

}
