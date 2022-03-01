#include "etat.h"
#include "automate.h"


bool E0 :: transition(Automate & automate, Symbole * s) {
    switch (*s){
        case EXPR:
            automate.decalage(s,new E1);
            break;
        case OPENPAR:
            automate.decalage(s,new E2);
            break; 
        case INT:
            automate.decalage(s,new E3);
            break;
        default:
            break;
    }
    return false;
 }

bool E1 :: transition(Automate & automate, Symbole * s) {
    switch (*s){
        case PLUS:
            automate.decalage(s,new E4);
            break;
        case MULT:
            automate.decalage(s,new E5);
            break;
        case FIN:
            return true;
            break;
        default:
            break;
    }
    return false;
}

bool E2 :: transition(Automate & automate, Symbole * s) {
    switch (*s){
        case EXPR:
            automate.decalage(s,new E6);
            break;
        case OPENPAR:
            automate.decalage(s,new E2);
            break;
        case INT:
            automate.decalage(s,new E3);
            break;
        default:
            break;
    }
    return false;
}

bool E3 :: transition(Automate & automate, Symbole * s) {
    int val;
    Expr* e = nullptr;
    switch (*s){
        case CLOSEPAR:
            e = (Expr *) automate.dernierSymbole(); 
            val = e->getValeur();
            automate.enleverSymbole();
            automate.reduction(1,new Expr(val));
            break; 
        case PLUS:
            e = (Expr *) automate.dernierSymbole(); 
            val = e->getValeur();
            automate.enleverSymbole();
            automate.reduction(1,new Expr(val));
            break;
        case MULT:
            e = (Expr *) automate.dernierSymbole(); 
            val = e->getValeur();
            automate.enleverSymbole();
            automate.reduction(1,new Expr(val));
            break;
        case FIN:
            e = (Expr *) automate.dernierSymbole(); 
            val = e->getValeur();
            automate.enleverSymbole();
            automate.reduction(1,new Expr(val));
            break;
        default:
            break;
    }
    delete(e);
    return false;
}

bool E4 :: transition(Automate & automate, Symbole * s) {
    switch (*s){
        case EXPR:
            automate.decalage(s,new E7);
            break;
        case OPENPAR:
            automate.decalage(s,new E2);
            break;
        case INT:
            automate.decalage(s,new E3);
            break;
        default:
            break;
    }
    return false;
}

bool E5 :: transition(Automate & automate, Symbole * s) {
    switch (*s){
        case EXPR:
            automate.decalage(s,new E8);
            break;
        case OPENPAR:
            automate.decalage(s,new E2);
            break;
        case INT:
            automate.decalage(s,new E3);
            break;
        default:
            break;
    }
    return false;
}

bool E6 :: transition(Automate & automate, Symbole * s) {
    switch (*s){
        case CLOSEPAR:
            automate.decalage(s,new E9);
            break;
        case PLUS:
            automate.decalage(s,new E4);
            break;
        case MULT:
            automate.decalage(s,new E5);
            break;
        default:
            break;
    }
    return false;
}

bool E7 :: transition(Automate & automate, Symbole * s) {
    Expr * s1 = nullptr;
    Expr * s2 = nullptr;
    int val;
    switch (*s){
        case CLOSEPAR:
            s1 = (Expr*) automate.dernierSymbole(); 
            automate.enleverSymbole();
            automate.enleverSymbole();
            s2 = (Expr*) automate.dernierSymbole();
            automate.enleverSymbole();
            val = s1->getValeur() + s2->getValeur();
            automate.reduction(3,new Expr(val));
            break;
        case PLUS:
            s1 = (Expr*) automate.dernierSymbole(); 
            automate.enleverSymbole();
            automate.enleverSymbole();
            s2 = (Expr*) automate.dernierSymbole();
            automate.enleverSymbole();
            val = s1->getValeur() + s2->getValeur();
            automate.reduction(3,new Expr(val));
            break;
        case MULT:
            automate.decalage(s,new E5);
            break;
        case INT:
        case FIN:
            s1 = (Expr*) automate.dernierSymbole(); 
            automate.enleverSymbole();
            automate.enleverSymbole();
            s2 = (Expr*) automate.dernierSymbole();
            automate.enleverSymbole();
            val = s1->getValeur() + s2->getValeur();
            automate.reduction(3,new Expr(val));
            break;
        default:
            break;
    }
    delete(s1);
    delete(s2);
    return false;
}

bool E8 :: transition(Automate & automate, Symbole * s) {
    Expr * s1 = nullptr;
    Expr * s2 = nullptr;
    int val;
    switch (*s){
        case CLOSEPAR:
            s1 = (Expr*) automate.dernierSymbole(); 
            automate.enleverSymbole();
            automate.enleverSymbole();
            s2 = (Expr*) automate.dernierSymbole();
            automate.enleverSymbole();
            val = s1->getValeur() * s2->getValeur();
            automate.reduction(3,new Expr(val));
            break;
        case PLUS:
            s1 = (Expr*) automate.dernierSymbole(); 
            automate.enleverSymbole();
            automate.enleverSymbole();
            s2 = (Expr*) automate.dernierSymbole();
            automate.enleverSymbole();
            val = s1->getValeur() * s2->getValeur();
            automate.reduction(3,new Expr(val));
            break;
        case MULT:
            s1 = (Expr*) automate.dernierSymbole(); 
            automate.enleverSymbole();
            automate.enleverSymbole();
            s2 = (Expr*) automate.dernierSymbole();
            automate.enleverSymbole();
            val = s1->getValeur() * s2->getValeur();
            automate.reduction(3,new Expr(val));
            break;
        case FIN:
            s1 = (Expr*) automate.dernierSymbole(); 
            automate.enleverSymbole();
            automate.enleverSymbole();
            s2 = (Expr*) automate.dernierSymbole();
            automate.enleverSymbole();
            val = s1->getValeur() * s2->getValeur();
            automate.reduction(3,new Expr(val));
            break;
        default:
            break;
    }
    delete(s1);
    delete(s2);
    return false;
}

bool E9 :: transition(Automate & automate, Symbole * s) {
    Expr * s1 = nullptr;
    int val;
    switch (*s){
        case CLOSEPAR: 
            automate.enleverSymbole();
            s1 = (Expr*) automate.dernierSymbole();
            automate.enleverSymbole();
            automate.enleverSymbole();
            val = s1->getValeur();
            automate.reduction(3,new Expr(val));
            break;
        case PLUS:
            automate.enleverSymbole();
            s1 = (Expr*) automate.dernierSymbole();
            automate.enleverSymbole();
            automate.enleverSymbole();
            val = s1->getValeur();
            automate.reduction(3,new Expr(val));
            break;
        case MULT:
            automate.enleverSymbole();
            s1 = (Expr*) automate.dernierSymbole();
            automate.enleverSymbole();
            automate.enleverSymbole();
            val = s1->getValeur();
            automate.reduction(3,new Expr(val));
            break;
        case FIN:
            automate.enleverSymbole();
            s1 = (Expr*) automate.dernierSymbole();
            automate.enleverSymbole();
            automate.enleverSymbole();
            val = s1->getValeur();
            automate.reduction(3,new Expr(val));
            break;
        default:
            break;
    }
    delete(s1);
    return false;
}