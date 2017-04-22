//
//  Variable.cpp
//  Projet - Langage et Compilation
//
//  Created by Daniel Regnard on 22/04/2017.
//  Copyright © 2017 A. All rights reserved.
//

#include "Variable.hpp"

Variable::Variable() {
    
}

Variable::~Variable() {

}

void Variable::set_name(string name){
    this->name = name;
}

string Variable::get_name() const {
    return this->name;
}

void Variable::set_type(int i){
    
    if (i == 1 || i == 2) {
        this->type = i;
    } else {
        cout << "Error : type send to Variable::set_type() is incorrect. Should be 1 for terminals, 2 for non terminals" << endl;
        exit(0);
    }
    
}

int Variable::get_type() const {
    return this->type;
}
