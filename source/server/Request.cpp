#include "Request.hpp"

#include <cstring>
#include <exception>
#include <iostream>

Request::Request() { }

Request::~Request() { }

void Request::deserialize(std::string& dest)
{

    auto rtpHeader = reinterpret_cast<RtpHeader*>(buffer.data());

    std::cout << "Incoming message! " << &std::endl;
    std::cout << "RtpHeader len: " << rtpHeader->payload_len << &std::endl;
    std::cout << "RtpHeader.isError: " << rtpHeader->isError << &std::endl;
    if (rtpHeader->isError == true)
        std::cout << "---ERROR---" << &std::endl;
    else
        std::cout << "---BEGIN---" << &std::endl;

    std::cout << (char*)data() << &std::endl;
    std::cout << "---END---" << &std::endl;
}

void* Request::payload() { return buffer.data(); }

void* Request::data() { return buffer.data() + sizeof(RtpHeader); }

uint64_t Request::size()
{
    auto rtpHeader = reinterpret_cast<RtpHeader*>(buffer.data());
    return rtpHeader->payload_len;
}