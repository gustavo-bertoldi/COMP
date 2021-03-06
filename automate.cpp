#include "automate.h"
#include <iostream>
#include <vector>
#include <algorithm>

Automate::Automate(string entree) : verbose(false) {
    //Enleve les espaces de l'entrée
    string entreeFiltree = "";
    for (const char &c : entree) {
        if (c != ' ') entreeFiltree += c;
    }
    flux = entreeFiltree;
    lexer = new Lexer(flux);
    etats.push_back(new E0());
    afficherPiles();
}

Automate::~Automate() {
    delete lexer;
    for (Etat* e : etats) {
        delete e;
    }
    for (Symbole *s: symboles) {
        delete s;
    }
};

void Automate::evaluerChaine() {
    bool fini = false;
    while (!fini) {
        Symbole *s = lexer -> Consulter();
        lexer -> Avancer();
        fini = etats.back()->transition(*this, s);
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
            int val1 = ((Expr *)(red->at(2)))->getValeur();
            int val2 = ((Expr *)(red->at(0)))->getValeur();
            if (*(red -> at(1)) == PLUS) {
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

void Automate::afficherPiles() const {
    if (verbose) {
        cout << "============" << endl << "Pile symboles: ";
        for (Symbole *s : symboles) {
            if (s) {
                cout << *s;
                if (s != symboles.back()) cout << ", ";
            }
        }

        cout << endl << "Pile etats: ";
        for (Etat *e : etats)
        {
            if (e) {
                cout << *e;
                if (e != etats.back()) cout << ", ";
            }
        }
        cout << endl << "============" << endl;
    }
}

void Automate::setVerbose(bool v) { verbose = v; };