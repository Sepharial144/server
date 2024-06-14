#ifndef _SIMPLE_MEMORY_HPP_
#define _SIMPLE_MEMORY_HPP_

#include "IfcBuffer.hpp"

class SimpleMemory : public IBuffer {
public:
    explicit SimpleMemory();
    virtual ~SimpleMemory();

    virtual auto fill(const void* data, size_t len) -> void override;
    virtual auto data() -> void* override;
    virtual auto size() -> size_t override;

private:
    std::string m_buffer;
};

#endif //!_SIMPLE_MEMORY_HPP_