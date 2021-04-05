#include <vector>
#include <map>
#include "clausule.h"

class sat3
{
public:
    std::vector<clausule> statement;
    std::map<int, bool> value;
    sat3();
    sat3(std::string file_name, int i);
    ~sat3() {}
};