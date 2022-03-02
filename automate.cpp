#include "automate.h"
#include <iostream>
#include <vector>

Automate::Automate(string entree) : flux(entree) {
    lexer = new Lexer(flux);
    etats.push(new E0());
}

Automate::~Automate() {};

void Automate::evaluerChaine() {
    Symbole *s = nullptr;
    while (*(s = lexer -> Consulter()) != FIN) {
        lexer -> Avancer();
        etats.top() -> transition(*this, s);
    }

    if (*symboles.top() != ERREUR) {
        Expr *e = (Expr *)symboles.top();
        cout << "Resultat : " << e -> getValeur() << endl;
    } else {
        cout << "Syntaxe inconnue" << endl;
    }
}

void Automate::decalage(Symbole *s, Etat *e) {
    symboles.push(s);
    etats.push(e);
    afficherPiles();
}

void Automate::reduction(int n, Symbole *s) {
    cout << "Reduction" << endl;
    stack<Symbole *> *red = new stack<Symbole *>();
    for (int i = 0; i < n; i++) {
        etats.pop();
        red -> push(symboles.top());
        symboles.pop();
    }

    int val = -1;
    if (n == 1) {
        val = ((Int *)(red -> top())) -> getValeur();
    } else if (n == 3) {
        if (*(red -> top()) == OPENPAR) {
            //Cas (E)
            red -> pop();
            val = ((Expr *)(red->top()))->getValeur();
        } else {
            //Cas E+E || E*E
            int val1 = ((Expr *)(red->top()))->getValeur();
            red -> pop();
            if (*(red -> top()) == PLUS) {
                //Cas E+E
                red->pop();
                val = val1 + ((Expr *)(red->top()))->getValeur();
            } else {
                //Cas E*E
                red->pop();
                val = val1 * ((Expr *)(red->top()))->getValeur();
            }
        }
    }
    afficherPiles();
    etats.top()->transition(*this, new Expr(val));
    lexer->putSymbol(s);
}

const Symbole& Automate::dernierSymbole() const { return *symboles.top(); };
vector<Symbole *> * Automate::getSymbolesReduction() const {
     return symbolesReduction; 
};

void Automate::afficherPiles() const {
    stack<Symbole *> *tmpSym = new stack<Symbole *>(symboles);
    stack<Etat *> *tmpEt = new stack<Etat *>(etats);

    cout << "============" << endl << "Pile symboles: ";
    for (int i = 0; i < symboles.size(); i++) {
        cout << *(tmpSym -> top()) << ", ";
        tmpSym -> pop();
    }
    cout << endl << "Pile etats: ";
    for (int i = 0; i < etats.size(); i++)
    {
        cout << *(tmpEt->top()) << ", ";
        tmpEt->pop();
    }
    cout << endl << "============" << endl;

    delete tmpSym;
    delete tmpEt;
}