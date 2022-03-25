/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "HardcodedWebRequestHandlerTests.hpp"

using namespace Ishiko;

HardcodedWebRequestHandlerTests::HardcodedWebRequestHandlerTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "HardcodedWebRequestHandler tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void HardcodedWebRequestHandlerTests::ConstructorTest1(Test& test)
{
}
