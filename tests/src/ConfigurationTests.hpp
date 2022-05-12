/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_TESTS_CONFIGURATIONTESTS_HPP_
#define _NEMU_CPP_CORE_TESTS_CONFIGURATIONTESTS_HPP_

#include <Ishiko/TestFramework.hpp>

class ConfigurationTests : public Ishiko::TestSequence
{
public:
    ConfigurationTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void CreationTest1(Ishiko::Test& test);
    static void CreationTest2(Ishiko::Test& test);
    static void CreationTest3(Ishiko::Test& test);
};

#endif
