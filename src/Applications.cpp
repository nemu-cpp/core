/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "Applications.hpp"

namespace Nemu
{

std::mutex Applications::sm_applicationsMutex;
std::set<Application*> Applications::sm_applications;

void Applications::StopAllApplications()
{
    std::lock_guard<std::mutex> guard(sm_applicationsMutex);
    for (Application* app : sm_applications)
    {
        app->stop();
    }
}

void Applications::set(Application* application)
{
    std::lock_guard<std::mutex> guard(sm_applicationsMutex);
    sm_applications.insert(application);
}

void Applications::unset(Application* application)
{
    std::lock_guard<std::mutex> guard(sm_applicationsMutex);
    sm_applications.erase(application);
}

}
