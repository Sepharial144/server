#ifndef _QUEUED_CLIENT_HPP_
#define _QUEUED_CLIENT_HPP_

#include <deque>
#include <mutex>
#include <optional>

template <class T>
class QueuedClient {
public:
    explicit QueuedClient();
    virtual ~QueuedClient();

    void pushBack(T& element);
    auto getFront() -> std::optional<T>;

private:
    std::deque<T> m_chunk;
    std::mutex mtx;
};

template <class T>
QueuedClient<T>::QueuedClient() { }

template <class T>
QueuedClient<T>::~QueuedClient() { }

template <class T>
auto QueuedClient<T>::pushBack(T& element) -> void
{
    // TODO: maybe lock guard
    mtx.lock();
    m_chunk.push_back(element);
    mtx.unlock();
}

template <class T>
auto QueuedClient<T>::getFront() -> std::optional<T>
{
    std::lock_guard<std::mutex> lg { mtx };
    if (m_chunk.size() > 0) {
        auto result = m_chunk.front();
        m_chunk.pop_front();
        return result;
    }
    return {};
}

#endif //!_QUEUED_CLIENT_HPP_