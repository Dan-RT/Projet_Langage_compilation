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
