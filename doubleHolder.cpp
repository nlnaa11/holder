#include "doubleHolder.h"

DoubleHolder::DoubleHolder(double data) noexcept
    : m_data(data)
{
} // DoubleHolder

DoubleHolder::~DoubleHolder()
{
} // ~DoubleHolder

int DoubleHolder::size() const
{
    return sizeof(double);
} // size

std::ostream& DoubleHolder::print(std::ostream& out) const
{
    out << m_data;
    return out;
} // print

std::string DoubleHolder::data() const
{
    return std::string{ std::to_string(m_data) };
} // data
