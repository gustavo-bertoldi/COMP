#pragma once

#include <string>
#include "automate.h"
#include "symbole.h"
using namespace std;

class Etat {

   public:
      Etat(){};
      virtual ~Etat();

      virtual bool transition(Automate & automate, Symbole * s) = 0;

   protected:
      string name;
};

class E0 : public Etat{
    public:
      E0(){};
      ~E0();
      virtual bool transition(Automate & automate, Symbole * s); 

    protected:

};

class E1 : public Etat{
    public:
      E1(){};
      ~E1();
      virtual bool transition(Automate & automate, Symbole * s); 

    protected:

};

class E2 : public Etat{
    public:
      E2(){};
      ~E2();
      virtual bool transition(Automate & automate, Symbole * s); 

    protected:

};

class E3 : public Etat{
    public:
      E3(){};
      ~E3();
      virtual bool transition(Automate & automate, Symbole * s); 

    protected:

};

class E4 : public Etat{
    public:
      E4(){};
      ~E4();
      virtual bool transition(Automate & automate, Symbole * s); 

    protected:

};

class E5 : public Etat{
    public:
      E5(){};
      ~E5();
      virtual bool transition(Automate & automate, Symbole * s); 

    protected:

};

class E6 : public Etat{
    public:
      E6(){};
      ~E6();
      virtual bool transition(Automate & automate, Symbole * s); 

    protected:

};

class E7 : public Etat{
    public:
      E7(){};
      ~E7();
      virtual bool transition(Automate & automate, Symbole * s); 

    protected:

};

class E8 : public Etat{
    public:
      E8(){};
      ~E8();
      virtual bool transition(Automate & automate, Symbole * s); 

    protected:

};

class E9 : public Etat{
    public:
      E9(){};
      ~E9();
      virtual bool transition(Automate & automate, Symbole * s); 

    protected:

};
