#ifndef _NET_PROTOCOL_HPP_
#define _NET_PROTOCOL_HPP_

#define BUFFER_SIZE 4096
#define ERROR_RAM '@'
#define START_OF_TEXT static_cast<char>(2)
#define END_OF_TEXT static_cast<char>(3)

#pragma pack(push, 1)
struct RtpHeader {
    uint64_t payload_len;
    bool isError;
    uint8_t source[64];
};
#pragma pack(pop)

#endif // !_NET_PROTOCOL_HPP_