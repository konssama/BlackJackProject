#include <stdio.h>
#include <stdlib.h>

#include "debug.c"
#include "deck.c"

/* Κανόνες παιχνιδιού: WIP*/

int main() {
    struct Card deck[52];      //Κάθε "Card" έχει μία τιμή "int value" (1-10 για τους αριθμούς ενώ οι φιγούρες στο εσωτερικά του προγράμματος συμβολίζονται J=20, Q=30, Κ=40) και μία "char symbol" ('c', 's', 'd', 'h').
    initializeDeck(&deck[0]);  //Δίνει τιμές στον πίνακα deck[] που αρχικά ήταν άδειος.
    printDeck(&deck[0]);

    separate();

    shuffleDeck(&deck[0]);
    printDeck(&deck[0]);

    return 0;
}