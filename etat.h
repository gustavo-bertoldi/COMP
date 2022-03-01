#pragma once

#include <string>
#include "symbole.h"
using namespace std;

class Automate;

class Etat {

   public:
      Etat() {};
      virtual ~Etat() {};
      virtual bool transition(Automate &automate, Symbole * s) = 0;
      virtual string print() = 0;
};

class E0 : public Etat{
    public:
          E0() {};
          virtual ~E0() {};
          virtual bool transition(Automate &automate, Symbole *s);
          inline virtual string print() { return "E0"; };
};

class E1 : public Etat{
    public:
          E1() {};
          virtual ~E1(){};
          virtual bool transition(Automate &automate, Symbole *s);
          inline virtual string print() { return "E1"; };
};

class E2 : public Etat{
    public:
          E2() {};
          virtual ~E2(){};
          virtual bool transition(Automate &automate, Symbole *s);
          inline virtual string print() { return "E2"; };
};

class E3 : public Etat{
    public:
          E3() {};
          virtual ~E3(){};
          virtual bool transition(Automate &automate, Symbole *s);
          inline virtual string print() { return "E3"; };
};

class E4 : public Etat{
    public:
          E4() {};
          virtual ~E4(){};
          virtual bool transition(Automate &automate, Symbole *s);
          inline virtual string print() { return "E4"; };
};

class E5 : public Etat{
    public:
          E5() {};
          virtual ~E5(){};
          virtual bool transition(Automate &automate, Symbole *s);
          inline virtual string print() { return "E5"; };
};

class E6 : public Etat{
    public:
          E6() {};
          virtual ~E6(){};
          virtual bool transition(Automate &automate, Symbole *s);
          inline virtual string print() { return "E6"; };
};

class E7 : public Etat{
    public:
          E7() {};
          virtual ~E7(){};
          virtual bool transition(Automate &automate, Symbole *s);
          inline virtual string print() { return "E7"; };
};

class E8 : public Etat{
    public:
          E8() {};
          virtual ~E8(){};
          virtual bool transition(Automate &automate, Symbole *s);
          inline virtual string print() { return "E8"; };
};

class E9 : public Etat{
    public:
          E9() {};
          virtual ~E9(){};
          virtual bool transition(Automate &automate, Symbole *s);
          inline virtual string print() { return "E9"; };
};
