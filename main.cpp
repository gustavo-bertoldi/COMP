#include "symbole.h"
#include "automate.h"
#include <iostream>

int main() {
    string chaine("(1+1)");
    auto aut = new Automate(chaine);
    aut -> evaluerChaine();

    return 0;
}