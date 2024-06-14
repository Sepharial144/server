#ifndef _CONNECTION_HPP_
#define _CONNECTION_HPP_

#include <memory>
#include <string>

class IConnection {
public:
    explicit IConnection() {};
    virtual ~IConnection() {};
};

#endif //! _CONNECTION_HPP_