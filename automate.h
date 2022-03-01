#pragma once

#include <string>
#include <stack>
#include "symbole.h"
#include "lexer.h"
#include "etat.h"
using namespace std;

class Automate {

   public:
      Automate(string fl);
      virtual ~Automate() {};
      void evaluerChaine();
      void decalage(Symbole *s, Etat *e);
      void reduction(int n, Symbole *s);
      void enleverSymbole();
      Symbole * dernierSymbole();
      void lire();

   protected:
      string flux;
      stack<Symbole *> symboles;
      stack<Etat *> etats;
      Lexer *lexer;
};
