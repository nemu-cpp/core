/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_TESTS_HELPERS_TESTWEBRESPONSEBUILDER_HPP_
#define _NEMU_CPP_CORE_TESTS_HELPERS_TESTWEBRESPONSEBUILDER_HPP_

#include "Nemu/Core/WebResponseBuilder.hpp"
#include <Ishiko/Time.hpp>
#include <ostream>
#include <string>

class TestWebResponseBuilder : public Nemu::WebResponseBuilder
{
public:
    TestWebResponseBuilder();

    void setStatus(unsigned int status) override;
    void setDateHeader(const Ishiko::UTCTime& time) override;
    std::string& body() override;

    unsigned int statusCode() const;

    void save(std::ostream& stream) const;

private:
    unsigned int m_statusCode;
    std::string m_body;
};

#endif
