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
    
    
public:
    
    Terminal();
    
    void set_name (string data);
    
    virtual ~Terminal();
    
};

#endif // VARIABLE_H
