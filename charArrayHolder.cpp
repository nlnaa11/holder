#include <ostream>
#include <cstring>
#include "charArrayHolder.h"

CharArrayHolder::CharArrayHolder(const char data[])
{
    m_data = new char[10]{};

    int size = strlen(data);
    int i = 0;

    if(size > 9)
        size = 9;

    while(size--)
    {
        m_data[i] = data[i];
        ++i;
    }
    m_data[i] = '\0';
} // CharArrayHolder

CharArrayHolder::~CharArrayHolder()
{
    delete[] m_data;
    m_data = nullptr;
} // ~CharArrayHolder

CharArrayHolder::CharArrayHolder(CharArrayHolder&& other) noexcept
    : CharArrayHolder()
{
    Swap(other);
} // CharArrayHolder(&&)

void CharArrayHolder::Swap(CharArrayHolder& other) noexcept
{
    auto tmp = std::move(other.m_data);
    other.m_data = std::move(m_data);
    m_data = std::move(tmp);
} // Swap

int CharArrayHolder::size() const
{
    return 10;
} // size

std::ostream& CharArrayHolder::print(std::ostream& out) const
{
    out << m_data;
    return out;
} // print

std::string CharArrayHolder::data() const
{
    return m_data;
} // data
