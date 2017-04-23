//
//  functions.cpp
//  Projet - Langage et Compilation
//
//  Created by Daniel Regnard on 22/04/2017.
//  Copyright © 2017 A. All rights reserved.
//

#include "initial_functions.hpp"


string choose_file() {  //fonction qui recupere le nom d'un fichier auprès du user
    
    string name;
    
    cout << "ENTER THE NAME OF YOUR FILE : " << endl;
    cin >> name;
    
    string b(".txt");
    
    return name+b;
}



                /*      Affichage       */

void show_all_rules (vector<Non_terminal> &tab_NT) {
    
    for (int i = 0; i < tab_NT.size(); i++) {
        
        if (tab_NT[i].get_type() == 1) {
            tab_NT[i].show_rules();
        }
    }
}

void show_all_terminals (vector<Terminal> tab_T) {
    
    cout << "Terminals : " << endl;
    for (int i = 0; i < tab_T.size(); i++) {
        cout << tab_T[i].get_name() << endl;
    }
}

void show_all_non_terminals (vector<Non_terminal> tab_NT) {
    
    cout << "Non terminals : " << endl;
    for (int i = 0; i < tab_NT.size(); i++) {
        cout << tab_NT[i].get_name() << endl;
    }
}





int loading (vector<Non_terminal> &tab_NT) {
    
    string name_file = choose_file();   //on appelle la fonciton permettant au user de choisir le nom du fichier
    string data = "";
    int cpt = 0;

    ifstream myStream(name_file);   //ouverture du fichier
    

    if (myStream) {
        
        cout << "\nLecture fichier\n" << endl;
        
        while (myStream >> data) {  //on avance d'un mot dans le fichier
            
            Non_terminal tmp_NT;
            tmp_NT.set_name(data);
            tmp_NT.set_type(1);
            if (cpt == 0) {
                tmp_NT.set_axiome(true);
                cpt++;
            } else {
                tmp_NT.set_axiome(false);
            }
            cout << data;
            
            while (data != "$") {
                
                if (data == "=" || data == "|") {
                    
                    cout << data;
                    myStream >> data;
                    
                    if (data != "#") {
                        tmp_NT.add_rules(data);
                        cout << data;
                    } else {
                        cout << data;
                    }
                    
                } else {
                    myStream >> data;
                }
            }
            cout << endl;
            
            tab_NT.push_back(tmp_NT);
            
            
        }
        cpt++;
        
        cout << endl;
        
        
        
        
        return 1;
    } else {
        cout << "Erreur ouverture fichier" << endl;
        return 0;
    }
}



void get_name_NT (vector<Non_terminal> &tab_NT, vector<string> &tab_name) {
    
    for (int i = 0; i < tab_NT.size(); i++) {
        tab_name.push_back(tab_NT[i].get_name());
    }
}



bool check_terminal_existence (string data, vector<string> tab_name_T) {
    
//fonction regardant si un terminal existe déjà pour un nom donné ou non, histoire qu'on ne le crée pas deux fois
    
    for (int i = 0; i < tab_name_T.size(); i++) {
        if (tab_name_T[i] == data) {
            return true;
        }
    }
    return false;
}


void create_terminals (vector<Non_terminal> &tab_NT, vector<Terminal> &tab_var_T, vector<string> &tab_name_NT, vector<string> &tab_name_T) {
    
    get_name_NT(tab_NT, tab_name_NT);
    
    string rule_tested = "";
    
    
    /*
     
     - Prendre chaque variable
        - Regarder ses règles
            - Chercher si le nom de chaque non terminaux est dedans
            - Si oui le/les supprimer
                - Checker si on a affaire à un ou plusieurs Terminal à ajouter
                    - Si c'est le cas on les sépare
                - Ajouter comme Terminal
     
     */
    
    cout << "\n---Fonction création Terminaux---\n" << endl;
    
    for (int i = 0; i < tab_NT.size(); i++) {
        cout << "Var : " << tab_NT[i].get_name() << endl;
        for (int j = 0; j < tab_NT[i].get_nb_rules(); j++) {
            
            rule_tested = tab_NT[i].get_rule(j);
            
            cout << "Rule tested : " << rule_tested << endl;
            
            for (int k = 0; k < tab_name_NT.size(); k++) {
                
                
                //Ici on recherche les éventuels NT se mêlant aux T dans les règles
                
                size_t found = rule_tested.find(tab_name_NT[k]);
                
                if (found!=std::string::npos) {
                    cout << tab_name_NT[k] << " found at: " << found << endl;
                    rule_tested.erase(rule_tested.begin()+found);
                    cout << "New rule : " << rule_tested << endl;
                }
                
                
                
                
                if (k == tab_name_NT.size()-1) {
                    
                    //on vérifie avant d'ajouter que le T n'est pas en réalité plusieurs T, si oui on les sépare
                    
                    if (rule_tested.size() > 1) {
                        
                        cout << "Taille de la rule_tested > 1" << endl;
                        
                        for (int l = 0; l < rule_tested.size(); l++) {
                            
                            char char_tmp = rule_tested[l];
                            stringstream ss;
                            string string_tmp = "";
                            ss << char_tmp;
                            ss >> string_tmp;
                            
                            if (check_terminal_existence(string_tmp, tab_name_T) != true) {
                                cout << "Adding " << string_tmp << " to tab_name_T" << endl;
                                Terminal var_t;
                                tab_name_T.push_back(string_tmp);
                                var_t.set_name(string_tmp);
                                tab_var_T.push_back(var_t);
                            }
                        }
                    } else {
                        
                        //on vérifie avant d'ajouter que le T n'est pas vide et qu'il n'existe pas déjà dans le tableau
                        
                        if ((rule_tested != "") && (check_terminal_existence(rule_tested, tab_name_T) != true)) {
                            cout << "Adding " << rule_tested << " to tab_name_T" << endl;
                            Terminal var_t;
                            tab_name_T.push_back(rule_tested);
                            var_t.set_name(rule_tested);
                            tab_var_T.push_back(var_t);
                        }
                    }
                    
                    
                }
            }
        }
        cout << endl;
    }
    
}








