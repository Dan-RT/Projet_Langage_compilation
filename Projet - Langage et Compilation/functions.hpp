//
//  functions.hpp
//  Projet - Langage et Compilation
//
//  Created by Daniel Regnard on 22/04/2017.
//  Copyright © 2017 A. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include <sstream>
#include <string>

#include "Variable.hpp"
#include "Terminal.h"
#include "Non_terminal.h"

int loading (vector<Non_terminal> &tab_var);
void show_all_rules (vector<Non_terminal> &tab_var);
void create_terminals (vector<Non_terminal> &tab_NT, vector<Terminal> &tab_var_T, vector<string> tab_name_NT, vector<string> tab_name_T);
void show_all_terminals (vector<Terminal> tab_T);
void show_all_non_terminals (vector<Non_terminal> tab_NT);


#endif /* functions_hpp */
