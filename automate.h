#pragma once

#include <string>
#include "symbole.h"
#include "etat.h"
#include <stack>
#include "lexer.h"
using namespace std;

class Automate {

   public:
      Automate(string fl) : flux(fl) { };
      virtual ~Automate();
      void decalage(Symbole *s, Etat *e);
      void reduction(int n, Symbole *s);

   protected:
      string flux;
      stack<Symbole *> symboles;
      stack<Etat *> etats;
      Lexer *lexer;
};
