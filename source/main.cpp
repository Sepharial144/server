#include "logger/logger.hpp"

#include <boost/asio.hpp>
#include <iostream>
#include <thread>

#include "IfcStorage.hpp"
#include "Storage.hpp"

#define IPADDRESS "127.0.0.1"
#define UDP_PORT 3000

int main(int argc, char **argv) {

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

  std::unique_ptr<IStorage> ptrStorage = std::make_unique<Storage>();
  auto message = ptrStorage->getMessage();
  std::cout << message->data() << std::endl;

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