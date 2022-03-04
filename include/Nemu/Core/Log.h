/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_LOG_H_
#define _NEMU_CPP_CORE_LOG_H_

#include "Application.h"
#include <Ishiko/Logging.hpp>
#include <string>

namespace Nemu
{

/// A log.
/**
    This is a wrapper around Ishiko/Logging.
*/
class Log : public Application::Observer
{
public:
    /// Constructor.
    /**
        @param filenamePrefix The prefix of the log file name. For instance this can be the name of the application.
    */
    Log(Ishiko::LoggingSink& sink);

    void onApplicationStarting(const Application& source) override;
    void onApplicationStarted(const Application& source) override;
    void onApplicationStopping(const Application& source) override;
    void onApplicationStopped(const Application& source) override;
    void onServerStarted(const Server& source) override;
    void onServerStopped(const Server& source) override;
    void onConnectionOpened(const Server& source, const std::string& sourceAddress) override;
    void onConnectionClosed(const Server& source, const std::string& sourceAddress) override;

private:
    Ishiko::Logger m_logger;
};

}

#endif
