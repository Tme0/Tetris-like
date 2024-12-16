#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../headers/graphics.h"
#include "../headers/game.h"


int main() {
    srand(time(NULL));
    initialiserFenetre();
    menu(1);
    exit(EXIT_SUCCESS);
}
