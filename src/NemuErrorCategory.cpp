/*
    Copyright (c) 2021-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "NemuErrorCategory.hpp"

namespace Nemu
{
   
const NemuErrorCategory& NemuErrorCategory::Get() noexcept
{
    static NemuErrorCategory theCategory;
    return theCategory;
}

const char* NemuErrorCategory::name() const noexcept
{
    return "NemuErrorCategory";
}


const char* NemuErrorCategory::message(int ev, char* buffer, size_t len) const noexcept
{
    switch (static_cast<Value>(ev))
    {
    case Value::generic_error:
        return "generic error";

    default:
        return "unknown value";
    }
}

void Fail(Ishiko::Error& error, NemuErrorCategory::Value value, const std::string& message, const char* file,
    int line) noexcept
{
    error.fail(NemuErrorCategory::Get(), static_cast<int>(value), message, file, line);
}

}
