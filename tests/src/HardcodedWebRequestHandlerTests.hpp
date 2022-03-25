/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_TESTS_HARDCODEDWEBREQUESTHANDLERTESTS_HPP_
#define _NEMU_CPP_CORE_TESTS_HARDCODEDWEBREQUESTHANDLERTESTS_HPP_

#include <Ishiko/Tests.hpp>

class HardcodedWebRequestHandlerTests : public Ishiko::TestSequence
{
public:
    HardcodedWebRequestHandlerTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void ConstructorTest1(Ishiko::Test& test);
    static void RunTest1(Ishiko::Test& test);
};

#endif