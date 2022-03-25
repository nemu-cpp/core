/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "RouteTests.h"
#include "Nemu/Core/Route.h"

using namespace Ishiko;
using namespace Nemu;

RouteTests::RouteTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Route tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<HeapAllocationErrorsTest>("Constructor test 2", ConstructorTest2);
}

void RouteTests::ConstructorTest1(Test& test)
{
    Route route("/",
        WebRequestHandler(
            [](const WebRequest& request, WebResponseBuilder& response, void* handlerData, Logger& logger)
            {
            }));

    ISHIKO_TEST_PASS();
}

void RouteTests::ConstructorTest2(Test& test)
{
    int data = 0;
    Route route("/",
        WebRequestHandler(
            [data](const WebRequest& request, WebResponseBuilder& response, void* handlerData, Logger& logger)
            {
            }));

    ISHIKO_TEST_PASS();
}
