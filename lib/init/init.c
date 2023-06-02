#include "init.h"

#include <iostream>
#include <list>
#include "../utils/util.c"
#include <filesystem>
#include <fstream>
#include <map>
#include "../json.hpp"
#include "../cppcodec/base64_default_rfc4648.hpp"

bool Init::start()
{
    bool projectStatus = false;   
    const char *newDir = "/.filixlib";

    std::string c = Util::get_current_dir() + newDir;
    const char *newDirPath = c.c_str();
    if (std::filesystem::is_directory(newDirPath) == false)
    {
        std::filesystem::create_directory(newDirPath);
        std::cout << "projectd started" << std::endl;
        projectStatus = true;
    }
    else
    {
        std::cout << "projectd already started" << std::endl;
        projectStatus = false;
    }
    return projectStatus;
}
