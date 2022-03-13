#pragma once

#include <string>

using namespace std;

enum identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };
const static string etiquettes[] = { "(", ")", "+", "*", "int", "fin",
    "ERREUR", "EXP" };

class Symbole {
    public:
        Symbole(int i);
        Symbole(const Symbole &s);
        virtual ~Symbole();
        operator int() const;
        friend ostream &operator<<(ostream &os, const Symbole &s);

    protected:
        int id;
        virtual const string toString() const;
};

class Openpar : public Symbole {
    public:
        Openpar();
        virtual ~Openpar();
};

class Closepar : public Symbole {
    public:
        Closepar();
        virtual ~Closepar();
};

class Plus : public Symbole {
    public:
        Plus();
        virtual ~Plus();
};

class Mult : public Symbole {
    public:
        Mult();
        virtual ~Mult();
};

class Int : public Symbole {
    public:
        Int(int val);
        virtual ~Int();
        int getValeur() const;
    
    protected:
        int valeur;
        virtual const string toString() const;
};

class Fin : public Symbole {
    public:
        Fin();
        virtual ~Fin();
};

class Erreur : public Symbole {
    public:
        Erreur();
        virtual ~Erreur();
};

class Expr : public Symbole {
    public:
        Expr();
        Expr(int valeur);
        Expr(const Expr &s);
        virtual ~Expr();
        int getValeur() const;

    protected:
        int valeur;
        virtual const string toString() const;
};