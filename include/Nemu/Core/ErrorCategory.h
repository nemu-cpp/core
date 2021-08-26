/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_ERRORCATEGORY_H_
#define _NEMU_CPP_CORE_ERRORCATEGORY_H_

#include <Ishiko/Errors.h>

namespace Nemu
{

class ErrorCategory : public Ishiko::ErrorCategory
{
public:
    enum EErrorValues
    {
        eGeneric = -1
    };

    static const ErrorCategory& Get() noexcept;

    const char* name() const noexcept override;

private:
    ErrorCategory() noexcept = default;
};

void Fail(Ishiko::Error& error, ErrorCategory::EErrorValues value, const std::string& message, const char* file,
    int line) noexcept;

}

#endif
