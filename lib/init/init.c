#include "init.h"

#include <iostream>
#include <list>
#include "../utils/util.c"
#include <filesystem>
#include <fstream>
#include <map>

void CreateDataInitFile()
{
    const char *newDir = "/.filixlib/data.json";

    std::string c = Util::get_current_dir() + newDir;
    const char *newDirPath = c.c_str();

    if (std::filesystem::exists(newDirPath) == false)
    {
        std::ofstream outfile(newDirPath);

        outfile << "my text here!" << std::endl;

        outfile.close();

        std::cout << "projectd started" << std::endl;
    }
    else
    {
        std::map<std::string, std::string> map;

        // Insert some values into the map
        map["pkg"] = "com.flixlib.app";
        map["root"] = "root/directry";

        // https://github.com/dropbox/json11/blob/master/json11.cpp
        // json11::Json Json_mp = json11::Json(map);

        std::cout << "projectd already started" << std::endl;
    }
}

void Init::start()
{
    const char *newDir = "/.filixlib";

    std::string c = Util::get_current_dir() + newDir;
    const char *newDirPath = c.c_str();
    if (std::filesystem::is_directory(newDirPath) == false)
    {
        std::filesystem::create_directory(newDirPath);
        std::cout << "projectd started" << std::endl;
    }
    else
    {
        CreateDataInitFile();
        std::cout << "projectd already started" << std::endl;
    }
}
