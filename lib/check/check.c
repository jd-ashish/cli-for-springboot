

#include "check.h"
#include <iostream>
#include <dirent.h>
#include <filesystem>

bool fileList(std::string pwd,std::string fileName){
    const char *ccx = pwd.c_str();
    if (auto dir = opendir(ccx))
    {
        while (auto f = readdir(dir))
        {
            if (!f->d_name || f->d_name[0] == '.')
                continue; // Skip everything that starts with a dot
            std::string fn = f->d_name;

            if( fn == fileName){
                return true;
            }

            // std::cout << f->d_name; 
            // printf("File: %s\n", f->d_name);
        }
        closedir(dir);
    }
    return false;
}
bool Check::args(const char *args, std::string pwd)
{
    std::string arg = args;
    if(arg=="is-pom"){
        if(fileList(pwd,"pom.xml")==true){
            return true;
        }
    }

    
    return false;
}