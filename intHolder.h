#ifndef INTHOLDER_H
#define INTHOLDER_H

#include <ostream>
#include <cstdint>
#include "baseHolder.h"

class IntHolder : public BaseHolder
{
public:
    IntHolder(int data = 0) noexcept;
    ~IntHolder();

    IntHolder(const IntHolder&) = delete;
    IntHolder& operator=(const IntHolder&) = delete;

    IntHolder(IntHolder&&) noexcept = default;
    IntHolder& operator=(IntHolder&&) noexcept = delete;

    std::ostream& print(std::ostream&) const override;
    int size() const override;
    std::string data() const override;

private:
    int32_t m_data;
};

#endif // INTHOLDER_H
