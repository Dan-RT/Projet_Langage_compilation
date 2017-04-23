#include "Non_terminal.h"

using namespace std;


Non_terminal::Non_terminal() {
    set_type(2);
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

void Non_terminal::delete_rule(int indice) {
    tab_rules.erase(tab_rules.begin()+indice);
}

void Non_terminal::modify_rule(int indice, string data) {
    tab_rules[indice] = data;
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

/*void Non_terminal::show_rules () const {
    cout << "Var : " << this->get_name() << endl;
    
    for (int i = 0; i < tab_rules.size(); i++) {
        cout << "Rule " << i+1 << " : " << tab_rules[i] << endl;
    }
    cout << endl;
}
*/

void Non_terminal::show_rules () const {
    cout << this->get_name() << " = ";
    
    for (int i = 0; i < tab_rules.size(); i++) {
        cout << tab_rules[i];
        if (i+1 != tab_rules.size()) {
            cout << "|";
        }
    }
    cout << endl;
}







