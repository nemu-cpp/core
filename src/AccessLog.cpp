/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "AccessLog.h"
#include <boost/date_time/posix_time/posix_time.hpp>

namespace Nemu
{

void AccessLog::log(const std::string& address, const std::string& requestLine, unsigned int statusCode, size_t size)
{
    boost::posix_time::ptime currentTime = boost::posix_time::second_clock::universal_time();
    const auto& date = currentTime.date();
    const auto& time = currentTime.time_of_day();

    // TODO
    /*LOG(INFO) << address << " - - [" << date.day() << "/" << date.month().as_short_string() << "/" << date.year()
        << ":" << time.hours() << ":" << time.minutes() << ":" << time.seconds() << " " << currentTime.zone_name(true)
        << "] \"" << requestLine << "\" " << statusCode << " " << size;*/
}

}
