#ifndef _NET_PROTOCOL_HPP_
#define _NET_PROTOCOL_HPP_

#include <cstdint>

#pragma pack(push, 1)
struct RtpHeader
{   
    uint64_t payload_len;
    uint8_t[64] source;
}
#pragma pack(pop)

class Protocol 
{
    public:
        explicit Protocol() {};
        virtual ~Protocol() {};

        void serialize(std::string& source, std::string& data);
    private:
};

void serialize(std::string& source, std::string& data);

#endif // !_NET_PROTOCOL_HPP_