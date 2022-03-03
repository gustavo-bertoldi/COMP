#include "symbole.h"
#include "automate.h"
#include <iostream>

int main() {
    string chaine("(3+2)*5*(1+4)");
    auto aut = new Automate(chaine);
    aut -> evaluerChaine();

    return 0;
}