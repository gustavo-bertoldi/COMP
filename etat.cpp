#include "etat.h"
#include "automate.h"
#include <vector>
#include <iostream>

Etat::Etat(int nmr) : nmrEtat(nmr) {};
Etat::Etat(const Etat &e) { nmrEtat = e.nmrEtat; };
Etat::~Etat(){};
const string Etat::toString() const { return "E" + to_string(nmrEtat); };
ostream &operator<<(ostream &os, const Etat &e)
{
    return os << e.toString();
}

E0::E0() : Etat(0) {};
E0::~E0() {};
bool E0::transition(Automate &aut, Symbole *s) const {
    switch (*s) {
        case EXPR:
            aut.decalage(s, new E1());
            break;
        case OPENPAR:
            aut.decalage(s, new E2());
            break;
        case INT:
            aut.decalage(s, new E3());
            break;
        default:
            aut.decalage(new Erreur(), nullptr);
            return true;
    }
    return false;
};

E1::E1() : Etat(1) {};
E1::~E1() {};
bool E1::transition(Automate &aut, Symbole *s) const
{
    switch (*s) {
        case PLUS:
            aut.decalage(s, new E4());
            break;
        case MULT:
            aut.decalage(s, new E5());
            break;
        case FIN:
            return true;
        default:
            aut.decalage(new Erreur(), nullptr);
            return true;
    }
    return false;
};

E2::E2() : Etat(2) {};
E2::~E2() {};
bool E2::transition(Automate &aut, Symbole *s) const {
    switch (*s) {
        case EXPR:
            aut.decalage(s, new E6());
            break;
        case OPENPAR:
            aut.decalage(s, new E2());
            break;
        case INT:
            aut.decalage(s, new E3());
            break;
        default:
            aut.decalage(new Erreur(), nullptr);
            return true;
    }
    return false;
};

E3::E3() : Etat(3) {};
E3::~E3() {};
bool E3::transition(Automate &aut, Symbole *s) const {
    switch (*s) {
        case CLOSEPAR:
            aut.reduction(1, new Closepar());
            break;
        case PLUS:
            aut.reduction(1, new Plus());
            break;
        case MULT:
            aut.reduction(1, new Mult());
            break;
        case FIN:
            aut.reduction(1, new Fin());
            break;
        default:
            aut.decalage(new Erreur(), nullptr);
            return true;
    }
    delete s;
    return false;
};

E4::E4() : Etat(4) {};
E4::~E4() {};
bool E4::transition(Automate &aut, Symbole *s) const {
    switch (*s) {
        case EXPR:
            aut.decalage(s, new E7());
            break;
        case OPENPAR:
            aut.decalage(s, new E2());
            break;
        case INT:
            aut.decalage(s, new E3());
            break;
        default:
            aut.decalage(new Erreur(), nullptr);
            return true;
    }
    return false;
};

E5::E5() : Etat(5) {};
E5::~E5() {};
bool E5::transition(Automate &aut, Symbole *s) const {
    switch (*s) {
        case EXPR:
            aut.decalage(s, new E8());
            break;
        case OPENPAR:
            aut.decalage(s, new E2());
            break;
        case INT:
            aut.decalage(s, new E3());
            break;
        default:
            aut.decalage(new Erreur(), nullptr);
            return true;
    }
    return false;
};

E6::E6() : Etat(6) {};
E6::~E6() {};
bool E6::transition(Automate &aut, Symbole *s) const {
    switch (*s) {
        case CLOSEPAR:
            aut.decalage(s, new E9());
            break;
        case PLUS:
            aut.decalage(s, new E4());
            break;
        case MULT:
            aut.decalage(s, new E5());
            break;
        default:
            aut.decalage(new Erreur(), nullptr);
            return true;
    }
    return false;
};

E7::E7() : Etat(7) {};
E7::~E7() {};
bool E7::transition(Automate &aut, Symbole *s) const {
    switch (*s) {
        case CLOSEPAR:
            aut.reduction(3, new Closepar());
            delete s;
            break;
        case PLUS:
            aut.reduction(3, new Plus());
            delete s;
            break;
        case FIN:
            aut.reduction(3, new Fin());
            delete s;
            break;
        case MULT:
            aut.decalage(s, new E5());
            break;
        case INT:
            aut.decalage(s, new E3());
            break;
        default:
            aut.decalage(new Erreur(), nullptr);
            delete s;
            return true;
    }
    return false;
};

E8::E8() : Etat(8) {};
E8::~E8() {};
bool E8::transition(Automate &aut, Symbole *s) const {
    switch (*s) {
        case CLOSEPAR:
            aut.reduction(3, new Closepar());
            break;
        case PLUS:
            aut.reduction(3, new Plus());
            break;
        case MULT:
            aut.reduction(3, new Mult());
            break;
        case FIN:
            aut.reduction(3, new Fin());
            break;
        default:
            aut.decalage(new Erreur(), nullptr);
            return true;
    }
    delete s;
    return false;
};

E9::E9() : Etat(9) {};
E9::~E9() {};
bool E9::transition(Automate &aut, Symbole *s) const {
    switch (*s) {
        case CLOSEPAR:
            aut.reduction(3, new Closepar());
            break;
        case PLUS:
            aut.reduction(3, new Plus());
            break;
        case MULT:
            aut.reduction(3, new Mult());
            break;
        case FIN:
            aut.reduction(3, new Fin());
            break;
        default:
            aut.decalage(new Erreur(), nullptr);
            return true;
    }
    delete s;
    return false;
};