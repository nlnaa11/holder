#include <cstdlib>
#include <sstream>
#include <regex>
#include "treeHld.h"
#include "baseHolder.h"
#include "charArrayHolder.h"
#include "intHolder.h"
#include "doubleHolder.h"

using BaseHldPtr = std::shared_ptr<BaseHolder>;

TreeHld::TreeHld() noexcept
    : m_tree{}
{
} // TreHld

TreeHld::TreeHld(std::string&& data)
{
    restoreTree(std::move(data));
} // TreeeHld(string)

TreeHld::TreeHld(TreeHld&& other) noexcept
    : TreeHld()
{
    m_tree.swap(other.m_tree);
} // TreeHld(&&)

void TreeHld::restoreTree(std::string&& treeData)
{
    std::stringstream data(std::move(treeData));
    std::list<std::string> list;

    for(std::string word; data >> word;
        list.emplace_back(word));

    std::regex int_word{ "(\\b-?[0-9]+\\b)" };
    std::regex double_word{ "(\\b-?[0-9]+\\.+[0-9]+\\b)" };

    for(auto& word : list)
    {
        data.clear();

        if(std::regex_search(word, double_word))
        {
            double d_data;
            //std::cout << word << " D\n";
            data << word;
            data >> d_data;
            insertDouble(d_data);
        }
        else if(std::regex_search(word, int_word))
        {
            int i_data;
            //std::cout << word << " Int\n";
            data << word;
            data >> i_data;
            insertInt(i_data);
        }
        else // char[10]
        {
            //std::cout << word << " S\n";
            insertStr(std::move(word));
        }
    }
} // restoreTree

/** Modifiers **/

std::string getRandStr();
int getRandInt(int min = -320000, int max = 320000); // randMagicNumber
double getRandDouble(int min = -76769, int max = 567809);

void TreeHld::fillWithRandData(int count)
{
    for(int i = 0; i < count; ++i)
    {
        m_tree.emplace(std::make_shared<CharArrayHolder>
                       (getRandStr().c_str()));
        m_tree.emplace(std::make_shared<IntHolder>
                       (getRandInt()));
        m_tree.emplace(std::make_shared<DoubleHolder>
                       (getRandDouble()));
    }
} // fillWithRandData

void TreeHld::insertData(std::string&& str, double d, int i)
{
    insertStr(std::move(str));
    insertDouble(d);
    insertInt(i);
} // insertData

void TreeHld::insertStr(std::string&& data)
{
    m_tree.emplace(std::make_shared<CharArrayHolder>
                    (std::move(data).c_str()));
} // insertStr

void TreeHld::insertInt(int data)
{
    m_tree.emplace(std::make_shared<IntHolder>(data));
} // insertInt

void TreeHld::insertDouble(double data)
{
    m_tree.emplace(std::make_shared<DoubleHolder>(data));
} // insertDouble

void TreeHld::clear()
{
    TreeHld tmp;
    m_tree.swap(tmp.m_tree);
} // clear

void TreeHld::removeStr(std::string&& data)
{
    BaseHldPtr str_p =
        std::make_shared<CharArrayHolder>(std::move(data).c_str());

    auto it_data{ m_tree.find(str_p) };

    if(it_data != m_tree.end())
        m_tree.erase(it_data);
} // removeStr

void TreeHld::removeInt(int data)
{
    BaseHldPtr int_p =
        std::make_shared<IntHolder>(data);

    auto it_data{ m_tree.find(int_p) };

    if(it_data != m_tree.end())
        m_tree.erase(it_data);
} // removeInt

void TreeHld::removeDouble(double data)
{
    BaseHldPtr d_p =
        std::make_shared<DoubleHolder>(data);

    auto it_data{ m_tree.find(d_p) };

    if(it_data != m_tree.end())
        m_tree.erase(it_data);
} // removeDouble

/** Read-only access **/

std::list<std::string> TreeHld::data() const
{
    std::list<std::string> data;

    for(const auto& hld : m_tree)
        data.emplace_back(hld->data());

    return data;
} // data

const
std::set<BaseHldPtr, TreeHld::Less>* TreeHld::operator->() const
{
    return &m_tree;
} // operator->

const
std::set<BaseHldPtr, TreeHld::Less>& TreeHld::operator*() const
{
    return m_tree;
} // operator*

/** helper functions **/

std::string getRandStr()
{
    int size = getRandInt(0, 9);
    std::string str;

    static const double
        fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    int i = 0;
    for( ; i < size; ++i)
    {
        str += static_cast<char>
                (rand() * fraction * (127 - 33 + 1) + 33);
        // from 33 to 127 -- codes of printed asci characters
        // ' ' is forbidden
    }
    str[i] = '\0';

    return str;
} // getRandStr

int getRandInt(int min, int max)
{
    return static_cast<int>(getRandDouble(min, max));
} // getRandInt

double getRandDouble(int min, int max)
{
    static const double
        fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return (rand() * fraction * (max - min + 1) + min);
} // getRandDouble
