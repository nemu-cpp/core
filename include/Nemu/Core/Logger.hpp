/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_LOGGER_HPP_
#define _NEMU_CPP_CORE_LOGGER_HPP_

#include <Ishiko/Logging.hpp>
#include <string>

namespace Nemu
{

/// A log.
/**
    This is a wrapper around Ishiko/Logging.
*/
class Logger
{
public:
    /// Constructor.
    Logger(Ishiko::LoggingSink& sink);

    template <typename... Args>
    void info(const std::string& message, Args&&... args);

private:
    Ishiko::Logger m_logger;
};

template <typename... Args>
void Logger::info(const std::string& message, Args&&... args)
{
    m_logger.info(message, std::forward<Args>(args)...);
}

}

#endif
