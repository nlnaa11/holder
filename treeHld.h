#ifndef TREEHLD_H
#define TREEHLD_H

#include <set>
#include <list>
#include <memory>
#include <string>
#include <algorithm>
#include "baseHolder.h"

class BaseHolder;

class TreeHld
{
    struct Less
    {
        bool operator()(std::shared_ptr<BaseHolder> a,
                        std::shared_ptr<BaseHolder> b)
        {
            return a->data() < b->data();
        }
    };

public:
    TreeHld() noexcept;
    TreeHld(std::string&& data);

    TreeHld(const TreeHld&) = delete;
    TreeHld& operator=(const TreeHld&) = delete;
    TreeHld(TreeHld&&) noexcept;
    TreeHld& operator=(TreeHld&&) = delete;

    void restoreTree(std::string&& data);
    void fillWithRandData(int count);

    void insertData(std::string&&, double, int);
    void insertStr(std::string&&);
    void insertInt(int);
    void insertDouble(double);

    void clear();
    void removeStr(std::string&&);
    void removeInt(int);
    void removeDouble(double);

    std::list<std::string> data() const;

    using BaseHldPtr = std::shared_ptr<BaseHolder>;

    const std::set<BaseHldPtr, Less>* operator->() const;
    const std::set<BaseHldPtr, Less>& operator*() const;

private:
    std::set<BaseHldPtr, Less> m_tree;
};

#endif // TREEHLD_H
