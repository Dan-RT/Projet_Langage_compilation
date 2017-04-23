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
    vector<string> tab_first;
    
public:
    
    Variable();
    
    void set_name (string name);
    void set_type (int i);
    void set_tab_first(string data);
    
    string get_name () const;
    int get_type () const;
    void show_tab_first () const;
    bool contains_final_sign () const;
    int get_nb_first () const;
    string get_first (int indice) const;
    bool contains_precised_sign_first (string data) const;
    
    virtual ~Variable();
    

};










#endif /* Variable_hpp */
