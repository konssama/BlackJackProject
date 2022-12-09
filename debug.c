
// DEBUG FUNCTION
void printDeck(struct Card *pDeck) {
    for (int i = 0; i < 52; i++) {
        printf("\n%d | %d of %c", (i + 1), (*pDeck).value, (*pDeck).symbol);
        pDeck++;
    }
}

// DEBUG FUNCTION
void separate(void) {
    printf("\n|--------------------------------------------------------------|");
    printf("\n");
}

void cheatersDeck(struct Card *pDeck, int value, char symbol) {
    for (int i = 0; i < 52; i++) {
        (*pDeck).value = value;
        (*pDeck).symbol = symbol;
        pDeck++;
    }
}