#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <time.h>
#include "sat3.h"

sat3::sat3(std::string file_name, int i = 0) 
{
    std::string garbage;
    unsigned n_variables, n_statement;
    srand(i==0?time(NULL):i);

    std::ifstream file; 
    file.open(file_name);
    if(!file.is_open()) {
        std::cout << "No such File" << std::endl; 
        exit(0);
    }
    
    while(!file.eof()){
        file >> garbage;
        if(garbage == "c") std::getline(file, garbage);
        else{
            file >> garbage >> n_variables >> n_statement;
            break;
        }
    }

    for(unsigned i = 0; i < n_statement; ++i){
        int v1, v2, v3;
        file >> v1 >> v2 >> v3 >> garbage;
        statement.push_back(clausule(variable(v1), variable(v2), variable(v3)));
        value[abs(v1)] = rand() % 2;
        value[abs(v2)] = rand() % 2;
        value[abs(v3)] = rand() % 2;
    }
}
