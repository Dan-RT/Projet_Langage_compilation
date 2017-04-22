#ifndef VARIABLE_H
#define VARIABLE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Variable.hpp"

using namespace std;


class Terminal : public Variable {

private:
    string name;
    
public:
    
    Terminal();
    virtual ~Terminal();
    
};

#endif // VARIABLE_H
