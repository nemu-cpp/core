/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_APPLICATION_H_
#define _NEMU_CPP_CORE_APPLICATION_H_

#include "Servers.hpp"
#include <Ishiko/Logging.hpp>

namespace Nemu
{

#ifdef _WIN32
class ControlHandlerRegistration;
#endif

/// Base class for all types of applications.
class Application
{
public:
    /// The interface that needs to be implemented by the observers of the Application class.
    /**
        Application observers also implement the Server::Observer interface to observe the servers that are part of the
        application.
    */
    class Observer : public Server::Observer
    {
    public:
        /// Called before an application is about to start.
        virtual void onApplicationStarting(const Application& source);
        /// Called when an application has been started.
        virtual void onApplicationStarted(const Application& source);
        /// Called when an application is about to be stopped.
        virtual void onApplicationStopping(const Application& source);
        /// Called when an application has stopped.
        virtual void onApplicationStopped(const Application& source);
    };

    /// A list of observers.
    /**
        A std::weak_ptr is used to refer to the observers. A count is also used so that adding and removing the same
        observer multiple times behaves correctly.
    */
    class Observers final
    {
    public:
        /// Adds an observer to the list.
        /**
            A std::weak_ptr to the argument will be added to the list of observers if the observer was not already
            present.
            @param observer The observer to add.
        */
        void add(std::shared_ptr<Observer> observer);
        /// Removes an observer from the list.
        /**
            If the observer was added multiple times it will only be removed when remove has been called as many times
            as the observer was added.
            @param observer The observer to remove.
        */
        void remove(std::shared_ptr<Observer> observer);

        /// Notifies all the observers of an event.
        /**
            If an observer was added multiple times, it will only be notified once.
            @param fct The member function to call on each observer.
            @param source The application the event originated from.
        */
        void notify(void (Observer::*fct)(const Application& source), const Application& source);

    private:
        void removeDeletedObservers();

    private:
        std::vector<std::pair<std::weak_ptr<Observer>, size_t>> m_observers;
    };

    /// Constructor.
    /**
        This constructor creates a new instance of the Application class and adds the observer passed in to the list of
        observers.
        @param observer An observer.
    */
    Application(Ishiko::Logger& logger);
    /// Destructor.
    virtual ~Application();

    /// Starts the application and blocks until the application is stopped.
    /**
        The function will start the servers needed by the application.

        On Windows it will also register a control handler for the Control-C event which will stop all applications
        when triggered. Once the applications are stopped the control handler is unregistered.
    */
    void run();
    /// Stops the application.
    /**
        If the start function was blocking it will return after this function is called. The function will stop all
        servers.

        On Windows it will also unregister the control handler for the Control-C event unless other applications are
        still running.
    */
    void stop();

    /// Returns the list of servers that are part of the application.
    const Servers& servers() const;
    /// Returns the list of observers.
    Observers& observers();

protected:
    /// Returns the list of servers.
    /**
        This function can be used by derived classes to add servers to the application.
    */
    Servers& servers();

private:
#ifdef _WIN32
    std::unique_ptr<ControlHandlerRegistration> m_controlHandlerRegistration;
#endif
protected:
    Ishiko::Logger& m_logger; // TODO: avoid protected
private:
    Servers m_servers;
    Observers m_observers;
};

}

#endif
