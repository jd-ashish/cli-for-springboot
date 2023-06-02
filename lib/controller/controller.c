#include "controller.h"

#include <iostream>
#include <list>
#include <string>
#include <array>
#include "JavaSampleController.c"
using json = nlohmann::json;

void Controller::create(const char *controllerName , const char *codeType)
{

    std::string name = controllerName;
    std::string apiOrView = codeType;
    std::string apiOrViewType = "api";
    if(apiOrView=="view"){
        
    }
    std::string pwd = InitData::GetData()["pwd"];
    std::string pkg = InitData::GetData()["pkg"];
    std::string type = InitData::GetData()["type"];
    pwd.append("\\").append("src\\main\\java").append("\\");

    // Array to store split parts
    std::array<std::string, 3> parts; // Adjust the size based on the expected number of split parts

    // Start position for searching
    size_t startPos = 0;

    // Find the delimiter position and split the string
    size_t dotPos;
    size_t partIndex = 0; // Index for storing parts in the array
    while ((dotPos = pkg.find('.', startPos)) != std::string::npos)
    {
        std::string part = pkg.substr(startPos, dotPos - startPos);
        parts[partIndex] = part;
        startPos = dotPos + 1;
        partIndex++;
    }

    // Add the remaining part after the last delimiter
    std::string lastPart = pkg.substr(startPos);
    parts[partIndex] = lastPart;

    // Print the split parts
    for (const auto &part : parts)
    {
        pwd.append(part).append("\\");
    }

    std::string fileName = name + "." + type;
    if (Help::CheckDir(pwd))
    {
        pwd.append("Controller");
        std::string controllerFolder = pwd;
        std::cout << controllerFolder << "\n";
        std::cout << Help::CheckDir(controllerFolder) << "\n";
        std::string location = controllerFolder;
        location.append("\\").append(fileName);

        json jsonData; // Create an empty JSON object

        // Add jsonData to the JSON object
        jsonData["root_pkg"] = pkg+".Controller;";
        jsonData["fileName"] = name;
        std::map<std::string, std::string> resource;
        resource["pkg"] = "import org.springframework.web.bind.annotation.*;";

        if (Help::CheckDir(controllerFolder))
        {

            // Create an output file stream
            std::ofstream outputFile(location);

            // Check if the file was opened successfully
            if (outputFile.is_open())
            {
                // Write the content to the file
                outputFile << getSample(jsonData,resource);

                // Close the file
                outputFile.close();
                std::cerr << "writtened file" << std::endl;
            }
            else
            {
                std::cerr << "Failed to open the file." << std::endl;
            }
        }
        else
        {
            std::cerr << "another created " << std::endl;
            std::filesystem::create_directory(controllerFolder);
        }
    }
    else
    {
        printf("no directry exist");
    }

    // std::cout << InitData::GetData()["type"];

    // std::cout << Util::get_current_dir();
}