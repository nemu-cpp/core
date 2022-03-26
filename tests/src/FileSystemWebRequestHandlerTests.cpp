/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "FileSystemWebRequestHandlerTests.hpp"
#include "Helpers/TestWebRequest.hpp"
#include "Helpers/TestWebResponseBuilder.hpp"
#include "Nemu/Core/Web/RequestHandlers/FileSystemWebRequestHandler.hpp"
#include <Ishiko/Logging.hpp>

using namespace boost::filesystem;
using namespace Ishiko;
using namespace Nemu;

FileSystemWebRequestHandlerTests::FileSystemWebRequestHandlerTests(const TestNumber& number,
    const TestContext& context)
    : TestSequence(number, "FileSystemWebRequestHandler tests", context)
{
    append<HeapAllocationErrorsTest>("Constructor test 1", ConstructorTest1);
    append<FileComparisonTest>("run test 1", RunTest1);
}

void FileSystemWebRequestHandlerTests::ConstructorTest1(Test& test)
{
    FileSystemWebRequestHandler requestHandler(".");

    ISHIKO_TEST_PASS();
}

void FileSystemWebRequestHandlerTests::RunTest1(FileComparisonTest& test)
{
    path inputPath(test.context().getTestDataPath("html"));

    path outputPath(test.context().getTestOutputPath("FileSystemWebRequestHandlerTests_RunTest1.bin"));
    std::ofstream stream(outputPath.c_str(), std::ios::binary);

    FileSystemWebRequestHandler requestHandler(inputPath.string().c_str());

    TestWebRequest request("/");
    Views views;
    TestWebResponseBuilder responseBuilder(views);
    NullLoggingSink sink;
    Logger log(sink);

    requestHandler.run(request, responseBuilder, log);

    responseBuilder.save(stream);

    test.setOutputFilePath(outputPath);
    test.setReferenceFilePath(test.context().getReferenceDataPath("FileSystemWebRequestHandlerTests_RunTest1.bin"));

    ISHIKO_TEST_PASS();
}
