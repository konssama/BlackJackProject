#include <stdio.h>

void printHand(struct Card hand[], int nOfCards) {
    for (int i = 0; i < nOfCards + 1; i++) {
        if (hand[i].value == 1) {
            printf("A%c  ", hand[i].value, hand[i].symbol);
        } else if (hand[i].value < 10) {
            printf("%d%c ", hand[i].value, hand[i].symbol);
        } else if (hand[i].value == 20) {
            printf("J%c ", hand[i].symbol);
        } else if (hand[i].value == 30) {
            printf("Q%c ", hand[i].symbol);
        } else if (hand[i].value == 40) {
            printf("K%c ", hand[i].symbol);
        }
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