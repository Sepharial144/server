#ifndef _SERVER_MANAGER_HPP_
#define _SERVER_MANAGER_HPP_

#include "IfcClient.hpp"
#include "IfcConnection.hpp"
#include "NetClient.hpp"

#include <fstream>
#include <map>
#include <string>

class ServerManager {
public:
    explicit ServerManager();
    virtual ~ServerManager();

    void readConfiguration();
    void initialization();
    void routeConnection(IConnection& connection);
    void publish(std::string& source);

private:
    struct Configuration {
        std::string source;
        std::string message;
    };

private:
    std::vector<Configuration> m_confArray;
    std::map<size_t, NetClient> m_mapClients;
};

#endif // !_SERVER_MANAGER_HPP_