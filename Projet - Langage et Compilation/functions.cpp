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



int loading (vector<Variable> &tab_var) {
    
    string name_file = choose_file();
    
    ifstream myStream(name_file);
    
    int data = 0;
    char data_char;
    
    if (myStream) {
        
        cout << "Lecture fichier" << endl;
        
        for (int i = 0; i < 10; i++) {
            myStream >> data_char;
            
            myStream >> data;
            
        }
        
        
        return 1;
    } else {
        cout << "Erreur ouverture fichier" << endl;
        return 0;
    }
}


