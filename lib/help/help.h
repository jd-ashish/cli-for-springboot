#include <iostream>
#include <list>

class Help
{
public:
    static void helpList();
    static std::string readXMLfile(const char *xmlFile, std::string type_info);

    //project dir check dir
    static bool CheckDir(std::string dir);
};