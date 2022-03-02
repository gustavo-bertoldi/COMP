#pragma once

#include <string>
#include <stack>
#include <vector>
#include "symbole.h"
#include "etat.h"
#include "lexer.h"

using namespace std;

class Automate {
    public:
        Automate(string entree);
        virtual ~Automate();
        void evaluerChaine();
        void decalage(Symbole *s, Etat *e);
        void reduction(int n, Symbole *s);
        void enleverSymbole();
        const Symbole& dernierSymbole() const;
        //void lire();
        void afficherPiles() const;
        vector<Symbole *> * getSymbolesReduction() const;

    protected:
        string flux;
        stack<Symbole *> symboles;
        stack<Etat *> etats;
        vector<Symbole *> *symbolesReduction;
        Lexer *lexer;
};