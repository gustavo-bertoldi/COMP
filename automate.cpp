#include "automate.h"
#include <queue>
#include <algorithm>
#include <iostream>
#include <deque>

Automate::Automate(string chaine) {
  flux = chaine;  
  this->lexer = new Lexer(chaine);
  Etat * depart = new E0();
  etats.push(depart);
}

void Automate::evaluerChaine(){
  Symbole * s = nullptr;

  while( * (s = lexer->Consulter()) != FIN ) {
      //s -> Affiche();
      cout << endl;
      lexer->Avancer();
      etats.top()->transition(*this, s);

   }

  if (*symboles.top() != ERREUR) {
    Expr *  e = (Expr *)symboles.top();
    int resultat = e->getValeur();
    cout << "Syntaxe correct" << endl << "Résultat : " << resultat << endl;
  } else {
    cout << "Syntaxe non reconnu : caractere invalide" << endl;
  }

} 



void Automate::decalage(Symbole *s, Etat *e) {
    symboles.push(s);
    etats.push(e);
    cout<<"Decalage"<<endl;
    s->Affiche();
    afficherPiles();
}

/*void Automate::reduction(int n, Symbole *s) {
    queue<Symbole *> evaluer;

    //Verifier la suppression des elements avec delete
    for (int i = 0; i < n; i++) {
        evaluer.push(symboles.top());
        symboles.pop();
        etats.pop();
    }

    Symbole * val;
    if (n == 1) {
        val = evaluer.back();
    }

    while (!evaluer.empty()) {
        Symbole * courant = evaluer.front();

    }

    symboles.push(new Symbole(EXPR));
    etats.top() -> transition(*this, s);
}*/

void Automate::reduction(int n,Symbole * s) {
    for (int i=0;i<n;i++){
        etats.pop();
    }
    //coloca a expressao calculada no topo da pilha
    etats.top()->transition(*this,s);
    cout<<"Reduction"<<endl;
    s->Affiche();
    lexer->Avancer();
    afficherPiles();
 }

void Automate::afficherPiles() {
    stack<Symbole *> tmpSym(symboles);
    stack<Etat *> tmpEt(etats);
    cout << "Etats: [";
    while (!tmpEt.empty())
    {
        cout << tmpEt.top()->print() << ", ";
        tmpEt.pop();
    }
    cout << "]" << endl << "Symboles: [";
    while (!tmpSym.empty())
    {
        cout << tmpSym.top()->getEtiquette() << ", ";
        tmpSym.pop();
    }
    cout << "]" << endl;
}

Symbole * Automate::dernierSymbole(){
    return symboles.top();
}

void Automate::enleverSymbole(){
    symboles.pop();
}
