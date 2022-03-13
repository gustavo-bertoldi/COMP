#pragma once

#include <string>
#include "symbole.h"

class Automate;

class Etat {
    public:
        Etat(int nmr);
        Etat(const Etat &e);
        virtual ~Etat();
        virtual bool transition(Automate &aut, Symbole *s) const = 0;
        friend ostream &operator<<(ostream &os, const Etat &e);
    
    protected:
        const string toString() const;
        int nmrEtat;
};

class E0 : public Etat {
    public:
        E0();
        virtual ~E0();
        virtual bool transition(Automate &aut, Symbole *s) const;
};

class E1 : public Etat {
    public:
        E1();
        virtual ~E1();
        virtual bool transition(Automate &aut, Symbole *s) const;
};

class E2 : public Etat {
    public:
        E2();
        virtual ~E2();
        virtual bool transition(Automate &aut, Symbole *s) const;
};

class E3 : public Etat {
    public:
        E3();
        virtual ~E3();
        virtual bool transition(Automate &aut, Symbole *s) const;
};

class E4 : public Etat {
    public:
        E4();
        virtual ~E4();
        virtual bool transition(Automate &aut, Symbole *s) const;
};

class E5 : public Etat {
    public:
        E5();
        virtual ~E5();
        virtual bool transition(Automate &aut, Symbole *s) const;
};

class E6 : public Etat {
    public:
        E6();
        virtual ~E6();
        virtual bool transition(Automate &aut, Symbole *s) const;
};

class E7 : public Etat {
    public:
        E7();
        virtual ~E7();
        virtual bool transition(Automate &aut, Symbole *s) const;
};

class E8 : public Etat {
    public:
        E8();
        virtual ~E8();
        virtual bool transition(Automate &aut, Symbole *s) const;
};

class E9 : public Etat {
    public:
        E9();
        virtual ~E9();
        virtual bool transition(Automate &aut, Symbole *s) const;
};
