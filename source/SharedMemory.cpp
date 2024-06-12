#include "SharedMemory.hpp"

SharedMemory::SharedMemory() 
{
}

SharedMemory::~SharedMemory() 
{
}

void SharedMemory::fill(const void *data)
{ 
    m_buffer = (const char*)(data); 
}

void* SharedMemory::data()
{
}

size_t SharedMemory::size() 
{
}