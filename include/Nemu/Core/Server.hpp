/*
    Copyright (c) 2019-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/nemu-cpp/core/blob/main/LICENSE.txt
*/

#ifndef _NEMU_CPP_CORE_SERVER_HPP_
#define _NEMU_CPP_CORE_SERVER_HPP_

#include <vector>
#include <string>
#include <memory>

namespace Nemu
{

/// Base class for the servers that are part of an Application.
class Server
{
public:
    /// The interface that needs to be implemented by the observers of the Server class.
    class Observer
    {
    public:
        /// Called when a server has been started.
        virtual void onServerStarted(const Server& source);
        /// Called when a server has stopped.
        virtual void onServerStopped(const Server& source);
        /// Called when a new connection has been established.
        /**
            @param source The server the event originated from.
            @param sourceAddress The address of the remote server that initiated the connection.
        */
        virtual void onConnectionOpened(const Server& source, const std::string& sourceAddress);
        /// Called when a connection has been closed.
        /**
            @param source The server the event originated from.
            @param sourceAddress The address of the remote server.
        */
        virtual void onConnectionClosed(const Server& source, const std::string& sourceAddress);
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
            @param source The server the event originated from.
        */
        void notify(void (Observer::*fct)(const Server& source), const Server& source);
        /// Notifies all the observers of an event.
        /**
            If an observer was added multiple times, it will only be notified once.
            @param fct The member function to call on each observer.
            @param source The server the event originated from.
            @param sourceAddress The address of the remote server.
        */
        void notify(void (Observer::*fct)(const Server& source, const std::string& sourceAddress),
            const Server& source, const std::string& sourceAddress);

    private:
        void removeDeletedObservers();

    private:
        std::vector<std::pair<std::weak_ptr<Observer>, size_t>> m_observers;
    };

    /// Constructor.
    /**
        This constructor creates a new instance of the Server class and adds the observer passed in to the list of
        observers.
        @param observer An observer.
    */
    Server() = default;
    Server(std::shared_ptr<Observer> observer);
    /// Destructor.
    virtual ~Server() = default;

    /// Starts the server.
    /**
        Unlike the Application::start function, this function doesn't block and returns immediately. Use the
        Server::join function to wait for server stop.
    */
    virtual void start() = 0;
    /// Stop the server.
    virtual void stop() = 0;
    /// Wait until the server has stopped.
    virtual void join() = 0;

    /// Checks whether the server has been started.
    virtual bool isRunning() const = 0;

    /// Returns the list of observers.
    Observers& observers();

private:
    Observers m_observers;
};

}

#endif
