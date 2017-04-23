#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "Variable.hpp"
#include "Terminal.h"
#include "Non_terminal.h"
#include "initial_functions.hpp"
#include "analyseur.hpp"

using namespace std;

int main() {
    
    /*
     
     On a besoin de tableaux pour les :
        - Non-Terminaux (NT)
        - Terminaux (T)
        - Les noms de NT
        - Les noms des T
     
     On charge depuis le fichier où ça crée les NT et où ça enregistre les règles (rules), puis depuis ces rules on crée les différents T. Et après bah on affiche tout oklm
     
     Il n'est pas indispensable de comprendre comment on fait tout ça, par contre il est indispensable de lire les classes Terminal et Non_Terminal, qui héritent de la classe Variable
     
     */
    
    
    vector<Terminal> tab_T;
    vector<Non_terminal> tab_NT;
    vector<string> tab_name_NT, tab_name_T;

    loading(tab_NT);
    
    show_all_rules(tab_NT);
    
    create_terminals(tab_NT, tab_T, tab_name_NT, tab_name_T);
    
    show_all_terminals(tab_T);
    show_all_non_terminals(tab_NT);
    
    first(tab_T, tab_NT, tab_name_NT, tab_name_T);
    
    return 0;
}












