#include "intHolder.h"

IntHolder::IntHolder(int data) noexcept
    : m_data{data}
{
} // IntHolder()

IntHolder::~IntHolder()
{
} // ~IntHolder

int IntHolder::size() const
{
    return 4;
} // size

std::ostream& IntHolder::print(std::ostream& out) const
{
    out << m_data;
    return out;
} // print

std::string IntHolder::data() const
{
    return std::string{ std::to_string(m_data) };
} // data
