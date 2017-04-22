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
    static vector<char> tab_name;
    
public:
    
    Non_terminal();
    
    void set_axiome(bool choice);
    void add_rules(string rule);
    void delete_rules();
    void look_for_non_terminals();
    
    bool is_axiome();
    string get_rule(int indice);
    int get_nb_rules() const;
    void show_rules() const;
    
    virtual ~Non_terminal();
    
};



#endif // CONTRAINTE_H
