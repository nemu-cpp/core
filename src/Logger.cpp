/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "Logger.hpp"

using namespace Ishiko;

namespace Nemu
{

Logger::Logger(LoggingSink& sink)
    : m_logger(sink)
{
    // TODO: need to support the following logging format
    // out.append(message.timestamp({"%Y-%m-%dT%H:%M:%S.%f6"}) + " (" + message.threadID() + ") [" + message.file() + ":"
     //   + message.line() + "] " + message.level() + " ");
}

}
