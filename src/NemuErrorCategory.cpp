/*
    Copyright (c) 2021-2022 Xavier Leclercq
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


std::ostream& NemuErrorCategory::streamOut(int value, std::ostream& os) const
{
    switch (static_cast<Value>(value))
    {
    case Value::generic_error:
        os << "generic error";
        break;

    default:
        os << "unknown value";
        break;
    }
    return os;
}

void Fail(Ishiko::Error& error, NemuErrorCategory::Value value, const std::string& message, const char* file,
    int line) noexcept
{
    error.fail(NemuErrorCategory::Get(), static_cast<int>(value), message, file, line);
}

}
