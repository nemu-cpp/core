/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "Servers.hpp"

namespace Nemu
{

void Servers::startAll()
{
    // First we start all the servers, note that the Server::start()
    // function does not block
    for (std::shared_ptr<Server>& server : m_servers)
    {
        server->start();
    }
}

void Servers::joinAll()
{
    for (std::shared_ptr<Server>& server : m_servers)
    {
        server->join();
    }
}

void Servers::stopAll()
{
    for (std::shared_ptr<Server>& server : m_servers)
    {
        server->stop();
    }
}

void Servers::append(std::shared_ptr<Server> server)
{
    m_servers.push_back(server);
}

size_t Servers::numberOfRunningServers() const
{
    size_t result = 0;
    for (const std::shared_ptr<Server>& server : m_servers)
    {
        result += server->isRunning();
    }
    return result;
}

}
