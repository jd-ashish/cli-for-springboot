#include <iostream>
#include <list>

class InitData
{
public:
    static void Insert(std::map<std::string, std::string> map);
    static void MyData();
    static nlohmann::json GetData();
};