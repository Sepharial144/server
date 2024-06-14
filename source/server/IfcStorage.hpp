#ifndef _STORAGE_INTERFACE_HPP_
#define _STORAGE_INTERFACE_HPP_

#include "buffer/IfcBuffer.hpp"

#include <memory>
#include <string>

class IStorage {
public:
    explicit IStorage();
    virtual ~IStorage();

    virtual auto getMessage(size_t hash) -> std::shared_ptr<IBuffer> = 0;
};

#endif //! _STORAGE_INTERFACE_HPP_