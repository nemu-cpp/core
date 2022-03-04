/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_LOGGINGMACROS_HPP_
#define _NEMU_CPP_CORE_LOGGINGMACROS_HPP_

// TODO: this should be set as a compile option
#define NEMU_LOG_MIN_DYNAMIC_LEVEL Ishiko::Logger::Level::info

#define NEMU_LOG_INFO(...)                                         \
    if (NEMU_LOG_MIN_DYNAMIC_LEVEL >= Ishiko::Logger::Level::info) \
    {                                                              \
        logger.info(__VA_ARGS__);                                  \
    }

#endif
