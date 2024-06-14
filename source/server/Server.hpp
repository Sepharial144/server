#ifndef _SERVER_HPP_
#define _SERVER_HPP_

#include <cstdint>

class Server {
public:
    explicit Server();
    virtual ~Server();

    void listening(const char* address, uint64_t port);

private:
};

#endif // !_SERVER_HPP_