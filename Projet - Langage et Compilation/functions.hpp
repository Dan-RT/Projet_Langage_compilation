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

#include "Variable.hpp"
#include "Terminal.h"
#include "Non_terminal.h"

int loading (vector<Non_terminal> &tab_var);
void show_all_rules (vector<Non_terminal> &tab_var);
void create_non_terminals (vector<Non_terminal> &tab_NT, vector<Terminal> &tab_var);



#endif /* functions_hpp */
