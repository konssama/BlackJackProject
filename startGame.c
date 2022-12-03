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

void playerTurn(struct Human *player, struct Card *top) {
    drawCard(player, top);  // ΟΤΑΝ ΒΓΑΙΝΕΙ ΑΠΟ ΕΔΩ ΔΕΝ ΕΠΙΣΤΡΕΦΕΙ ΤΟ TOP ΚΑΙ ΔΕΙΧΝΕΙ ΑΚΟΜΑ ΤΗΝ ΠΑΝΩ-ΠΑΝΩ ΚΑΡΤΑ
    printf("\n%d", (*player).handValue);

    if ((*player).handValue <= 21) {
        char answer;

        printf("\nWould you like to draw another card? (y/n)");
        // scanf("\n%c", &answer);
        answer = 'y';
        if (answer != 'y' && answer != 'n') {
            do {
                printf("\nIncompatible answer");
                printf("\nWould you like to draw another card? (y/n)");
                scanf("\n%c", &answer);
            } while (answer != 'y' && answer != 'n');
        }

        if (answer == 'y') {
            playerTurn(player, top);
        }
    }
}

void startGame(struct Card *pDeck) {
    struct Card *top = pDeck + 51;

    struct Human player;
    struct Human house;

    setDefaultValues(&player, &house);

    printf("\nStarting Game...");

    playerTurn(&player, top);
    printf("\n%d", player.handValue);  // DEBUG
    // houseTurn();
}