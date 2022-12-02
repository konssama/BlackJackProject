#include "drawCard.c"

void gameLoop(struct Card *pDeck) {
    struct Card *top = pDeck + 51;

    struct Human player;
    struct Human house;

    struct Human winner = house;

    player.name = 'c';
    player.money = 100;
    player.nOfCards = 0;

    house.name = 'h';
    house.money = 100;
    house.nOfCards = 0;

    printf("Starting Game...");

    // main while loop
    drawCard(player, top);
    printf("%d", (player.currentHand[player.nOfCards]).value);
    // display(player, house);

    if (player.handValue <= 21) {
        char answer;
        printf("Would you like to draw another card? (Y/N)");

        do {
            scanf("\n%c", &answer);
        } while (answer != 'Y' && answer != 'N');
    } else {
        winner = house;
    }

    printf("%c", winner.name);
}