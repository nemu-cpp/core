/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "ConfigurationTests.hpp"
#include "Nemu/Core/Configuration.h"

using namespace Ishiko;

ConfigurationTests::ConfigurationTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Configuration tests", context)
{
    append<HeapAllocationErrorsTest>("Creation test 1", CreationTest1);
    append<HeapAllocationErrorsTest>("Creation test 2", CreationTest2);
    append<HeapAllocationErrorsTest>("Creation test 3", CreationTest3);
}

void ConfigurationTests::CreationTest1(Test& test)
{
    int argc = 1;
    const char* argv[] = { "NemuTests" };
    Nemu::Configuration configuration(argc, argv, TCPServerSocket::AllInterfaces, Port::http);

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.ipAddress().toString(), "0.0.0.0");
    ISHIKO_TEST_FAIL_IF_NEQ(configuration.port(), 80);
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::CreationTest2(Test& test)
{
    int argc = 1;
    const char* argv[] = { "NemuTests" };
    Nemu::Configuration configuration(argc, argv, IPv4Address::Localhost(), 8080);

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.ipAddress().toString(), "127.0.0.1");
    ISHIKO_TEST_FAIL_IF_NEQ(configuration.port(), 8080);
    ISHIKO_TEST_PASS();
}

void ConfigurationTests::CreationTest3(Test& test)
{
    Nemu::Configuration configuration(TCPServerSocket::AllInterfaces, Port::http);

    ISHIKO_TEST_FAIL_IF_NEQ(configuration.ipAddress().toString(), "0.0.0.0");
    ISHIKO_TEST_FAIL_IF_NEQ(configuration.port(), 80);
    ISHIKO_TEST_PASS();
}
