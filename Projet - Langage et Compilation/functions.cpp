//
//  functions.cpp
//  Projet - Langage et Compilation
//
//  Created by Daniel Regnard on 22/04/2017.
//  Copyright © 2017 A. All rights reserved.
//

#include "functions.hpp"


string choose_file() {  // fonction qui recupere le nom d'un fichier
    
    string name;
    
    cout << "ENTER THE NAME OF YOUR FILE : " << endl;
    cin >> name;
    
    string b(".txt");
    
    return name+b;
}


void show_all_rules (vector<Terminal> &tab_var) {
    
    for (int i = 0; i < tab_var.size(); i++) {
        
        if (tab_var[i].get_type() == 1) {
            tab_var[i].show_rules();
        }
    }
    
}



int loading (vector<Terminal> &tab_var) {
    
    string name_file = choose_file();   //on appelle la fonciton permettant au user de choisir le nom du fichier
    string data = "";
    int cpt = 0;

    ifstream myStream(name_file);   //ouverture du fichier
    

    if (myStream) {
        
        cout << "\nLecture fichier\n" << endl;
        
        while (myStream >> data) {  //on avance d'un mot dans le fichier
            
            Terminal tmp_NT;
            tmp_NT.set_name(data);
            tmp_NT.set_type(1);
            if (cpt == 0) {
                tmp_NT.set_axiome(true);
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
            
            tab_var.push_back(tmp_NT);
            
            cpt++;
        }
        
        cout << endl;
        
        show_all_rules(tab_var);
        
        return 1;
    } else {
        cout << "Erreur ouverture fichier" << endl;
        return 0;
    }
}






void create_non_terminals (vector<Non_terminal> &tab_NT, vector<Terminal> &tab_var) {
    
    for (int i = 0; i < tab_var.size(); i++) {
        for (int j = 0; i < tab_var[i].get_nb_rules(); i++) {
            tab_var[i].get_rule(j);
            //fonction pas encore fini
        }
    }
}








