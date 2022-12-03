// clang-format off
#include <stdio.h>
#include <stdlib.h>

#include "structures.c"
#include "deck.c"
#include "startGame.c"
#include "debug.c"
// clang-format on

/* Κανόνες παιχνιδιού: WIP*/

int main() {
    struct Card deck[52];      //Κάθε "Card" έχει μία τιμή "int value" (1-10 για τους αριθμούς ενώ οι φιγούρες στο εσωτερικά του προγράμματος συμβολίζονται J=20, Q=30, Κ=40) και μία "char symbol" ('c', 's', 'd', 'h').
    initializeDeck(&deck[0]);  //Δίνει τιμές στον πίνακα deck[] που αρχικά ήταν άδειος.
    shuffleDeck(&deck[0]);

    startGame(&deck[0]);

    return 0;
}