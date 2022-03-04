/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_APPLICATIONS_H_
#define _NEMU_CPP_CORE_APPLICATIONS_H_

#include "Application.h"
#include <set>
#include <mutex>

namespace Nemu
{

/// The list of applications in the program.
/**
    This class behaves as a singleton that stores the list of Application instances in the program. The constructors
    and destructor of the Application class automatically add and remove instances to this class.
    
    On Windows, it is used by the Ctrl-C handler to stop all applications when a Ctrl-C event is received. But it can
    be used for other purposes if needed.
*/
class Applications
{
public:
    /// Stops all applications in the list.
    static void StopAllApplications();

    /// Adds an application to the list.
    /**
        This function is automatically called by the Application constructors so there should be no need to call it
        directly.
        @param application The application to add to the list.
    */
    static void set(Application* application);
    // Removes an application from the list.
    /**
        This function is automatically called by the Application destructor so there should be no need to call it
        directly.
        @param application The application to remove from the list.
    */
    static void unset(Application* application);

private:
    static std::mutex sm_applicationsMutex;
    static std::set<Application*> sm_applications;
};

}

#endif
