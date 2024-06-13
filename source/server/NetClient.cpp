#include "NetClient.hpp"

#include <chrono>

NetClient::NetClient() {}

NetClient::NetClient(const std::string &label, const StoragePtr p_storage)
    : m_netClientName{label}, m_pStorage{p_storage} {}

NetClient::~NetClient() { stop(); }

void NetClient::mainLoop() {
  while (m_loopIsStarted == true) {
    std::this_thread::sleep_for(std::chrono::microseconds(33));
    auto element = QueuedClient::getFront();
    if (element.has_value()) {
      std::cout << m_netClientName << ": net client running ..."
                << element.value() << &std::endl;
      continue;
    }
    std::cout << m_netClientName << ": net client running ..."
              << "has no value" << &std::endl;
  }
}

void NetClient::start() {
  m_loopIsStarted = true;
  m_thread = std::thread(&NetClient::mainLoop, this);
}

void NetClient::stop() {
  m_loopIsStarted = false;
  if (m_thread.joinable())
    m_thread.join();
}

void NetClient::sendMessage(std::shared_ptr<IBuffer> ptrMemory) {
  m_netStream.send(ptrMemory->data());
}

void NetClient::publish(size_t element) { QueuedClient::pushBack(element); }

/*
NetClient &NetClient::operator=(const NetClient &other)
{
  m_netStream = {};
  m_pStorage = std::move(other.m_pStorage);
  m_netClientName = std::move(other.m_netClientName);
  m_loopIsStarted = std::move(other.m_loopIsStarted);
  this->m_thread = std::move(other.m_thread);
  return *this;
}
*/

/*
NetClient::NetClient(const NetClient& other)
{
  m_netStream = {};
  m_pStorage = std::move(other.m_pStorage);
  m_netClientName = std::move(other.m_netClientName);
  m_loopIsStarted = std::move(other.m_loopIsStarted);
  this->m_thread = std::move(other.m_thread);
}
*/

NetClient::NetClient(NetClient &&other)
{
  m_netStream = {};
  m_pStorage = std::move(other.m_pStorage);
  m_netClientName = std::move(other.m_netClientName);
  m_loopIsStarted = std::move(other.m_loopIsStarted);
  this->m_thread = std::move(other.m_thread);
}