#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   string chaine("(1+34)*123");
   /*
   Lexer l(chaine);

   Symbole * s;

   while( * (s = l.Consulter()) != FIN ) {
      s -> Affiche();
      cout << endl;
      l.Avancer();
   }*/

   Automate * a = new Automate(chaine);
   a->evaluerChaine();

   return 0;
}

