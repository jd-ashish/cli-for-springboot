
std::string getSample(nlohmann::json json, std::map<std::string, std::string> resource)
{
    std::string pkg = json["root_pkg"];
    std::string fileName = json["fileName"];

    // std::cout << resource << "\n";
    std::string sampleCode;

    // Add sample code to the string
    sampleCode += "package  " + pkg + "\n";
    for (const auto &pair : resource)
    {
        sampleCode += pair.second + "\n";
    }
    sampleCode += "\n";
    sampleCode += "@RestController\n";
    sampleCode += "public class "+fileName+" {\n";
    sampleCode += "    @GetMapping({\"/""\", ""\"/logins\"})\n";
    sampleCode += "    public String home() {\n";
    sampleCode += "         System.out.println(\"workingfile\");\n";
    sampleCode += "         return \"Spring boot api working fine\";\n";
    sampleCode += "    }\n";
    sampleCode += "\n";
    sampleCode += "}";
    sampleCode += "\n";

    return sampleCode;
}