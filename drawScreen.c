
void printHand(struct Card hand[], int nOfCards) {
    for (int i = 0; i < nOfCards + 1; i++) {
        if (hand[i].value == 1) {
            wprintf(L"A%lc  ", hand[i].symbol);
        } else if (hand[i].value < 10) {
            wprintf(L"%d%lc ", hand[i].value, hand[i].symbol);
        } else if (hand[i].value == 20) {
            wprintf(L"J%lc ", hand[i].symbol);
        } else if (hand[i].value == 30) {
            wprintf(L"Q%lc ", hand[i].symbol);
        } else if (hand[i].value == 40) {
            wprintf(L"K%lc ", hand[i].symbol);
        }
    }
}

extern int roundNumber;
void drawScreen(struct Human *person) {
    system("cls");

    if ((*person).name == 'p') {
        wprintf(L"\nRound %d - Player's Turn", roundNumber);
    } else if ((*person).name == 'h') {
        wprintf(L"\nRound %d - House's Turn", roundNumber);
    }

    wprintf(L"\n");
    wprintf(L"\nMoney: %3d                    Bet: %3d", (*person).money, (*person).currentBet);

    wprintf(L"\n");
    wprintf(L"\nTotal Value: %d\n", (*person).handValue);
    printHand((*person).currentHand, (*person).nOfCards);
    wprintf(L"\n");
}