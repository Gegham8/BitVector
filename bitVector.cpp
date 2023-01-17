#include "vecBool.h"

VecBit::VecBit()
{
    m_size = 1;
    m_arr = new int[m_size];
}

VecBit::VecBit(const size_t size, bool value)
{
    m_size = size + 1;
    m_arr = new int[m_size];
    m_arr[size] = value;
}
VecBit::~VecBit()
{
    delete[] m_arr;
}
VecBit::VecBit(VecBit&& other)
{
    if (this->m_arr == other.m_arr)
    {
        return;
    }
    this->m_size = other.m_size;
    this->m_arr = other.m_arr;
    other.m_arr = nullptr;
    other.m_size = 0;
}
VecBit::VecBit(const VecBit& rhs)
{
    if (this->m_arr == rhs.m_arr)
    {
        return;
    }
    this->m_size = rhs.m_size;
    this->m_arr = new int[this->m_size];
    for (size_t i = 0; i < rhs.m_size; ++i)
    {
        this->m_arr[i] = rhs.m_arr[i];
    }
}

std::ostream& operator <<(std::ostream &out, const VecBit& v) 
{
    for (size_t i = 0; i < v.m_size; ++i)
    {
        out << v.m_arr[i] << " ";
    }
    return out;
}
std::size_t VecBit::operator[] (std::size_t i) 
{
    if (i >= m_size)
    {
        throw std::invalid_argument("Out of range");
    }
    return m_arr[i];
}
int VecBit::get(const size_t index) 
{
    if (index >= m_size)
    {
        throw std::invalid_argument("Out of range");
    }
    return m_arr[index];
}
void VecBit::set(const size_t size, const bool value)
{
    if (resize(size))
    {
        m_arr[size] = value;
        return;   
    }
    m_arr[size] = value;   
}
bool VecBit::resize(const size_t size)
{
    if (size >= m_size)
    {
        int* tmp = new int[size + 1];
        for (int i = 0; i < m_size; ++i)
        {
            tmp[i] = m_arr[i];
        }
        m_size = size + 1;
        delete [] m_arr;
        m_arr = tmp;
        tmp = nullptr;
        return true;
    }
    return false;
}
size_t VecBit::size() const
{
    return m_size;
}