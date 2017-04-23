//
//  analyseur.hpp
//  Projet - Langage et Compilation
//
//  Created by Daniel Regnard on 23/04/2017.
//  Copyright © 2017 A. All rights reserved.
//

#ifndef analyseur_hpp
#define analyseur_hpp

#include <stdio.h>
#include <sstream>
#include <string>

#include "Variable.hpp"
#include "Terminal.h"
#include "Non_terminal.h"


void first(vector<Terminal> &tab_T, vector<Non_terminal> &tab_NT, vector<string> tab_name_NT, vector<string> tab_name_T);






#endif /* analyseur_hpp */
