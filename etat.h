#pragma once

#include <string>
#include "automate.h"
#include "symbole.h"
using namespace std;

class Etat {

   public:
      Etat(string n) : name(n) { };
      virtual ~Etat();

      virtual bool transition(Automate & automate, Symbole * s) = 0;

   protected:
      string name;
};
