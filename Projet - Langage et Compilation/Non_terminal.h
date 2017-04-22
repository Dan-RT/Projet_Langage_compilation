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
    
    bool axiome;
    vector<string> tab_rules;
    
public:
    
    Non_terminal();
    
    static vector<string> tab_name;

    
    void set_axiome(bool choice);
    void add_rules(string rule);
    void delete_rules();
    void look_for_terminals();
    void set_name(string name);
    
    bool is_axiome();
    string get_rule(int indice);
    int get_nb_rules() const;
    void show_rules() const;
    
    virtual ~Non_terminal();
    
};



#endif // CONTRAINTE_H
