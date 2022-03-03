/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "RoutesTests.h"
#include "Nemu/Core/Routes.h"

using namespace Ishiko::Tests;

RoutesTests::RoutesTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Routes tests", context)
{
    append<HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
    append<HeapAllocationErrorsTest>("match test 1", MatchTest1);
}

void RoutesTests::CreationTest1(Test& test)
{
    Nemu::Routes routes;

    ISHIKO_PASS();
}

void RoutesTests::MatchTest1(Test& test)
{
    Nemu::Routes routes;
    const Nemu::Route& matchedRoute = routes.match("/");

    ISHIKO_FAIL_IF_NEQ(&matchedRoute, &routes.defaultRoute());
    ISHIKO_PASS();
}
