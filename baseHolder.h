#ifndef BASEHOLDER_H
#define BASEHOLDER_H

#include <iostream>

class BaseHolder
{
public:
    virtual ~BaseHolder();

    virtual int size() const = 0;
    virtual std::string data() const = 0;

    friend bool operator<(const BaseHolder& a, const BaseHolder& b);
    friend std::ostream& operator<<(std::ostream& out,
                                    const BaseHolder& base);
    virtual std::ostream& print(std::ostream&) const = 0;
};

#endif // BASEHOLDER_H
