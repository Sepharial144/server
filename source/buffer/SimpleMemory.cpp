#include "SimpleMemory.hpp"

SimpleMemory::SimpleMemory() { }

SimpleMemory::~SimpleMemory() { }

void SimpleMemory::fill(const void* data, size_t len)
{
    m_buffer.assign((const char*)data);
}

void* SimpleMemory::data() { return static_cast<void*>(m_buffer.data()); }

size_t SimpleMemory::size() { return m_buffer.size(); }