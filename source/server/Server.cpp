#include "Server.hpp"
#include "netxx/netxx.hpp"

#include <array>
#include <iostream>
#include <string>

Server::Server() { }

Server::~Server() { }

void Server::listening(const char* address, uint64_t port)
{

    /*
    net::settings::server_t settings{
        net::settings::aifamily::inetv4, net::settings::aisocktype::dgram,
        net::settings::aiprotocol::udp, net::settings::aiflags::passive, 10ul};

    try {
      net::socket_t udp_server = net::make_server(settings, address, port,
                                                  net::socket::type::nonblocking);
      std::array<char, 1024ul> request = {0};

      std::string message{"Asynchronous socket!"};
      net::pollfd_s serverSocketArray[1];
      net::pollfd_s fdArray[10];

      int32_t countClientFd = 0;
      int32_t currentSocketFd = 0;
      int32_t nfds = 0;
      bool serverIsRun = true;

      std::cout << "Poll call ..." << &std::endl;

      serverSocketArray[0].fd = udp_server;
      serverSocketArray[0].events = POLLIN;
      constexpr uint64_t timeout = 3 * 60 * 100; // wait 3 minute
      // int32_t ret = ::poll((pollfd*)&fdArray, numFds, timeout);
      int32_t ret = ::poll(serverSocketArray, 1, timeout);
      if (ret == 0) {
        std::cout << "Poll call ... timeout: " << ret << " errno: " << errno
                  << &std::endl;
        return;
      }
      if (ret == net::status::error) {
        std::cout << "Poll call ... error: " << ret << " errno: " << errno
                  << &std::endl;
        return;
      }

      std::cout << "Poll call ... complete" << &std::endl;

      std::cout << "Check server events ..." << std::endl;
      int32_t retEvents = serverSocketArray[0].revents;

      if (retEvents == 0)
        std::cout << "Check server events ... good" << std::endl;

      if (retEvents != POLLIN) {
        // error revent retEvents
        std::cout << "Check server events ... revent error: " << retEvents
                  << std::endl;
        serverIsRun = false;
        return;
      }
      std::cout << "Check server events ... complete" << std::endl;

      bool isServerRunning = true;
      while (isServerRunning) {
        std::cout << "Cycle" << std::endl;
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        ret = net::read(serverSocketArray[0].fd, request.data(), request.size());
        if (ret < 0) {
          if (errno != NET_SOCKET_WOULD_BLOCK) {
            std::cout << "Read message ... error: " << ret << " errno: " << errno
                      << &std::endl;
            net::free(serverSocketArray[0].fd);
          }
          break;
        }

        if (ret == net::status::disconnected) {
          std::cout << "Read message ... disconnected: " << ret
                    << "errno: " << errno << &std::endl;
          net::free(serverSocketArray[0].fd);
          break;
        }

        if (ret > 0) {
          std::cout << "Read message ... complete, ret status: " << ret << " "
                    << request.data() << " len: " << ret << std::endl;
          break;
        }
      }

      std::cout << "Close server ... " << &std::endl;
      net::free(udp_server);
      std::cout << "Close server ... complete" << &std::endl;
    } catch (const std::exception &e) {
      std::cout << "Catch error: " << e.what() << &std::endl;
    }
    */
}