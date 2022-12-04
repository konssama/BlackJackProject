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
    //Διαβάστε πρώτα το structures.c
    struct Card deck[52];      //Μία στοίβα απο 52 κάρτες. Κάθε "Card" έχει μία τιμή "int value" (1-10 για τους αριθμούς ενώ οι φιγούρες στο εσωτερικά του προγράμματος συμβολίζονται J=20, Q=30, Κ=40) και μία "char symbol" ('c', 's', 'd', 'h').
    initializeDeck(&deck[0]);  //Δίνει τιμές στον deck[52] κάνοντας τον μία ρεαλιστική τράπουλα.
    shuffleDeck(&deck[0]);     //Μπερδεύει την τράπουλα deck[52].

    //Οι παραπάνω συναρτήσεις βρίσκονται στο αρχείο deck.c

    startGame(&deck[0]);
    //Βρίσκεται τελευταία στο αρχείο startGame.c

    return 0;
}