#include "ServerManager.hpp"

#include <exception>

ServerManager::ServerManager() {}

ServerManager::~ServerManager() {}

void ServerManager::readConfiguration() {
    // TODO: create with file system
  std::ifstream file("config.txt");
  std::string line{};
  if (file.is_open()) {
    std::cout << "Read configuration..." << std::endl;
    while (std::getline(file, line)) {
      auto first = line.find(' ');
      if (first != std::string::npos) {
        std::string resource = line.substr(0, first);
        std::string message = line.substr(first, line.size());
        m_confArray.emplace_back(Configuration{resource, message});
      } else {
        throw std::invalid_argument("The line of configuration is wrong!");
      }
    }
    // TODO: need to delete this
    //for (auto &el : m_confArray)
    //  std::cout << el.source << ":" << el.message << &std::endl;
    return;
  }
  throw std::invalid_argument("Configuration file could not readed!");
}

void ServerManager::initialization() {
  for (auto &el : m_confArray) {
    NetClient client{el.source, nullptr};
    size_t hash = std::hash<std::string>{}(el.source);
    m_mapClients.emplace(std::move(hash), NetClient{el.source, nullptr});
  }
}

void ServerManager::publish(std::string &source) {
  size_t hash = std::hash<std::string>{}(source);
  std::cout << "Server manager: " << hash << &std::endl;
  if (auto element = m_mapClients.find(hash); element != m_mapClients.end()) {
    // TODO: fix this
    element-second.publish(42);
  }
}