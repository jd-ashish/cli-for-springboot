#include "help.h"

#include <iostream>
#include <list>

void Help::helpList()
{
    // std::cout << "Welcome to Flixlib" << std::endl
    std::list<std::string> list = {
        "check",
        "check is-pom             check pom.xml file exist not not",
        "get",
        "get pkg             get project pkg name"
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
            }else if(type_info == "java_version"){
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
