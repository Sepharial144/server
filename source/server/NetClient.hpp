#ifndef _NET_CLIENT_STORAGE_HPP_
#define _NET_CLIENT_STORAGE_HPP_

#include "IfcClient.hpp"
#include "QueuedClient.hpp"

class IStorage;
class SharedMemory;

#include <functional>
#include <iostream>
#include <thread>

using StoragePtr = IStorage*;

class NetClient : public IClient, public QueuedClient<std::string> {
public:
    explicit NetClient();
    explicit NetClient(const std::string& label, const StoragePtr p_storage);
    virtual ~NetClient();

    // NetClient& operator=(const NetClient &other);
    NetClient(NetClient&& other);

    void mainLoop();
    void start() override;
    void stop() override;
    void sendMessage(std::shared_ptr<IBuffer> ptrMemory) override;
    void incomingConnection(IConnection& connection, Response& req) override;
    void publish(std::string element) override; // TODO: fix this publish function

private:
    struct Recipient {
        void send(const void* data) { std::cout << data << &std::endl; }
    };

private:
    Recipient m_netStream {};
    StoragePtr m_pStorage;
    std::string m_netClientName;
    bool m_loopIsStarted = false;
    std::thread m_thread;
};

#endif // !_NET_CLIENT_STORAGE_HPP_