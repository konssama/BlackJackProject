
int valueOfCard(struct Card *currentCard) {
    int value = 0;

    if ((*currentCard).value >= 2 && (*currentCard).value <= 10) {
        value = (*currentCard).value;

    } else if ((*currentCard).value > 10) {
        value = 10;

    } else if ((*currentCard).value == 1) {
        int aceValue;

        printf("Picked an ace. You can either choose 1 or 10");

        do {
            scanf("%d", &aceValue);
        } while (aceValue != 1 && aceValue != 10);

        value = aceValue;
    }

    return value;
}

void drawCard(struct Human *person, struct Card *top) {
    struct Card pickedCard = *top;
    top--;

    (*person).nOfCards++;
    (*person).currentHand[(*person).nOfCards] = pickedCard;
    (*person).handValue += valueOfCard(&pickedCard);
}