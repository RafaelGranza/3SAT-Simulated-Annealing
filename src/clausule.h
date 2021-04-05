#include "variable.h"

class clausule{
public:
    variable first, second, third;
    clausule() {}
    clausule(variable f, variable s, variable t) { first = f; second = s; third = t;}
    ~clausule() {}
};
