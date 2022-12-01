#include "drawCard.c"

void gameloop(struct Card *pDeck) {
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

    // main while loop
    drawCard(player, top);
    printStats(player);  //! empty

    if (player.handValue <= 21) {
        char answer;
        printf("Would you like to draw another Hand? (Y/N)");

        do {
            scanf("\n%c", &answer);
        } while (answer != 'Y' && answer != 'N');
    } else {
        winner = house;
    }

    printf("%c", winner.name);
}