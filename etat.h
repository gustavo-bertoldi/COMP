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
};

class E0 : public Etat{
    public:
      virtual ~E0() {};
      virtual bool transition(Automate & automate, Symbole * s);
};

class E1 : public Etat{
    public:
      virtual ~E1() {};
      virtual bool transition(Automate & automate, Symbole * s); 
};

class E2 : public Etat{
    public:
      virtual ~E2() {};
      virtual bool transition(Automate & automate, Symbole * s); 
};

class E3 : public Etat{
    public:
      virtual ~E3() {};
      virtual bool transition(Automate & automate, Symbole * s); 
};

class E4 : public Etat{
    public:
      virtual ~E4() {};
      virtual bool transition(Automate & automate, Symbole * s); 
};

class E5 : public Etat{
    public:
      virtual ~E5() {};
      virtual bool transition(Automate & automate, Symbole * s); 
};

class E6 : public Etat{
    public:
      virtual ~E6() {};
      virtual bool transition(Automate & automate, Symbole * s); 
};

class E7 : public Etat{
    public:
      virtual ~E7() {};
      virtual bool transition(Automate & automate, Symbole * s); 
};

class E8 : public Etat{
    public:
      virtual ~E8() {};
      virtual bool transition(Automate & automate, Symbole * s); 
};

class E9 : public Etat{
    public:
      virtual ~E9() {};
      virtual bool transition(Automate & automate, Symbole * s); 
};
