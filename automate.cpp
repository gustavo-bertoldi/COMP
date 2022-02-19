#include "automate.h"
#include <queue>

void Automate::decalage(Symbole *s, Etat *e) {
    symboles.push(s);
    etats.push(e);

    //if (s -> isTerminal()) lexer -> Avancer();
}

void Automate::reduction(int n, Symbole *s) {
    queue<Symbole *> evaluer;

    //Verifier la suppression des elements avec delete
    for (int i = 0; i < n; i++) {
        evaluer.push(symboles.top());
        symboles.pop();
        etats.pop();
    }

    // Verifier comment gerer les valeurs gauche
    while (!evaluer.empty()) {
        Symbole courant = *(evaluer.front());
        switch (courant)
        {
        case OPENPAR:
            break;
        
        default:
            break;
        }
    }

    symboles.push(new Symbole(EXPR));
    etats.top() -> transition(*this, s);
}