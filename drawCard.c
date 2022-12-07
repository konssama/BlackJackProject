
// Επιστρέφει την πραγματική αξία μιας κάρτας.
int valueOfCard(struct Card *currentCard, char mode) {
    int value = 0;

    if ((*currentCard).value >= 2 && (*currentCard).value <= 10) {
        value = (*currentCard).value;  // Εφόσον είναι αριθμός η τιμή του είναι απλα το value της κάρτας.

    } else if ((*currentCard).value > 10) {
        value = 10;  // Οι φιγούρες έχουν value 20, 30 και 40 αντίστοιχα. Στο παιχνίδι όμως όλες μετράνε για 10.

    } else if ((*currentCard).value == 1) {
        int aceValue;

        if (mode = 'c') {
            printf("Picked an ace. You can either choose 1 or 10");  // Ο Άσος μετράει για 1 ή 10, ανάλογα με την επιλογή του παίκτη.

            do {
                scanf("%d", &aceValue);
            } while (aceValue != 1 && aceValue != 10);

        } else if (mode = 'r') {
            //! ΠΡΕΠΕΙ ΚΑΠΩΣ ΝΑ ΔΙΑΛΕΞΟΥΜΕ ΤΥΧΑΙΑ 1 Η 10.
            aceValue = 1;
        }
        value = aceValue;
    }

    return value;
}

void drawCard(struct Human *person) {
    extern struct Card *top;
    struct Card pickedCard = *top;  // Η κάρτα που τράβηξε ο παίκτης είναι αυτή που δείχνει το top
    top--;                          // To top πρέπει τώρα να πάει στην προηγούμενη κάρτα.

    (*person).nOfCards++;                                    // Οι παίκτης δημιουργεί μια νέα θέση στο χέρι του.
    (*person).currentHand[(*person).nOfCards] = pickedCard;  //Και βάζει σε αυτη τη θέση την κάρτα που τράβηξε.

    char mode = '_';  // H valueOfCard πρέπει να έχει 2 modes για την περίπτωση του άσου.
    if ((*person).name = 'p') {
        mode = 'c';  // Στην περίπτωση που τράβηξε ο άνθρωπος θέλουμε να μπούμε στην valueOfCard με "choice" mode, για να μπορεί να επιλέξει την τιμή, στην περίπτωση που τράβηξε άσο.
    } else if ((*person).name = 'h') {
        mode = 'r';  // Αντίθετα, στην σειρά του οίκου μπαίνουμε με "random" mode για να επιλεχθεί η τιμή του άσου στην τύχη.
    }

    (*person).handValue += valueOfCard(&pickedCard, mode);  //Μένει να προσθέσουμε την αξία αυτης της κάρτας στην συνολική.
}