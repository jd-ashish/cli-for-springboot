
#include <sstream>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include <random>

// Utility class to manage misc. functions

class Util {
public:
    static std::string get_current_dir();
    static std::string removeAllHtmlsTags(std::string);
    static int randrange(int min, int max);
    static void trim(std::string&);
    static void ltrim(std::string&);
    static void rtrim(std::string&);
    static std::string trim_copy(std::string);
    static std::string ltrim_copy(std::string);
    static std::string rtrim_copy(std::string);
    static std::string int2str(int);
    static std::string lowercase(std::string);
    static std::vector<std::string> split(std::string, std::string);
    static std::vector<std::string> split_once(std::string, std::string);
};
