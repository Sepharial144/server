#include "Storage.hpp"
#include "SharedMemory.hpp"


Storage::Storage() 
{
}

Storage::~Storage() 
{
}

std::shared_ptr<IBuffer> Storage::getMessage() 
{
  std::shared_ptr<IBuffer> result = std::make_shared<SharedMemory>();
  result->fill("Super message");
  return result;
}
