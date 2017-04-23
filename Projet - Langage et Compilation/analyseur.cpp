//
//  analyseur.cpp
//  Projet - Langage et Compilation
//
//  Created by Daniel Regnard on 23/04/2017.
//  Copyright © 2017 A. All rights reserved.
//

#include "analyseur.hpp"

bool check_terminal_existence (string data, vector<string> tab_name_T);


struct NT_couple {
    int X;
    int Y;
};

int get_indice_NT (vector<Non_terminal> &tab_NT, vector<string> tab_name_NT, string data) {
    
    for (int i = 0; i < tab_name_NT.size(); i++) {
        if (tab_NT[i].get_name() == data) {
            return i;
        }
    }
    
    cout << "Error in analyseur.hpp/get_indice_NT, name of terminal not found" << endl;
    exit(0);
    return 0;
}

int get_type (vector<Terminal> &tab_T, vector<Non_terminal> &tab_NT, vector<string> tab_name_NT, vector<string> tab_name_T, string data) {
 
    for (int i = 0; i < tab_name_T.size(); i++) {
        if (tab_T[i].get_name() == data) {
            return tab_T[i].get_type();
        }
    }
    
    for (int i = 0; i < tab_name_NT.size(); i++) {
        if (tab_NT[i].get_name() == data) {
            return tab_NT[i].get_type();
        }
    }
    return 0;
}




void first(vector<Terminal> &tab_T, vector<Non_terminal> &tab_NT, vector<string> tab_name_NT, vector<string> tab_name_T) {
    
    cout << "\n\n---Fonction calcul des First---\n[Work in progress]\n" << endl;
    
    for (int i = 0; i < tab_T.size(); i++) {
        tab_T[i].show_tab_first();
    }
    
    
    string rule_tested = "";
    char char_tmp;
    string string_tmp = "";
    vector<NT_couple> tab_NT_tmp;
    
    
    for (int i = 0; i < tab_NT.size(); i++) {
        for (int j = 0; j < tab_NT[i].get_nb_rules(); j++) {
            rule_tested = tab_NT[i].get_rule(j);
            //cout << "Rule tested : " << rule_tested << endl;
            
            
            for(int k = 0; k < rule_tested.size(); k++) {
                
                char_tmp = rule_tested[k];
                stringstream ss;
                ss << char_tmp;
                ss >> string_tmp;
                
                
                if (string_tmp == "#" && rule_tested.size() == 1) {
                    //on vérifie si on tombe pas sur #, et si c'est bien une production
                    cout << "Adding final symbol " << string_tmp << " to First of " << tab_NT[i].get_name() << endl;
                    tab_NT[i].set_tab_first(string_tmp);
                }
                
                //if (rule_tested.size() > 1) {
                    // > ou >= 1 ?
                
                if (tab_NT[i].contains_final_sign() == false) {
                    //First(Y1Y2..Yk) is First(Y1) if First(Y1) doesn't contain #
                    
                    if (get_type(tab_T, tab_NT, tab_name_NT, tab_name_T, string_tmp) == 1) {
                        //on regarde le type de ce qu'on manipule, là on veut un T
                        
                        if (tab_NT[i].contains_precised_sign_first(string_tmp) == false) {
                            tab_NT[i].set_tab_first(string_tmp);
                            cout << "Adding symbol " << string_tmp << " to First of " << tab_NT[i].get_name() << endl;
                            k = (int)rule_tested.size(); //nous permet de sortir de la boucle for k
                        }
                        
                    } else {
                        //on récupère tous les first de la var NT pour les ajouter au first à notre var tab_NT[i]
                        
                        int tmp = get_indice_NT(tab_NT, tab_name_NT, string_tmp);
                        
                        NT_couple help;
                        help.X = i;
                        help.Y = tmp;
                        tab_NT_tmp.push_back(help);
                        
                        /*for (int l = 0; l < tab_NT[tmp].get_nb_first(); l++) {
                            
                            if(tab_NT[i].contains_precised_sign_first(tab_NT[tmp].get_first(l)) == false) {
                                tab_NT[i].set_tab_first(string_tmp);
                            }
                        }*/
                        k = (int)rule_tested.size(); //nous permet de sortir de la boucle for k
                    }
                } else {
                    
                }
            }
        }
        cout << endl;
        tab_NT[i].show_tab_first();
    }
    
    int j = 0, i = 0, tmp = 0, flag = 0;
    
    while (tab_NT_tmp.size() > 0) {
        
        i = tab_NT_tmp[j].X;
        tmp = tab_NT_tmp[j].Y;
        
        for (int l = 0; l < tab_NT[tmp].get_nb_first(); l++) {
            
            if(tab_NT[i].contains_precised_sign_first(tab_NT[tmp].get_first(l)) == false) {
                tab_NT[i].set_tab_first(tab_NT[tmp].get_first(l));
                tab_NT[i].show_tab_first();
                //l = tab_NT[tmp].get_nb_first();
            }
            flag = 1;
        }
        
        if (flag == 1) {
            tab_NT_tmp.erase(tab_NT_tmp.begin()+j);
            flag = 0;
            j = 0;
        } else {
            j++;
        }
        
    }
    
    cout << "\n\n---Fin fonction calcul des First---\n\n" << endl;
}






