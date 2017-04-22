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
    int type;
    
public:
    
    Variable();
    
    void set_name (string name);
    void set_type (int i);
    
    string get_name () const;
    int get_type () const;
    
    virtual ~Variable();
    

};










#endif /* Variable_hpp */
