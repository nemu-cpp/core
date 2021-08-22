/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "ErrorCategory.h"

namespace Nemu
{
   
const ErrorCategory& ErrorCategory::Get() noexcept
{
    static ErrorCategory theCategory;
    return theCategory;
}

const char* ErrorCategory::name() const noexcept
{
    return "Nemu::ErrorCategory";
}

void Fail(Ishiko::Error& error, ErrorCategory::EErrorValues value, const std::string& message, const char* file,
    int line) noexcept
{
    error.fail(value, ErrorCategory::Get(), message, file, line);
}

}
