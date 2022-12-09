
char askForReplay() {
    char answer;
    printf("\nWould you like to play again? (y/n)");
    scanf("\n%c", &answer);

    if (answer != 'y' && answer != 'n') {
        do {
            printf("\nIncompatible answer");
            printf("\nWould you like to play again? (y/n)");
            scanf("\n%c", &answer);
        } while (answer != 'y' && answer != 'n');
    }

    return answer;
}

// Αρχικοποιεί το χέρι κάθε παίκτη.
void initializeHand(struct Card *pHand) {
    for (int i = 0; i < 10; i++) {
        (*pHand).symbol = '_';
        (*pHand).value = 0;
        pHand++;
    }
}

// Δίνει αρχικές τιμές στους 2 παίκτες.
void setDefaultValues(struct Human *player, struct Human *house) {
    (*player).name = 'p';                         // Χρησιμοποιείται για να αναγνωρίσουμε το παίκτη. p = Player, h = House.
    initializeHand(&((*player).currentHand)[0]);  // Δίνουμε αρχικές τιμές σε ολόκληρο τον currentHand[10] του παίκτη.Ο currentHand[10] έχει ως index το nOfCards.
    (*player).nOfCards = -1;                      // Ξεκινάμε απο το -1, εφόσον αυξάνεται κάθε φορά ΠΡΙΝ τραβήξει κάρτα ο παίκτης.
    (*player).handValue = 0;                      // Η συνολική αξία των καρτών που έχει τραβήξει ο παίκτης μέχρι τώρα.
    (*player).money = 100;                        // Τα χρήματα που του έχουν απομείνει.
    (*player).currentBet = 0;                     // Πόσα απο αυτά έχει ποντάρει.

    (*house).name = 'h';
    initializeHand(&((*house).currentHand)[0]);
    (*house).nOfCards = -1;
    (*house).handValue = 0;
    (*house).money = 100;
    (*house).currentBet = 0;
}

struct Card *top;
int roundNumber = 1;
void startGame(struct Card *pDeck) {
    top = pDeck + 51;  // Ένα pointer που θα δείχνει πάντα την πάνω-πάνω κάρτα.

    struct Human player;
    struct Human house;
    setDefaultValues(&player, &house);  // Οι 2 παίκτες παίρνουν όλες τις αρχικές τιμές τους.

    playerTurn(&player);
    //* houseTurn(&house);

    if (askForReplay() == 'y') {
        roundNumber++;
        shuffleDeck(pDeck);
        startGame(pDeck);
    }
}