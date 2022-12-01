#include "structures.c"

void displayHand(struct Human player) {
    struct Card card;
    for (int i = 0; i < player.nOfCards; i++) {
        card = player.currentHand[0];
        printf("\n%d", card.value);
    }
}

void display(struct Human player, struct Human house) {
    printf("-------------------------------------------------------------------");
    printf("\nPlayer: %d$                                                           House: %d$", player.money, house.money);
    printf("\n%d", player.handValue);
    displayHand(player);
}