#include "NetClient.hpp"


NetClient::NetClient()
{  
}

NetClient::NetClient(const StorageReference storage) : StorageReference{storage} 
{  
}

NetClient::~NetClient() 
{  
}

void NetClient::sendMessage(std::shared_ptr<IBuffer> ptrMemory) 
{
  m_netStream.send(ptrMemory->data());
}