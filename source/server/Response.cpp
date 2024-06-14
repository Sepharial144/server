#include "Response.hpp"

#include <cstring>
#include <exception>
#include <iostream>

Response::Response() { }

Response::~Response() { }

void Response::serialize(std::string& source, std::string& data)
{

    auto rtpHeader = reinterpret_cast<RtpHeader*>(buffer.data());

    if (source.size() > 64u) {
        throw std::invalid_argument("The source of header property is too long");
    }
    void* pData = buffer.data() + sizeof(RtpHeader);

    if (BUFFER_SIZE - sizeof(RtpHeader) < data.size()) {
        std::string error = "The actual size of payload is too long!";
        std::memcpy(pData, error.data(), error.size());
        rtpHeader->payload_len = error.size();
        rtpHeader->isError = true;
        return;
    }

    rtpHeader->payload_len = data.size();
    rtpHeader->isError = false;
    std::memcpy(&rtpHeader->source, source.data(), source.size());
    std::memcpy(pData, data.data(), data.size());
}

void* Response::payload() { return buffer.data(); }

void* Response::data() { return buffer.data() + sizeof(RtpHeader); }

uint64_t Response::size()
{
    auto rtpHeader = reinterpret_cast<RtpHeader*>(buffer.data());
    return rtpHeader->payload_len;
}