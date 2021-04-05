#include <math.h>

class variable{
public:
    int id;
    bool signal;
    variable() {}
    variable(int _id) { 
        id = abs(_id);
        signal = (_id > 0)? 1: 0;
    }
    ~variable() {}
};
