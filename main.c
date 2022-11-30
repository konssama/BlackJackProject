#include <stdio.h>
#include <stdlib.h>

#include "deck.c"
#include "structures.c"

/* Κανόνες παιχνιδιόυ: WIP

Άλλες σημειώσεις:
Όπου γράφω: func(deck), ξέρω οτι θα ήταν εξυπνώτερο να περάσω το
pointer του deck, αλλά είμαι 90% σίγουρος οτι ο compiler μου
το έκανε αυτόματα, οπότε αποφάσησα να μην το πειράξω*/

int main() {
    struct Card deck[52];  //Κάθε "Card" έχει μία τιμή "int value" (1-10 για τους αριθμούς ενώ οι φιγόυρες στο εσωτερικά του προγράμματος συμβολίζονται J=20, Q=30, Κ=40) και μία "char symbol" ('c', 's', 'd', 'h').
    initializeDeck(deck);  //Δίνει τιμές στον πίνακα deck[] που αρχικά ήταν άδειος.
    printDeck(deck);

    seperate();

    shuffle(deck);
    printDeck(deck);

    // WIP
    // int playing = 1;
    // int top = 52;
    // struct Human player;
    // struct Human dealer;

    // seperate();

    //  drawCard(player.currentCard, deck, top);
    //  printf("\n%c", player.currentCard.symbol);

    return 0;
}