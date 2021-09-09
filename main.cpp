#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "treeHld.h"
#include "baseHolder.h"

std::string restoreTreeData();
bool saveTreeData(const std::list<std::string>& data);

int main()
{
    std::srand(std::time(nullptr));

    // if the data cannot be restored, a corresponding
    // message will be displayed and an empty tree
    // will be created

    TreeHld tree{ restoreTreeData() };

    tree.fillWithRandData(5);

    for(const auto& i : *tree)
        std::cout << i->data() << ' ';
    std::cout << std::endl << std::endl;

    tree.insertStr("Innopolis");

    for(const auto& i : *tree)
        std::cout << i->data() << ' ';
    std::cout << std::endl << std::endl;

    tree.removeStr("Innopolis");
    tree.removeInt(-102790);
    tree.removeDouble(0.00000);

    tree.insertData("Hooray!", 8.09, 2120);

    for(const auto& i : *tree)
        std::cout << i->data() << ' ';
    std::cout << std::endl;

    saveTreeData(tree.data());

    return 0;
}

std::string restoreTreeData()
{
    std::ifstream i_tree("treeHld.txt");
    std::string treeData{ "" };

    if(!i_tree)
        std::cout << "Failed to restore the tree data.\n";

    while(i_tree)
        std::getline(i_tree, treeData);

    return treeData;
} // restoreTreeData

bool saveTreeData(const std::list<std::string>& data)
{
    std::ofstream o_tree("treeHld.txt");

    if(!o_tree)
    {
        std::cout << "Failed to save the tree data.\n";
        return false;
    }

    for(const auto& it : data)
        o_tree << it << ' ';

    return true;
} // saveTreeData
