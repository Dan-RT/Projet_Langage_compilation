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

void Variable::set_tab_first(string data) {
    tab_first.push_back(data);
}

void Variable::show_tab_first () const {
    
    cout << "\nVar : " << name << " First : ";
    
    for (int i = 0; i < tab_first.size(); i++) {
        cout << tab_first[i] << " ";
    }
    cout << endl;
}

bool Variable::contains_final_sign () const {
    
    for (int i = 0; i < tab_first.size(); i++) {
        if (tab_first[i] == "#") {
            return true;
        }
    }
    return false;
}

int Variable::get_nb_first () const {
    return tab_first.size();
}

string Variable::get_first (int indice) const {
    return tab_first[indice];
}

bool Variable::contains_precised_sign_first (string data) const {
    for (int i = 0; i < tab_first.size(); i++) {
        if (tab_first[i] == data) {
            return true;
        }
    }
    return false;
}





