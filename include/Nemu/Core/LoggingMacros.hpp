/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_LOGGINGMACROS_HPP_
#define _NEMU_CPP_CORE_LOGGINGMACROS_HPP_

#include "compileoptions.hpp"
#include <Ishiko/Logging.hpp>

#define NEMU_LOG_ERROR(...) ISHIKO_LOG_ERROR(NEMU_MAX_LOG_LEVEL, __VA_ARGS__)
#define NEMU_LOG_WARNING(...) ISHIKO_LOG_WARNING(NEMU_MAX_LOG_LEVEL, __VA_ARGS__)     
#define NEMU_LOG_INFO(...) ISHIKO_LOG_INFO(NEMU_MAX_LOG_LEVEL, __VA_ARGS__)  
#define NEMU_LOG_TRACE(...) ISHIKO_LOG_TRACE(NEMU_MAX_LOG_LEVEL, __VA_ARGS__)     

#endif
