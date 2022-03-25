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

void Fail(Ishiko::Error& error, NemuErrorCategory::EErrorValues value, const std::string& message, const char* file,
    int line) noexcept
{
    error.fail(value, NemuErrorCategory::Get(), message, file, line);
}

}
