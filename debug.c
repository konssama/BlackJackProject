#include <stdio.h>
#include <stdlib.h>

#include "structures.c"

// DEBUG FUNCTION
void printDeck(struct Card deck[]) {
    for (int i = 0; i < 52; i++) {
        printf("\n%d of %c", deck[i].value, deck[i].symbol);
    }
}

// DEBUG FUNCTION
void seperate(void) {
    printf("\n//////////////////////////////////////////////////////////////////////////////////////////");
}