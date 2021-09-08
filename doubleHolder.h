#ifndef DOUBLEHOLDER_H
#define DOUBLEHOLDER_H

#include <ostream>
#include "baseHolder.h"

class DoubleHolder : public BaseHolder
{
public:
    DoubleHolder(double data = 0.0) noexcept;
    ~DoubleHolder();

    DoubleHolder(const DoubleHolder&) = delete;
    DoubleHolder& operator=(const DoubleHolder&) = delete;

    DoubleHolder(DoubleHolder&&) noexcept = default;
    DoubleHolder& operator=(DoubleHolder&&) noexcept = delete;

    std::ostream& print(std::ostream&) const override;
    int size() const override;
    std::string data() const override;

private:
    double m_data;
};

#endif // DOUBLEHOLDER_H
