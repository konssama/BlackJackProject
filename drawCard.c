
// Επιστρέφει την πραγματική αξία μιας κάρτας.
int valueOfCard(struct Card *currentCard) {
    int value = 0;

    if ((*currentCard).value >= 2 && (*currentCard).value <= 10) {
        value = (*currentCard).value;  // Εφόσον είναι αριθμός η τιμή του είναι απλα το value της κάρτας.

    } else if ((*currentCard).value > 10) {
        value = 10;  // Οι φιγούρες έχουν value 20, 30 και 40 αντίστοιχα. Στο παιχνίδι όμως όλες μετράνε για 10.

    } else if ((*currentCard).value == 1) {
        int aceValue;

        //! ΘΑ ΥΠΑΡΞΕΙ ΠΡΟΒΛΗΜΑ ΑΝ Ο ΟΙΚΟΣ ΤΡΑΒΗΞΕΙ ΑΣΟ.
        printf("Picked an ace. You can either choose 1 or 10");  // Ο Άσος μετράει για 1 ή 10, ανάλογα με την επιλογή του παίκτη.

        do {
            scanf("%d", &aceValue);
        } while (aceValue != 1 && aceValue != 10);

        value = aceValue;
    }

    return value;
}

void drawCard(struct Human *person, struct Card *top) {
    struct Card pickedCard = *top;  // Η κάρτα που τράβηξε ο παίκτης είναι αυτή που δείχνει το top
    top--;                          // To top πρέπει τώρα να πάει στην προηγούμενη κάρτα.

    (*person).nOfCards++;                                    // Οι παίκτης δημιουργεί μια νέα θέση στο χέρι του.
    (*person).currentHand[(*person).nOfCards] = pickedCard;  //Και βάζει σε αυτη τη θέση την κάρτα που τράβηξε.
    (*person).handValue += valueOfCard(&pickedCard);         //Μένει να προσθέσουμε την αξία αυτης της κάρτας στην συνολική.
}