#include <iostream>
#include <string>
#include <cstring>
#include "lib/init/init.c"
// #include "lib/utils/util.c"
#include "lib/help/help.c"
#include "lib/check/check.c"

#include "db/filixlib/table/initdata.c"
#include "lib/controller/controller.c"
#include <conio.h> // For _getch() function (Windows-specific)

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

std::string get(const char *get_type_list)
{
    std::string get_type = get_type_list;
    if (get_type == "data")
    {

        InitData::MyData();
        return "";
    }
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
void getPhraseInput(const char *get_type_list)
{
    std::string get_type = get_type_list;
    if (get_type == "pkg")
    {
        printf("\033[1;34mPackage for you projects is\033[0m \033[1;32m\t%s\n\033[0m", get("pkg").c_str());
    }
    else
    {
        get(get_type_list);
    }
}
void createDataFile()
{
}
void installApp()
{

    std::map<std::string, std::string> map;

    map["token"] = "token";
    map["pkg"] = get("pkg");
    map["version"] = get("java_version");
    map["type"] = "java";
    map["pwd"] = Util::get_current_dir();
    if (Init::start() == true)
    {
        InitData::Insert(map);
    }
}

void pwd()
{

    cout << Util::get_current_dir();
}
void makecontroller()
{
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
            getPhraseInput(argv[i + 1]);
        }
        if (argc > 1 && (strcmp(argv[i], "makecontroller") == 0))
        {

            int selectedOption = 0;
            const int totalOptions = 3;

            while (true)
            {
                // system("cls"); // Clear the console screen (Windows-specific)

                // Display the menu options
                std::cout << "Menu Options:\n";
                for (int i = 0; i < totalOptions; ++i)
                {
                    if (selectedOption == i)
                    {
                        std::cout << "> ";
                    }
                    else
                    {
                        std::cout << "  ";
                    }
                    std::cout << "Option " << (i + 1) << "\n";
                }

                // Wait for user input
                char key = _getch(); // Get a key press (Windows-specific)

                // Process the user's input
                switch (key)
                {
                case 72: // Up arrow key
                    selectedOption = (selectedOption - 1 + totalOptions) % totalOptions;
                    break;
                case 80: // Down arrow key
                    selectedOption = (selectedOption + 1) % totalOptions;
                    break;
                case 13: // Enter key
                    // Perform the action corresponding to the selected option
                    std::cout << "You selected Option " << (selectedOption + 1) << ".\n";
                    // Add any additional code here for the selected option
                    break;
                }
            }

            // cout << argv[i];
            // Controller::create(argv[i + 1],argv[i + 2]);
            // cout << argv[i + 1];
        }
    }
    return 0;
}

// g++.exe   -c C:\cpp\Filixlib\Filixlib.cpp -o C:\cpp\Filixlib\Filixlib.o
// g++.exe  -o C:\cpp\Filixlib\Filixlib.exe C:\cpp\Filixlib\Filixlib.o
