#include <stdio.h>

// DEBUG FUNCTION
void printDeck(struct Card *pDeck) {
    for (int i = 0; i < 52; i++) {
        printf("\n%d of %c", (*pDeck).value, (*pDeck).symbol);
        pDeck++;
    }
}

// DEBUG FUNCTION
void separate(void) {
    printf("\n|-------------------------------------------------------------------------------------------------------|");
}