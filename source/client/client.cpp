#include <array>
#include <string>

#define IPADDRESS "127.0.0.1"
#define UDP_PORT 3000
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <iostream>

using boost::asio::ip::udp;

class UDPClient {
public:
    UDPClient(
        boost::asio::io_service& io_service,
        const std::string& host,
        const std::string& port)
        : io_service_(io_service)
        , socket_(io_service, udp::endpoint(udp::v4(), 0))
    {
        udp::resolver resolver(io_service_);
        udp::resolver::query query(udp::v4(), host, port);
        udp::resolver::iterator iter = resolver.resolve(query);
        endpoint_ = *iter;
    }

    ~UDPClient()
    {
        socket_.close();
    }

    void send(const std::string& msg)
    {
        socket_.send_to(boost::asio::buffer(msg, msg.size()), endpoint_);
    }

private:
    boost::asio::io_service& io_service_;
    udp::socket socket_;
    udp::endpoint endpoint_;
};

int main(int argc, char** argv)
{
    boost::asio::io_service io_service;
    UDPClient client(io_service, "localhost", "1337");

    client.send("Hello, World!");
}