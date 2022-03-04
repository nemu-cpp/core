/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_ACCESSLOG_H_
#define _NEMU_CPP_CORE_ACCESSLOG_H_

#include <string>

namespace Nemu
{

class AccessLog
{
public:
    virtual void log(const std::string& address, const std::string& requestLine, unsigned int statusCode, size_t size);
};

}

#endif
