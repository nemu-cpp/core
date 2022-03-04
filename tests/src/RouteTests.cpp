/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "RouteTests.h"
#include "Nemu/Core/Route.h"

using namespace Ishiko::Tests;

RouteTests::RouteTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Route tests", context)
{
    append<HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
}

void RouteTests::CreationTest1(Test& test)
{
    Nemu::Route route("/",
        [](const Nemu::WebRequest& request, Nemu::WebResponseBuilder& response, void* handlerData)
        {
        });

    ISHIKO_PASS();
}
