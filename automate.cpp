#include "automate.h"

void Automate::decalage(Symbole *s, Etat *e) {
    symboles.push(s);
    etats.push(e);

    if (s -> isTerminal()) lexer -> Avancer();
}

void Automate::reduction(int n, Symbole *s) {
    //Verifier la suppression des elements avec delete
    for (int i = 0; i < n; i++) {
        symboles.pop();
        etats.pop();
    }

    // Verifier comment gerer les valeurs gauche
    symboles.push(new Expr());
    etats.top() -> transition(*this, s);
}