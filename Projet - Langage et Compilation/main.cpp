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
    
    vector<Terminal> tab_var;
    vector<Non_terminal> tab_var_NT;

    //test.set_axiome(true);
    
    loading(tab_var);
    show_all_rules(tab_var);
    create_non_terminals(tab_var_NT, tab_var);
    
    
    return 0;
}
