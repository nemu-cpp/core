/*
    Copyright (c) 2021-2024 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef GUARD_NEMU_CPP_CORE_NEMUERRORCATEGORY_HPP
#define GUARD_NEMU_CPP_CORE_NEMUERRORCATEGORY_HPP

#include <Ishiko/Errors.hpp>

namespace Nemu
{

class NemuErrorCategory : public Ishiko::ErrorCategory
{
public:
    enum class Value
    {
        generic_error = -1
    };

    static const NemuErrorCategory& Get() noexcept;

    const char* name() const noexcept override;
    const char* message(int ev, char* buffer, size_t len) const noexcept override;

private:
    NemuErrorCategory() noexcept = default;
};

void Fail(Ishiko::Error& error, NemuErrorCategory::Value value, const std::string& message, const char* file,
    int line) noexcept;

}

#endif
