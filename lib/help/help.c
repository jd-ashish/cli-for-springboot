#include "help.h"

#include <iostream>
#include <list>

void Help::helpList()
{
    // std::cout << "Welcome to Flixlib" << std::endl
    std::list<std::string> list = {
        "\033[1;33mcheck\033[0m",
        "\033[1;32mcheck is-pom\033[0m             \033[1;32mcheck pom.xml file exist not not\033[0m",
        "\033[1;33mget\033[0m",
        "\033[1;32mget pkg             get project pkg name\033[0m",
        "\033[1;32mget data             get your projects informations\033[0m",
    };

    for (auto const &i : list)
    {
        std::cout << i << std::endl;
    }
}

std::string Help::readXMLfile(const char *xmlFile, std::string type_info)
{
    std::string pkg = "";
    FILE *fp;
    char s[2048];
    // Open XML file to read
    fp = fopen(xmlFile, "r");

    if (fp == NULL)
        printf("File error, can't read! n");
    else
    {
        // read each lines of XML file
        int groupIdCount = 0, artifactIdCount = 0;

        while (!feof(fp))
        {

            fgets(s, 2047, fp); // max 2047 char
            if (type_info == "pkg")
            {
                char *groupId = strstr(s, "<groupId>");
                char *artifactId = strstr(s, "<artifactId>");

                if (artifactId != NULL)
                {
                    if (artifactIdCount == 1)
                    {
                        pkg.append(artifactId);
                    }
                    artifactIdCount++;
                }
                if (groupId != NULL)
                {

                    if (groupIdCount == 1)
                    {
                        pkg.append(groupId).append(".");
                    }

                    groupIdCount++;
                }
            }
            else if (type_info == "java_version")
            {
                char *java_version = strstr(s, "<java.version>");
                if (java_version != NULL)
                {
                    pkg.append(java_version);
                }
            }
        };

        // std::string pkgData = Util::removeAllHtmlsTags(pkg);

        // pkgData.erase(std::remove(pkgData.begin(), pkgData.end(), '\n'), pkgData.end());

        // std::cout << pkgData << '\n';

        fclose(fp);
    }
    return pkg;
}

bool Help::CheckDir(std::string dir)
{

    // if (!dir.empty())
    // {
    //     dir.erase(dir.size() - 1);
    // }
    if (std::filesystem::is_directory(dir.c_str()))
    {
        return true;
    }
    else
    {
        return false;
    }
}