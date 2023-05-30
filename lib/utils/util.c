#include "util.h"

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

// returns a random number in range min through max, inclusive.
int Util::randrange(int min, int max)
{
    std::random_device rd;                           // obtain a random number from hardware
    std::mt19937 eng(rd());                          // seed the generator
    std::uniform_int_distribution<> distr(min, max); // define the range
    return distr(eng);
}

std::string Util::get_current_dir()
{
    char buff[FILENAME_MAX]; // create string buffer to hold path
    GetCurrentDir(buff, FILENAME_MAX);
    std::string current_working_dir(buff);
    return current_working_dir;
    // return "current_working_dir";
}
std::string Util::removeAllHtmlsTags(std::string html)
{

    while (html.find("<") != std::string::npos)
    {
        auto startpos = html.find("<");
        auto endpos = html.find(">") + 1;

        if (endpos != std::string::npos)
        {
            html.erase(startpos, endpos - startpos);
        }
    }
    return html;
}
// splits a string infinitely by delimiter until completely tokenized
std::vector<std::string> Util::split(std::string s, std::string delimiter)
{
    std::vector<std::string> output;

    std::string::size_type prev_pos = 0, pos = 0;

    while ((pos = s.find(delimiter, pos)) != std::string::npos)
    {
        std::string substring(s.substr(prev_pos, pos - prev_pos));
        output.push_back(substring);
        prev_pos = ++pos;
    }

    output.push_back(s.substr(prev_pos, pos - prev_pos)); // Last word

    return output;
}

// splits a string by the first instance of delimiter
std::vector<std::string> Util::split_once(std::string s, std::string delimiter)
{
    std::vector<std::string> output;
    std::string::size_type pos = 0;

    if ((pos = s.find(delimiter, pos)) != std::string::npos)
    {
        output.push_back(std::string(s.substr(0, pos)));
        output.push_back(std::string(s.substr(pos + 1)));
    }

    return output;
}

// trim from start (in place)
void Util::ltrim(std::string &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
                                    std::not1(std::ptr_fun<int, int>(std::isspace))));
}

// trim from end (in place)
void Util::rtrim(std::string &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(),
                         std::not1(std::ptr_fun<int, int>(std::isspace)))
                .base(),
            s.end());
}

// trim from both ends (in place)
void Util::trim(std::string &s)
{
    ltrim(s);
    rtrim(s);
}

// trim from start (copying)
std::string Util::ltrim_copy(std::string _s)
{
    std::string s = _s;
    ltrim(s);
    return s;
}

// trim from end (copying)
std::string Util::rtrim_copy(std::string _s)
{
    std::string s = _s;
    rtrim(s);
    return s;
}

// trim from both ends (copying)
std::string Util::trim_copy(std::string _s)
{
    std::string s = _s;
    trim(s);
    return s;
}

// convert string to lowercase version of same string
std::string Util::lowercase(std::string _s)
{
    std::string s = _s;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// convert type integer to string
std::string Util::int2str(int i)
{
    std::string out;
    std::stringstream ss;
    ss << i;
    return ss.str();
}
