/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_SERVERS_HPP_
#define _NEMU_CPP_CORE_SERVERS_HPP_

#include "Server.hpp"
#include <vector>
#include <memory>

namespace Nemu
{

/// A list of servers.
/**
    This class is used by the Application class to store its list of servers. There should usually be no need to create
    an instance of this class yourself.
*/
class Servers
{
public:
    /// Starts all the servers in the list.
    /**
        This function doesn't block and returns immediately. It simply calls Server::start on each server in the list.
    */
    void startAll();
    /// Stops all the servers in the list.
    /**
        This function simply calls Server::stop on each server in the list.
    */
    void stopAll();
    /// Wait until all servers in the list have stopped.
    /**
        This function simply calls Server::join on each server in the list.
    */
    void joinAll();

    /// Appends a server to the list.
    /**
        @param server The server to add to the list.
    */
    void append(std::shared_ptr<Server> server);

    /// Returns the number of servers that have been stated and are running.
    size_t numberOfRunningServers() const;

private:
    std::vector<std::shared_ptr<Server>> m_servers;
};

}

#endif
