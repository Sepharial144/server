#ifndef _SERVER_STORAGE_HPP_
#define _SERVER_STORAGE_HPP_

#include "IfcStorage.hpp"
#include "IfcBuffer.hpp"

#include <functional>

class Storage : public IStorage {
public:
  explicit Storage();
  virtual ~Storage();
  auto getMessage() -> std::shared_ptr<IBuffer> override;
};

#endif // !_SERVER_STORAGE_HPP_