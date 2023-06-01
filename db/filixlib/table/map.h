class Map
{
private:
    /* data */
public:
    std::map<std::string, std::string> map;
    Map(std::map<std::string, std::string> data)
    {
        this->map = data;
    }
    std::string get(std::string key)
    {

        std::map<std::string, std::string>::iterator it;
        it = this->map.find(key);

        if (it == this->map.end())
            return NULL;
        else
            return it->second;
    }
};
