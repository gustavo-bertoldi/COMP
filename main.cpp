#include "symbole.h"
#include "automate.h"
#include <iostream>

int main(int argc, char *argv[]) {
    bool verbose = false;
    if (argc > 1 && strcmp(argv[1], "-v") == 0) verbose = true;
    
    string exp;
    cout << "Entrez l'expression : ";
    getline(cin, exp);
    auto aut = new Automate(exp);
    aut -> setVerbose(verbose);
    aut -> evaluerChaine();
    delete aut;
    return 0;
}