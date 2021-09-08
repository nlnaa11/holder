#ifndef CHARARRAYHOLDER_H
#define CHARARRAYHOLDER_H

#include <utility>
#include "baseHolder.h"

class CharArrayHolder : public BaseHolder
{
public:
    CharArrayHolder(const char data[] = "");
    ~CharArrayHolder();

    CharArrayHolder(const CharArrayHolder&) = delete;
    CharArrayHolder& operator=(const CharArrayHolder&) = delete;

    CharArrayHolder(CharArrayHolder&&) noexcept;
    CharArrayHolder& operator=(CharArrayHolder&&) noexcept = delete;

    void Swap(CharArrayHolder&) noexcept;

    int size() const override;
    std::ostream& print(std::ostream&) const override;
    std::string data() const override;

private:
    char* m_data = nullptr;
};

inline void swap(CharArrayHolder& a,
                 CharArrayHolder& b) noexcept
{
    a.Swap(b);
}

#endif // CHARARRAYHOLDER_H
