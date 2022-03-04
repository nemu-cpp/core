/*
    Copyright (c) 2019-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#include "ControlHandlerRegistration.h"

#ifdef _WIN32
#include "Applications.h"
#include <windows.h>

namespace Nemu
{

std::mutex ControlHandlerRegistration::sm_mutex;
size_t ControlHandlerRegistration::sm_count = 0;

BOOL WINAPI ControlHandler(DWORD fdwCtrlType)
{
    switch (fdwCtrlType)
    {
    case CTRL_C_EVENT:
        // TODO
        // LOG(INFO) << "Ctrl-C received, stopping all applications";
        Applications::StopAllApplications();
        return TRUE;

    default:
        return FALSE;
    }
}

ControlHandlerRegistration::ControlHandlerRegistration()
{
    std::lock_guard<std::mutex> guard(sm_mutex);
    if (sm_count++ == 0)
    {
        SetConsoleCtrlHandler(ControlHandler, TRUE);
    }
}

ControlHandlerRegistration::~ControlHandlerRegistration()
{
    std::lock_guard<std::mutex> guard(sm_mutex);
    if (--sm_count == 0)
    {
        SetConsoleCtrlHandler(ControlHandler, FALSE);
    }
}

}

#endif
