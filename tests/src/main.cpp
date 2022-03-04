/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "ConfigurationTests.h"
#include "RouteTests.h"
#include "RoutesTests.h"
#include "Nemu/Core/linkoptions.hpp"
#include <Ishiko/Tests.hpp>
#include <boost/filesystem/operations.hpp>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("NemuCore");

    theTestHarness.context().setTestOutputDirectory("../../TestOutput");
    boost::filesystem::create_directories("../../TestOutput");
    theTestHarness.context().setReferenceDataDirectory("../../ReferenceData");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<ConfigurationTests>();
    theTests.append<RouteTests>();
    theTests.append<RoutesTests>();

    return theTestHarness.run();
}
