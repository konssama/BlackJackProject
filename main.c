// clang-format off
#include <stdio.h>
#include <stdlib.h>

#include "structures.c"
#include "debug.c"

#include "deck.c"
#include "drawCard.c"
#include "turns.c"
#include "startGame.c"
// clang-format on

/* Κανόνες παιχνιδιού: WIP*/

int main() {
    // Διαβάστε πρώτα το structures.c

    struct Card deck[52];  // Η τράπουλα είναι απλά μια στοίβα απο 52 κάρτες.

    initializeDeck(&deck[0]);  // Δίνει τιμές στον deck[52] κάνοντας τον μία ρεαλιστική τράπουλα.
    shuffleDeck(&deck[0]);     // Μπερδεύει την τράπουλα deck[52].
    // Οι παραπάνω συναρτήσεις βρίσκονται στο αρχείο deck.c

    startGame(&deck[0]);
    // Βρίσκεται τελευταία στο αρχείο startGame.c

    return 0;
}