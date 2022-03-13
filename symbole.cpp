#include <iostream>
#include "symbole.h"

Symbole::Symbole(int id) : id(id) {};
Symbole::Symbole(const Symbole &s) { id = s.id; };
Symbole::~Symbole() {};
Symbole::operator int() const { return id; };
const string Symbole::toString() const { return etiquettes[id]; };
ostream &operator<<(ostream &os, const Symbole &s) {
    return os << s.toString();
}

Openpar::Openpar() : Symbole(OPENPAR) {};
Openpar::~Openpar() {};

Closepar::Closepar() : Symbole(CLOSEPAR) {};
Closepar::~Closepar() {};

Plus::Plus() : Symbole(PLUS) {};
Plus::~Plus() {};

Mult::Mult() : Symbole(MULT) {};
Mult::~Mult() {};
 
Int::Int(int val) : Symbole(INT), valeur(val) {};
Int::~Int() {};
int Int::getValeur() const { return valeur; };
const string Int::toString() const {
    const string str = etiquettes[id] + "(" + to_string(valeur) + ")";
    return str;
};

Fin::Fin() : Symbole(FIN) {};
Fin::~Fin() {};

Erreur::Erreur() : Symbole(ERREUR) {};
Erreur::~Erreur() {};

Expr::Expr() : Symbole(EXPR), valeur(-1) {};
Expr::Expr(int valeur) : Symbole(EXPR), valeur(valeur) {};
Expr::Expr(const Expr &s) : Symbole(EXPR) { valeur = s.valeur; };
Expr::~Expr() {};
const string Expr::toString() const {
    const string str = etiquettes[id] + "(" + to_string(valeur) + ")";
    return str;
};
int Expr::getValeur() const { return valeur; };