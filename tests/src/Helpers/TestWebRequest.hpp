/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_TESTS_HELPERS_TESTWEBREQUEST_HPP_
#define _NEMU_CPP_CORE_TESTS_HELPERS_TESTWEBREQUEST_HPP_

#include "Nemu/Core/WebRequest.hpp"
#include <string>

class TestWebRequest : public Nemu::WebRequest
{
public:
    TestWebRequest(std::string uri);

    std::string URI() const override;

private:
    std::string m_uri;
};

#endif
