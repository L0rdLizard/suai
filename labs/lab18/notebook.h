#include <iostream>
#include <string>
#include <map>


class notebook
{
    public:
        // notebook();
        // ~notebook();
        void add(const std::string &name, unsigned long phone);
        void erase(const std::string &name);
        std::string find(unsigned long phone);
        unsigned int find(const std::string& name);
        friend std::ostream& operator<<(std::ostream& os, const notebook& n);
        void load(const std::string& filename);
        void save(const std::string& filename);
        void loadyaml(const std::string& filename);
        void saveyaml(const std::string& filename);
    private:
        std::map<std::string, unsigned long> phonebook;
};
