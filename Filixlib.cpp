#include <iostream>
#include <string>
#include <cstring>
#include "lib/utils/util.c"
#include "lib/help/help.c"
#include "lib/check/check.c"

using namespace std;

std::string exec(const char *cmd)
{
    FILE *pipe = _popen(cmd, "r");
    if (!pipe)
        return "ERROR";
    char buffer[128];
    std::string result = "";
    while (!feof(pipe))
    {
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    _pclose(pipe);
    return result;
}

void installApp()
{

    const char *newDir = "/.filixlib";
    string c = Util::get_current_dir() + newDir;
    const char *newDirPath = c.c_str();
    if (std::filesystem::is_directory(newDirPath) == false)
    {
        std::filesystem::create_directory(newDirPath);
        cout << "projectd started" << endl;
    }else{
        cout << "projectd already started" << endl;
    }
    //
    
    // std::cout << exec("hhfhdhf -version");
}

void pwd()
{

    cout << Util::get_current_dir();
}
void makecontroller()
{
}

std::string get(const char *get_type_list)
{
    std::string get_type = get_type_list;
    const char *pomfile = "is-pom";
    if (Check::args(pomfile, Util::get_current_dir()) == true)
    {
        const char *ffn = "/pom.xml";
        string c = Util::get_current_dir() + ffn;
        const char *xmlFile = c.c_str();
        std::string data = Help::readXMLfile(xmlFile, get_type);
        std::string pkgData = Util::removeAllHtmlsTags(data);

        pkgData.erase(std::remove(pkgData.begin(), pkgData.end(), '\n'), pkgData.end());

        return pkgData;
    }
    return "";
}

int main(int argc, char *argv[])
{

    for (int i = 0; i < argc; ++i)
    {

        if (argc > 1 && (strcmp(argv[i], "install-app") == 0 || strcmp(argv[i], "init") == 0))
        {
            installApp();
        }
        if (argc > 1 && (strcmp(argv[i], "help") == 0))
        {
            Help::helpList();
        }
        if (argc > 1 && (strcmp(argv[i], "check") == 0))
        {
            if (Check::args(argv[i + 1], Util::get_current_dir()) == true)
            {
                std::cout << "POM file exist!";
            }
            else
            {
                std::cout << "POM file not exist!";
            }
        }
        if (argc > 1 && (strcmp(argv[i], "pwd") == 0))
        {
            pwd();
        }
        if (argc > 1 && (strcmp(argv[i], "get") == 0))
        {
            get(argv[i + 1]);
        }
        if (argc > 1 && (strcmp(argv[i], "makecontroller") == 0))
        {
            cout << argv[i];
            cout << argv[i + 1];
        }
    }
    return 0;
}

// g++.exe   -c C:\cpp\Filixlib\Filixlib.cpp -o C:\cpp\Filixlib\Filixlib.o
// g++.exe  -o C:\cpp\Filixlib\Filixlib.exe C:\cpp\Filixlib\Filixlib.o