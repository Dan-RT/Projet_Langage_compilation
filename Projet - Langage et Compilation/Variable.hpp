//
//  Variable.hpp
//  Projet - Langage et Compilation
//
//  Created by Daniel Regnard on 22/04/2017.
//  Copyright © 2017 A. All rights reserved.
//

#ifndef Variable_hpp
#define Variable_hpp

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Variable {
    
protected:
    string name;
    
public:
    
    Variable();
    
    void set_name (string name);
    
    string get_name () const;
    
    virtual ~Variable();
    

};










#endif /* Variable_hpp */
