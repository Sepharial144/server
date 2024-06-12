#ifndef _STORAGE_SHARED_MEMORY_HPP_
#define _STORAGE_SHARED_MEMORY_HPP_

#include "IfcBuffer.hpp"

class SharedMemory : public IBuffer {
public:
  explicit SharedMemory();
  virtual ~SharedMemory();

  virtual auto fill(const void *data) -> void override;
  virtual auto data() -> void * override;
  virtual auto size() -> size_t override;

private:
  std::string m_buffer;
};

#endif //!_STORAGE_SHARED_MEMORY_HPP_