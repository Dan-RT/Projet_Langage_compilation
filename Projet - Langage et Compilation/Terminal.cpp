
#include "Terminal.h"

Terminal::Terminal() {
    
}

Terminal::~Terminal() {
    
}

void Terminal::set_axiome(bool choice) {
    axiome = choice;
}

void Terminal::add_rules(string rule) {
    tab_rules.push_back(rule);
}

void Terminal::delete_rules() {
    //à compléter
}

bool Terminal::is_axiome() {
    return axiome;
}

string Terminal::get_rule(int indice) {
    return tab_rules[indice];
}

int Terminal::get_nb_rules() const {
    return tab_rules.size();
}

void Terminal::show_rules () const {
    cout << "Var : " << this->get_name() << endl;
    
    for (int i = 0; i < tab_rules.size(); i++) {
        cout << "Rule " << i+1 << " : " << tab_rules[i] << endl;
    }
    cout << endl;
}

