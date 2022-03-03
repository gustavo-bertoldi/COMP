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
        void afficherPiles() const;

    protected:
        string flux;
        vector<Symbole *> symboles;
        vector<Etat *> etats;
        Lexer *lexer;
};