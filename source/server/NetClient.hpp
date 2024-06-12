#ifndef _NET_CLIENT_STORAGE_HPP_
#define _NET_CLIENT_STORAGE_HPP_

#include "IClient.hpp"

class IStorage;
class SharedMemory;

#include <functional>
#include <iostream>


using StorageReference = std::reference_wrapper<IStorage>;

class NetClient : public IClient {
public:
  explicit NetClient();
  explicit NetClient(const StorageReference storage);
  virtual ~NetClient();

  void sendMessage(std::shared_ptr<IBuffer> ptrMemory) override;

private:
  struct Recipient {
    void send(const void *data) { std::cout << data << &std::endl; }
  };

private:
  Recipient m_netStream{};
  StorageReference m_storage;
};

#endif // !_NET_CLIENT_STORAGE_HPP_