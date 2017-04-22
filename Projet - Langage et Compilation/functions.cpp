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


void show_all_rules (vector<Non_terminal> &tab_NT) {
    
    for (int i = 0; i < tab_NT.size(); i++) {
        
        if (tab_NT[i].get_type() == 1) {
            tab_NT[i].show_rules();
        }
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






void create_non_terminals (vector<Non_terminal> &tab_NT, vector<Terminal> &tab_var) {
    
    /*
     Ici on arrive à récupérer chaque règle mais il faut implémenter une façon de chercher dans chaque règles les caractères correspondant au noms des non terminaux, car des terminaux peuvent très bien s'y trouver. Utilisez pq pas les fonctions find() et replace() du C++
    */
    
    
    cout << "\n---Fonction création Non terminaux---\n" << endl;
    for (int i = 0; i < tab_var.size(); i++) {
        cout << "Var : " << tab_NT[i].get_name() << endl;
        for (int j = 0; j < tab_NT[i].get_nb_rules(); j++) {
            
            cout << tab_NT[i].get_rule(j) << endl;
            //fonction pas encore fini
            
        }
        cout << endl;
    }
    
}








