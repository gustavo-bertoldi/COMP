#include <iostream>
#include "lexer.h"


int main(void) {
   string chaine("(1+34)*123");

   Lexer l(chaine);

   Symbole * s;
   //Verifier Consulter() != ERREUR
   while( * (s = l.Consulter()) != FIN ) {
      s -> Affiche();
      cout << endl;
      l.Avancer();
   }
   return 0;
}

