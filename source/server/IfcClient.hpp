#ifndef _CLIENT_INTERFACE_HPP_
#define _CLIENT_INTERFACE_HPP_

#include "IfcConnection.hpp"
#include "Response.hpp"
#include "buffer/IfcBuffer.hpp"

#include <functional>
#include <memory>
#include <string>

class IClient {
public:
    explicit IClient() {};
    virtual ~IClient() {};

    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void sendMessage(std::shared_ptr<IBuffer> ptrMemory) = 0;
    virtual void incomingConnection(IConnection& connection, Response& req) = 0;
    virtual void publish(std::string element) = 0;
};

#endif // !_CLIENT_INTERFACE_HPP_