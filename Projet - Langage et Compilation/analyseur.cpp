//
//  analyseur.cpp
//  Projet - Langage et Compilation
//
//  Created by Daniel Regnard on 23/04/2017.
//  Copyright © 2017 A. All rights reserved.
//

#include "analyseur.hpp"

bool check_terminal_existence (string data, vector<string> tab_name_T);




void first(vector<Terminal> &tab_T, vector<Non_terminal> &tab_NT, vector<string> tab_name_NT, vector<string> tab_name_T) {
    
    cout << "---Fonction calcul des First---\n[Work in progress]\n" << endl;
    
    string rule_tested = "";
    
    char char_tmp;
    
    string string_tmp = "";
    
    
    
    for (int i = 0; i < tab_NT.size(); i++) {
        for (int j = 0; j < tab_NT[i].get_nb_rules(); j++) {
            rule_tested = tab_NT[i].get_rule(j);
            cout << "Rule tested : " << rule_tested << endl;
            
            
            for(int k = 0; k < rule_tested.size(); k++) {
                
                char_tmp = rule_tested[k];
                stringstream ss;
                ss << char_tmp;
                ss >> string_tmp;
                
                
                //on vérifie si c'est terminal ou pas
                if (check_terminal_existence(string_tmp, tab_name_T) == true) {
                    
                    cout << "Adding " << string_tmp << " to First of " << tab_NT[i].get_name() << endl;
                    
                    tab_NT[i].set_tab_first(char_tmp);
                    //ici on manipule des char et non plus des string, voir dans le futur ce qui est le mieux
                }
            }
        }
        cout << endl;
        tab_NT[i].show_tab_first();
    }
}






