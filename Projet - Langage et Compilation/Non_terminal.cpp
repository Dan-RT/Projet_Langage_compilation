#include "Non_terminal.h"

using namespace std;


Non_terminal::Non_terminal() {
    
}

Non_terminal::~Non_terminal() {
    
}

void Non_terminal::set_name(string data) {
    
    Variable::set_name(data);
}

void Non_terminal::set_axiome(bool choice) {
    axiome = choice;
}

void Non_terminal::add_rules(string rule) {
    tab_rules.push_back(rule);
}

void Non_terminal::delete_rules() {
    //à compléter
}

bool Non_terminal::is_axiome() {
    return axiome;
}

string Non_terminal::get_rule(int indice) {
    return tab_rules[indice];
}

int Non_terminal::get_nb_rules() const {
    return tab_rules.size();
}

void Non_terminal::show_rules () const {
    cout << "Var : " << this->get_name() << endl;
    
    for (int i = 0; i < tab_rules.size(); i++) {
        cout << "Rule " << i+1 << " : " << tab_rules[i] << endl;
    }
    cout << endl;
}

void Non_terminal::set_tab_first(char data) {
    tab_first.push_back(data);
}

void Non_terminal::show_tab_first () const {
    
    cout << "Var : " << name << "\nFirst :"<< endl;
    
    for (int i = 0; i < tab_first.size(); i++) {
        cout << tab_first[i] << endl;
    }
}






