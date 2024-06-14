#ifndef _NET_RESPONSE_HPP_
#define _NET_RESPONSE_HPP_

#include <array>
#include <cstdint>
#include <string>

#include "Protocol.hpp"

class Response {
public:
    explicit Response();
    virtual ~Response();

    void serialize(std::string& source, std::string& data);
    void* payload();
    void* data();
    uint64_t size();

private:
    std::array<uint8_t, BUFFER_SIZE> buffer {};
};

#endif // !_NET_RESPONSE_HPP_