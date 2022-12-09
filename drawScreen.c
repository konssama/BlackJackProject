#include <stdio.h>

void printHand(struct Card *hand, int nOfCards) {
    for (int i = 0; i < nOfCards + 1; i++) {
        printf("%d%c  ", hand[i].value, hand[i].symbol);
    }
}

extern int roundNumber;
void drawScreen(struct Human *person) {
    system("cls");

    if ((*person).name == 'p') {
        printf("\nRound %d - Player's Turn", roundNumber);
    } else if ((*person).name == 'h') {
        printf("\nRound %d - House's Turn", roundNumber);
    }

    printf("\n");
    printf("\nMoney: %3d                    Bet: %3d", (*person).money, (*person).currentBet);

    printf("\n");
    printf("\nTotal Value: %d\n", (*person).handValue);
    printHand((*person).currentHand, (*person).nOfCards);
}