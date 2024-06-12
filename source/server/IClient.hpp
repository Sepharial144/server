#ifndef _CLIENT_INTERFACE_HPP_
#define _CLIENT_INTERFACE_HPP_

#include "IfcBuffer.hpp"

#include <functional>
#include <memory>

class IClient {
public:
  explicit IClient(){};
  virtual ~IClient(){};

  virtual void sendMessage(std::shared_ptr<IBuffer> ptrMemory) = 0;
};

#endif // !_CLIENT_INTERFACE_HPP_