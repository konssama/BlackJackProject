// #include "drawCard.c"

void setDefaultValues(struct Human player, struct Human house) {
    player.name = 'c';
    player.money = 100;
    player.nOfCards = 0;

    house.name = 'h';
    house.money = 100;
    house.nOfCards = 0;
}

void gameLoop(struct Card *pDeck) {
    struct Card *top = pDeck + 51;
    printf("\nFirst Card: %d of %c", (*top).value, (*top).symbol);
    printf("\nLast Card: %d of %c", (*pDeck).value, (*pDeck).symbol);

    struct Human player;
    struct Human house;

    struct Human winner = house;

    printf("\nStarting Game...");

    // // main while loop
    // drawCard(player, top);
    // printf("%d", (player.currentHand[player.nOfCards]).value);
    // // display(player, house);

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