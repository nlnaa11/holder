#include "baseHolder.h"

BaseHolder::~BaseHolder()
{
} // ~BaseHolder

bool operator<(const BaseHolder& a, const BaseHolder& b)
{
    return a.data() < b.data();
} // operator<

std::ostream& operator<<(std::ostream& out, const BaseHolder& b)
{
    return b.print(out);
} // operator<<
