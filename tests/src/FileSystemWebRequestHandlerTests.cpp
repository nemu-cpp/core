/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "FileSystemWebRequestHandlerTests.hpp"

using namespace Ishiko;

FileSystemWebRequestHandlerTests::FileSystemWebRequestHandlerTests(const TestNumber& number,
    const TestContext& context)
    : TestSequence(number, "FileSystemWebRequestHandler tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
}

void FileSystemWebRequestHandlerTests::ConstructorTest1(Test& test)
{
}
