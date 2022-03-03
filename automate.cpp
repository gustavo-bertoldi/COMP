#include "automate.h"
#include <iostream>
#include <vector>

Automate::Automate(string entree) : flux(entree) {
    lexer = new Lexer(flux);
    etats.push_back(new E0());
    afficherPiles();
}

Automate::~Automate() {};

void Automate::evaluerChaine() {
    Symbole *s = nullptr;
    while (*(s = lexer -> Consulter()) != FIN) {
        lexer -> Avancer();
        etats.back() -> transition(*this, s);
    }

    if (*symboles.back() != ERREUR) {
        Expr *e = (Expr *)symboles.back();
        cout << "Resultat : " << e -> getValeur() << endl;
    } else {
        cout << "Syntaxe inconnue" << endl;
    }
}

void Automate::decalage(Symbole *s, Etat *e) {
    symboles.push_back(s);
    etats.push_back(e);
    afficherPiles();
}

void Automate::reduction(int n, Symbole *s) {
    vector<Symbole *> *red = new vector<Symbole *>();
    for (int i = 0; i < n; i++) {
        etats.pop_back();
        red -> push_back(symboles.back());
        symboles.pop_back();
    }
    afficherPiles();
    
    int val = -1;
    if (n == 1) {
        val = ((Int *)(red -> back())) -> getValeur();
    } else if (n == 3) {
        if (*(red -> back()) == OPENPAR) {
            //Cas (E)
            val = ((Expr *)(red -> at(1)))->getValeur();
        } else {
            //Cas E+E || E*E
            int val1 = ((Expr *)(red->at(0)))->getValeur();
            int val2 = ((Expr *)(red->at(2)))->getValeur();
            if (*(red -> back()) == PLUS) {
                //Cas E+E
                val = val1 + val2;
            } else {
                //Cas E*E
                val = val1 * val2;
            }
        }
    }
    lexer->putSymbol(s);
    etats.back()->transition(*this, new Expr(val));
    
}

const Symbole& Automate::dernierSymbole() const { return *symboles.back(); };

void Automate::afficherPiles() const {

    cout << "============" << endl << "Pile symboles: ";
    for (Symbole *s : symboles) {
        cout << *s;
        if (s != symboles.back()) cout << ", ";
    }

    cout << endl << "Pile etats: ";
    for (Etat *e : etats)
    {
        cout << *e;
        if (e != etats.back()) cout << ", ";
    }
    cout << endl << "============" << endl;
}