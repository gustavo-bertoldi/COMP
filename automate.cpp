#include "automate.h"

void Automate::decalage(Symbole *s, Etat *e) {
    symboles.push(s);
    etats.push(e);

    if (s -> isTerminal()) lexer -> Avancer();
}