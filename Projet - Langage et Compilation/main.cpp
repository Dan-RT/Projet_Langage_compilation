#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "Variable.hpp"
#include "Terminal.h"
#include "Non_terminal.h"
#include "functions.hpp"


using namespace std;

int main() {
    
    
    Terminal test;
    
    //test.set_name("test");
    //cout << test.get_name() << endl;
    
    vector<Terminal> tab_var_T;
    vector<Non_terminal> tab_var_NT;
    vector<string> tab_name_NT, tab_name_T;

    //test.set_axiome(true);
    
    loading(tab_var_NT);
    show_all_rules(tab_var_NT);
    create_terminals(tab_var_NT, tab_var_T, tab_name_NT, tab_name_T);
    
    show_all_terminals(tab_var_T);
    show_all_non_terminals(tab_var_NT);
    
    
    
    return 0;
}
