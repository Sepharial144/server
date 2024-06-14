#include "logger/logger.hpp"

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

#include <iostream>
#include <thread>

#include "server/IfcStorage.hpp"
#include "server/NetClient.hpp"
#include "server/Server.hpp"
#include "server/ServerManager.hpp"
#include "server/Storage.hpp"

#define IPADDRESS "127.0.0.1"
#define UDP_PORT 3000

using boost::asio::ip::udp;

//https://gist.github.com/amidvidy/b4883a84a7ac17f0d37a

// the multy client udp example here 
https://www.cs.cmu.edu/afs/cs/academic/class/15213-f99/www/class26/udpserver.c

class udp_server {
public:
    udp_server(boost::asio::io_service& io_service)
        : m_socket(io_service, udp::endpoint(udp::v4(), 3000))
    {
        startReceive();
    }

private:
    void startReceive()
    {

        m_socket.async_receive_from(boost::asio::buffer(m_requestBuffer),
                                    m_remoteEndpoint,
                                    boost::bind(&udp_server::handleReceive, 
                                    this,
                                    boost::asio::placeholders::error,
                                    boost::asio::placeholders::bytes_transferred));
    }

    void handleReceive(const boost::system::error_code& error, size_t bytes_transferred)
    {
        if (!error || error == boost::asio::error::message_size) {
            // need to read the actual message from requw
            std::shared_ptr<std::string> message("Test message"); // we got the message, so we need to return back the right message

            m_socket.async_send_to(boost::asio::buffer(*message),
                m_remoteEndpoint,
                boost::bind(&udp_server::handleSend, this, message,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred));

            startReceive();
        }
    }

    void handleSend(std::shared_ptr<std::string> message, const boost::system::error_code& error, size_t bytes_transferred) 
    {
        startReceive();
    }

private:
    udp::socket m_socket;
    udp::endpoint m_remoteEndpoint;
    boost::array<char, 1024> m_requestBuffer;
};

int main(int argc, char** argv)
{

    boost::asio::io_service io_service;
    udp_server server(io_service);
    io_service.run();

    /*
      logger::info("Server running {}", "...");
      boost::asio::io_service io_service;
      boost::asio::ip::udp::socket socket(io_service);
      boost::asio::ip::udp::endpoint remote_endpoint =
          boost::asio::ip::udp::endpoint(
              boost::asio::ip::address::from_string(IPADDRESS), UDP_PORT);
      socket.open(boost::asio::ip::udp::v4());

      boost::system::error_code err;
      auto sent = socket.send_to(boost::asio::buffer(in), remote_endpoint, 0,
      err); socket.close(); std::cout << "Sent Payload --- " << sent << "\n";

    */

    /*
    std::unique_ptr<IStorage> ptrStorage = std::make_unique<Storage>();
    auto message = ptrStorage->getMessage(5u);
    std::cout << (const char*)message->data() << std::endl;
    */

    /*
      NetClient client{"First client", nullptr};
      client.start();
      client.publish(42u);
      client.publish(41u);
      client.publish(40u);
      client.publish(39u);
      client.publish(38u);
      std::this_thread::sleep_for(std::chrono::microseconds(10000));
      client.stop();
      */
    /*
    ServerManager manager;
    manager.readConfiguration();
    */
    // Server server{};
    // server.listening(IPADDRESS, UDP_PORT);

    /*
      logger::fatal("Fatal {}", "...");
      logger::error("Error {}", " ...");
      logger::warning("Warning {}", " ...");
      logger::info("Info {}", " ...");
      logger::debug("Debug {}", " ...");
      logger::debug_low("Debug low {}", " ...");
      logger::debug_medium("Debug medium {}", " ...");
      logger::debug_high("Debug high {}", " ...");
      */
    return EXIT_SUCCESS;
}

/*
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <thread>

#define IPADDRESS "127.0.0.1"
#define UDP_PORT 3000

using boost::asio::ip::udp;
using boost::asio::ip::address;

void Sender(std::string in) {
    boost::asio::io_service io_service;
    udp::socket socket(io_service);
    udp::endpoint remote_endpoint =
udp::endpoint(address::from_string(IPADDRESS), UDP_PORT);
    socket.open(udp::v4());

    boost::system::error_code err;
    auto sent = socket.send_to(boost::asio::buffer(in), remote_endpoint, 0,
err); socket.close(); std::cout << "Sent Payload --- " << sent << "\n";
}

struct Client {
    boost::asio::io_service io_service;
    udp::socket socket{io_service};
    boost::array<char, 1024> recv_buffer;
    udp::endpoint remote_endpoint;

    int count = 3;

    void handle_receive(const boost::system::error_code& error, size_t
bytes_transferred) { if (error) { std::cout << "Receive failed: " <<
error.message() << "\n"; return;
        }
        std::cout << "Received: '" << std::string(recv_buffer.begin(),
recv_buffer.begin()+bytes_transferred) << "' (" << error.message() << ")\n";

        if (--count > 0) {
            std::cout << "Count: " << count << "\n";
            wait();
        }
    }

    void wait() {
        socket.async_receive_from(boost::asio::buffer(recv_buffer),
            remote_endpoint,
            boost::bind(&Client::handle_receive, this,
boost::asio::placeholders::error,
boost::asio::placeholders::bytes_transferred));
    }

    void Receiver()
    {
        socket.open(udp::v4());
        socket.bind(udp::endpoint(address::from_string(IPADDRESS), UDP_PORT));

        wait();

        std::cout << "Receiving\n";
        io_service.run();
        std::cout << "Receiver exit\n";
    }
};

int main(int argc, char *argv[])
{
    Client client;
    std::thread r([&] { client.Receiver(); });

    std::string input = argc>1? argv[1] : "hello world";
    std::cout << "Input is '" << input.c_str() << "'\nSending it to Sender
Function...\n";

    for (int i = 0; i < 3; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        Sender(input);
    }

    r.join();
}
*/