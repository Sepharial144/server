#ifndef _NET_REQUEST_HPP_
#define _NET_REQUEST_HPP_

#include <array>
#include <cstdint>
#include <string>

#include "Protocol.hpp"

class Request {
public:
    explicit Request();
    virtual ~Request();

    void deserialize(std::string& dest);
    void* payload();
    // bool error(); // TODO: implement
    void* data();
    uint64_t size();

private:
    std::array<uint8_t, BUFFER_SIZE> buffer {};
};

#endif // !_NET_REQUEST_HPP_