#ifndef CONTRAINTE_H
#define CONTRAINTE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Variable.hpp"

using namespace std;

class Non_terminal : public Variable {
    
private:
    string name;
    
public:
    
    Non_terminal();
    
    
    virtual ~Non_terminal();
    
};



#endif // CONTRAINTE_H
