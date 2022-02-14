#include "etat.h"
#include "symbole.h"

bool E0 :: transition(Automate & automate, Symbole * s) {
    switch (*s){
        case EXPR:
            automate.decalage(s,new E1);
            break;
        case OPENPAR:
            automate.decalage(s,new E2);
            break; 
        case CLOSEPAR: 
        case PLUS:
        case MULT:
        case INT:
            automate.decalage(s,new E3);
            break;
        case FIN:
        case ERREUR:
            break;
    }
    return false;
 }

bool E1 :: transition(Automate & automate, Symbole * s) {
    switch (*s){
        case EXPR:
        case OPENPAR:
        case CLOSEPAR: 
        case PLUS:
            automate.decalage(s,new E4);
            break;
        case MULT:
            automate.decalage(s,new E5);
            break;
        case INT:
        case FIN:
        //ver o que fazer aqui 
        case ERREUR:
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
        case CLOSEPAR: 
        case PLUS:
        case MULT:
        case INT:
            automate.decalage(s,new E3);
            break;
        case FIN:
        case ERREUR:
        break;
    }
    return false;
}

bool E3 :: transition(Automate & automate, Symbole * s) {
    switch (*s){
        case EXPR:
        case OPENPAR:
        case CLOSEPAR:
            automate.reduction(1,s);
            break; 
        case PLUS:
            automate.reduction(1,s);
            break;
        case MULT:
            automate.reduction(1,s);
            break;
        case INT:
        case FIN:
            automate.reduction(1,s);
            break;
        case ERREUR:
        break;
    }
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
        case CLOSEPAR:
        case PLUS:
        case MULT:
        case INT:
            automate.decalage(s,new E3);
            break;
        case FIN:
        case ERREUR:
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
        case CLOSEPAR:
        case PLUS:
        case MULT:
        case INT:
            automate.decalage(s,new E3);
            break;
        case FIN:
        case ERREUR:
        break;
    }
    return false;
}

bool E6 :: transition(Automate & automate, Symbole * s) {
    switch (*s){
        case EXPR:
        case OPENPAR:
        case CLOSEPAR:
            automate.decalage(s,new E9);
            break;
        case PLUS:
            automate.decalage(s,new E4);
            break;
        case MULT:
            automate.decalage(s,new E5);
            break;
        case INT:
        case FIN:
        case ERREUR:
        break;
    }
    return false;
}

bool E7 :: transition(Automate & automate, Symbole * s) {
    switch (*s){
        case EXPR:
        case OPENPAR:
        case CLOSEPAR:
            automate.reduction(3,s);
            break;
        case PLUS:
            automate.reduction(3,s);
            break;
        case MULT:
            automate.decalage(s,new E5);
            break;
        case INT:
        case FIN:
            automate.reduction(3,s);
            break;
        case ERREUR:
        break;
    }
    return false;
}

bool E8 :: transition(Automate & automate, Symbole * s) {
    switch (*s){
        case EXPR:
        case OPENPAR:
        case CLOSEPAR:
            automate.reduction(3,s);
            break;
        case PLUS:
            automate.reduction(3,s);
            break;
        case MULT:
            automate.reduction(3,s);
            break;
        case INT:
        case FIN:
            automate.reduction(3,s);
            break;
        case ERREUR:
        break;
    }
    return false;
}

bool E9 :: transition(Automate & automate, Symbole * s) {
    switch (*s){
        case EXPR:
        case OPENPAR:
        case CLOSEPAR:
            automate.reduction(3,s);
            break;
        case PLUS:
            automate.reduction(3,s);
            break;
        case MULT:
            automate.reduction(3,s);
            break;
        case INT:
        case FIN:
            automate.reduction(3,s);
            break;
        case ERREUR:
        break;
    }
    return false;
}