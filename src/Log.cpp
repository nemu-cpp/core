/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "Log.h"

using namespace Ishiko;

namespace Nemu
{

Log::Log(LoggingSink& sink)
    : m_logger(sink)
{
    // TODO: need to support the following logging format
    // out.append(message.timestamp({"%Y-%m-%dT%H:%M:%S.%f6"}) + " (" + message.threadID() + ") [" + message.file() + ":"
     //   + message.line() + "] " + message.level() + " ");
}

void Log::onApplicationStarting(const Application& source)
{
    m_logger.info("Application starting");
}

void Log::onApplicationStarted(const Application& source)
{
    size_t running = source.servers().numberOfRunningServers();
    m_logger.info("Application started ({} server{} running", running, ((running != 1) ? "s" : ""));
}

void Log::onApplicationStopping(const Application& source)
{
    m_logger.info("Application stopping");
}

void Log::onApplicationStopped(const Application& source)
{
    size_t running = source.servers().numberOfRunningServers();
    m_logger.info("Application stopped ({} server{} running", running, ((running != 1) ? "s" : ""));
}

void Log::onServerStarted(const Server& source)
{
    m_logger.info("Server started");
}

void Log::onServerStopped(const Server& source)
{
    m_logger.info("Server stopped");
}

void Log::onConnectionOpened(const Server& source, const std::string& sourceAddress)
{
    m_logger.info("Connection from {} opened", sourceAddress);
}

void Log::onConnectionClosed(const Server& source, const std::string& sourceAddress)
{
    m_logger.info("Connection from {} closed", sourceAddress);
}

}
