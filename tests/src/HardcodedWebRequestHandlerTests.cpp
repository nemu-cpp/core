/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "HardcodedWebRequestHandlerTests.hpp"
#include "Helpers/TestWebRequest.hpp"
#include "Helpers/TestWebResponseBuilder.hpp"
#include "Nemu/Core/Web/RequestHandlers/HardcodedWebRequestHandler.hpp"
#include <iostream>

using namespace boost::filesystem;
using namespace Ishiko;
using namespace Nemu;
using namespace std;

HardcodedWebRequestHandlerTests::HardcodedWebRequestHandlerTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "HardcodedWebRequestHandler tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<Test>("run test 1", RunTest1);
}

void HardcodedWebRequestHandlerTests::ConstructorTest1(Test& test)
{
    HardcodedWebRequestHandler requestHandler(200, "");

    ISHIKO_TEST_PASS();
}

void HardcodedWebRequestHandlerTests::RunTest1(Test& test)
{
    HardcodedWebRequestHandler requestHandler(200, "body");

    TestWebRequest request;
    Views views;
    TestWebResponseBuilder responseBuilder(views);

    // TODO: null log
    StreamLoggingSink sink(cout);
    Logger log(sink);

    requestHandler.run(request, responseBuilder, log);
    
    ISHIKO_TEST_FAIL_IF_NEQ(responseBuilder.statusCode(), 200);
    ISHIKO_TEST_FAIL_IF_NEQ(responseBuilder.body(), "body");
    ISHIKO_TEST_PASS();
}
