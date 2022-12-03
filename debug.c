
// DEBUG FUNCTION
void printDeck(struct Card *pDeck) {
    for (int i = 0; i < 52; i++) {
        printf("\n%d | %d of %c", (i + 1), (*pDeck).value, (*pDeck).symbol);
        pDeck++;
    }
}

// DEBUG FUNCTION
void separate(void) {
    printf("\n|-------------------------------------------------------------------------------------------------------|");
}