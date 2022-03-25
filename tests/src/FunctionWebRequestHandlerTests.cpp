/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "FunctionWebRequestHandlerTests.hpp"
#include "Nemu/Core/Web/RequestHandlers/FunctionWebRequestHandler.hpp"

using namespace Ishiko;
using namespace Nemu;

FunctionWebRequestHandlerTests::FunctionWebRequestHandlerTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "FunctionWebRequestHandler tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void FunctionWebRequestHandlerTests::ConstructorTest1(Test& test)
{
    int data = 0;
    FunctionWebRequestHandler requestHandler(
        [data](const WebRequest& request, WebResponseBuilder& response, void* handlerData, Logger& logger)
        {
        });

    ISHIKO_TEST_PASS();
}
