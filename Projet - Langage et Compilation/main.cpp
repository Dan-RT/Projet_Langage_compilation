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
    
    test.set_name("test");
    cout << test.get_name() << endl;
    
    
    vector<Variable> tab_var;
    
    loading(tab_var);
    
    
    
    
    
    return 0;
}
