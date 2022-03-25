/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "ConfigurationTests.h"
#include "FileSystemWebRequestHandlerTests.hpp"
#include "FunctionWebRequestHandlerTests.hpp"
#include "HardcodedWebRequestHandlerTests.hpp"
#include "RouteTests.h"
#include "RoutesTests.h"
#include "Nemu/Core/linkoptions.hpp"
#include <Ishiko/Tests.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("NemuCore");

    theTestHarness.context().setTestOutputDirectory("../../output");
    theTestHarness.context().setReferenceDataDirectory("../../reference");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<ConfigurationTests>();
    theTests.append<RouteTests>();
    theTests.append<RoutesTests>();
    theTests.append<HardcodedWebRequestHandlerTests>();
    theTests.append<FunctionWebRequestHandlerTests>();
    theTests.append<FileSystemWebRequestHandlerTests>();

    return theTestHarness.run();
}
