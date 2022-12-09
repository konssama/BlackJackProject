
// Επιστρέφει την πραγματική αξία μιας κάρτας.
int valueOfCard(struct Card *currentCard) {
    int realValue = 0;

    if ((*currentCard).value >= 2 && (*currentCard).value <= 10) {
        realValue = (*currentCard).value;  // Εφόσον είναι αριθμός η τιμή του είναι απλα το value της κάρτας.

    } else if ((*currentCard).value > 10) {
        realValue = 10;  // Οι φιγούρες έχουν value 20, 30 και 40 αντίστοιχα. Στο παιχνίδι όμως όλες μετράνε για 10.

    } else if ((*currentCard).value == 1) {
        realValue = -1;  // Στην περίπτωση του άσου επιστρέφουμε error -1 για να το διαχειριστεί άλλη συνάρτηση.
    }

    return realValue;
}

int handleAce(struct Human *person) {
    int aceValue;

    if ((*person).name == 'p') {
        printf("Picked an ace. You can either choose 1 or 10: ");  // Ο Άσος μετράει για 1 ή 10, ανάλογα με την επιλογή του παίκτη.

        do {
            scanf("%d", &aceValue);
        } while (aceValue != 1 && aceValue != 10);

    } else if ((*person).name == 'h') {
        if ((*person).handValue + 10 > 21) {
            aceValue = 1;
        } else {
            aceValue = 10;
        }
    }

    return aceValue;
}

void drawCard(struct Human *person) {
    extern struct Card *top;
    struct Card pickedCard = *top;  // Η κάρτα που τράβηξε ο παίκτης είναι αυτή που δείχνει το top
    top--;                          // To top πρέπει τώρα να πάει στην προηγούμενη κάρτα.

    (*person).nOfCards++;                                    // Οι παίκτης δημιουργεί μια νέα θέση στο χέρι του.
    (*person).currentHand[(*person).nOfCards] = pickedCard;  // Και βάζει σε αυτη τη θέση την κάρτα που τράβηξε.

    int pickedCardValue = valueOfCard(&pickedCard);  // Κρατάμε την πραγματική αξία που τράβηξε ο παίκτης.

    if (pickedCardValue != -1) {
        (*person).handValue += pickedCardValue;  // Εφόσον δεν έχει error -1 μπορούμε να προσθέσουμε την αξία στην συνολική.
    } else {
        (*person).handValue += handleAce(person);  // Αλλιώς καλούμε ειδική συνάρτηση.
    }
}