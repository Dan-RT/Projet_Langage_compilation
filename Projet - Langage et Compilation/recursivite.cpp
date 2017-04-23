//
//  recursivite.cpp
//  Projet - Langage et Compilation
//
//  Created by Daniel Regnard on 23/04/2017.
//  Copyright © 2017 A. All rights reserved.
//

#include "recursivite.hpp"


void delete_recursive (vector<Non_terminal> &tab_NT, vector<string> &tab_name_NT) {
    
    string rule = "", rule_0 = "", new_name = "", rule_new_var = "";
    int size = (int)tab_name_NT.size();
    char char_tmp;
    
    
    cout << "\n---Fonction elimination de la recursivite---\n" << endl;
    
    for (int i = 0; i < size; i++) {
        
        for (int j = 0; j < tab_NT[i].get_nb_rules(); j++) {
            rule = tab_NT[i].get_rule(j);
            
            char_tmp = rule[0];
            stringstream ss;
            ss << char_tmp;
            ss >> rule_0;
            
            //si il y a le nom de la var tout à gauche de la règle
            if (rule_0 == tab_name_NT[i]) {
                
                cout << "Recurvisity found for var " << tab_name_NT[i] <<"\n" << endl;
                
                //on trouve un nom
                new_name = tab_name_NT[i];
                transform(new_name.begin(), new_name.end(), new_name.begin(), ::tolower);
                tab_name_NT.push_back(new_name);
                
                //on crée une nouvelle variable
                Non_terminal new_var_NT;
                cout << "New Var " << new_name << " created" << endl;
                new_var_NT.set_name(new_name);
                
                //on copie la règle avec la récursivité
                rule_new_var = tab_NT[i].get_rule(j) + new_name;
                rule_new_var.erase(rule_new_var.begin()+0);
                new_var_NT.add_rules(rule_new_var);
                new_var_NT.set_axiome(false);
                
                //on ajoute le symbole finale comme règle de la nouvelle variable
                new_var_NT.add_rules("#");
                cout << "Rules : " << rule_new_var << " #\n" << endl;
                
                //on ajoute la nouvelle variable au tableau de variable
                tab_NT.push_back(new_var_NT);
                
                //on supprime la règle de la variable initial
                tab_NT[i].delete_rule(j);
                
                for (int k = 0; k < tab_NT[i].get_nb_rules(); k++) {
                    //on ajoute à chaque règle de la var initial le nom de la nouvelle
                    rule = tab_NT[i].get_rule(k);
                    rule = rule + new_name;
                    tab_NT[i].modify_rule(k, rule);
                    cout << "New rule " << rule << " for var " << tab_name_NT[i] << "\n" << endl;
                }
            }
            
            //tab_NT[i].show_rules();
        }
    }
    
    cout << "\n---Fin fonction elimination de la recursivite---\n\n" << endl;
    
}



