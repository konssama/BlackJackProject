// #include "structures.c"

// int valueOfCard(struct Card card) {
//     int value = 0;

//     if (card.value >= 2 && card.value <= 10) {
//         value = card.value;

//     } else if (card.value > 10) {
//         value = 10;

//     } else if (card.value == 1) {
//         int aceValue;

//         printf("Picked an ace. You can either choose 1 or 10");

//         do {
//             scanf("%d", &aceValue);
//         } while (aceValue != 1 && aceValue != 10);

//         value = aceValue;
//     }

//     return value;
// }

// void drawCard(struct Human person, struct Card *top) {
//     struct Card pickedCard = *top;
//     top--;

//     person.nOfCards++;
//     person.currentHand[person.nOfCards] = pickedCard;
//     person.handValue += valueOfCard(pickedCard);
// }