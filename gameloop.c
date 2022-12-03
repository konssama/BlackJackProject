#include "drawCard.c"

void initializeHand(struct Card *pHand) {
    for (int i = 0; i < 10; i++) {
        (*pHand).symbol = '_';
        (*pHand).value = 0;
        pHand++;
    }
}

void setDefaultValues(struct Human *player, struct Human *house) {
    (*player).name = 'c';
    initializeHand(&((*player).currentHand)[0]);
    (*player).nOfCards = -1;
    (*player).handValue = 0;
    (*player).money = 100;
    (*player).currentBet = 0;

    (*house).name = 'h';
    initializeHand(&((*house).currentHand)[0]);
    (*house).nOfCards = -1;
    (*house).handValue = 0;
    (*house).money = 100;
    (*house).currentBet = 0;
}

void gameLoop(struct Card *pDeck) {
    struct Card *top = pDeck + 51;
    printf("\nFirst Card: %d of %c", (*top).value, (*top).symbol);
    printf("\nLast Card: %d of %c", (*pDeck).value, (*pDeck).symbol);

    struct Human player;
    struct Human house;

    setDefaultValues(&player, &house);

    struct Human winner = house;

    printf("\nStarting Game...");

    drawCard(&player, top);
    printf("\n%d", player.handValue);
    // display(player, house);

    // if (player.handValue <= 21) {
    //     char answer;
    //     printf("Would you like to draw another card? (Y/N)");

    //     do {
    //         scanf("\n%c", &answer);
    //     } while (answer != 'Y' && answer != 'N');
    // } else {
    //     winner = house;
    // }

    // printf("%c", winner.name);
}