/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_TESTS_ROUTESTESTS_H_
#define _NEMU_CPP_CORE_TESTS_ROUTESTESTS_H_

#include <Ishiko/Tests.hpp>

class RoutesTests : public Ishiko::Tests::TestSequence
{
public:
    RoutesTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestContext& context);

private:
    static void CreationTest1(Ishiko::Tests::Test& test);
    static void MatchTest1(Ishiko::Tests::Test& test);
};

#endif
