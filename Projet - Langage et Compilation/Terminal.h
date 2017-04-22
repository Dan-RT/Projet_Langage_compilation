#ifndef VARIABLE_H
#define VARIABLE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Variable.hpp"

using namespace std;


class Terminal : public Variable {

public:
    
    Terminal();
    
    void set_axiome(bool choice);
    void add_rules(string rule);
    void delete_rules();
    void look_for_non_terminals();
    
    bool is_axiome();
    string get_rule(int indice);
    int get_nb_rules() const;
    void show_rules() const;
    
    virtual ~Terminal();
    
private:
    
    bool axiome;
    vector<string> tab_rules;
    
    
};

#endif // VARIABLE_H
