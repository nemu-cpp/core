/*
    Copyright (c) 2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "TestWebResponseBuilder.hpp"

using namespace Ishiko;
using namespace Nemu;
using namespace std;

TestWebResponseBuilder::TestWebResponseBuilder(const Views& views)
    : WebResponseBuilder(views), m_statusCode(0)
{
}

void TestWebResponseBuilder::setStatus(unsigned int status)
{
    m_statusCode = status;
}

void TestWebResponseBuilder::setDateHeader(const UTCTime& time)
{
}

string& TestWebResponseBuilder::body()
{
    return m_body;
}

unsigned int TestWebResponseBuilder::statusCode() const
{
    return m_statusCode;
}

void TestWebResponseBuilder::save(ostream& stream) const
{
    stream << "Status Code: " << m_statusCode << "\r\n";
    stream << "Body:\r\n" << m_body;
}
