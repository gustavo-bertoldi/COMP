#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   string chaine("(1+1)");

   Automate * a = new Automate(chaine);
   a->evaluerChaine();

   return 0;
}

