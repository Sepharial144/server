#include "Storage.hpp"
#include "buffer/SimpleMemory.hpp"

Storage::Storage() { }

Storage::~Storage() { }

std::shared_ptr<IBuffer> Storage::getMessage(size_t hash)
{
    std::shared_ptr<IBuffer> result = std::make_shared<SimpleMemory>();
    std::string simpleMessage = "Super Message";
    result->fill(simpleMessage.data(), simpleMessage.size());
    return result;
}
