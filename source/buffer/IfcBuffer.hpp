#ifndef _STORAGE_BUFFER_INTERFACE_HPP
#define _STORAGE_BUFFER_INTERFACE_HPP

#include <string>

class IBuffer {
public:
    explicit IBuffer();
    virtual ~IBuffer();

    virtual auto fill(const void* data, size_t len) -> void = 0;
    virtual auto data() -> void* = 0;
    virtual auto size() -> size_t = 0;
};

#endif //!_STORAGE_BUFFER_INTERFACE_HPP