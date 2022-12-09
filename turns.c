
// Η σειρά του ανθρώπου.
void playerTurn(struct Human *player) {
    separate();
    if ((*player).nOfCards == -1) {
        drawCard(player);
        drawCard(player);
    } else {
        drawCard(player);
    }
    printf("\nNumber of cards drawn: %d", (*player).nOfCards + 1);  //* DEBUG
    printf("\nTotal value: %d", (*player).handValue);               //* DEBUG

    if ((*player).handValue <= 21) {
        char answer;

        printf("\nWould you like to draw another card? (y/n)");
        scanf("\n%c", &answer);

        if (answer != 'y' && answer != 'n') {
            do {
                printf("\nIncompatible answer");
                printf("\nWould you like to draw another card? (y/n)");
                scanf("\n%c", &answer);
            } while (answer != 'y' && answer != 'n');
        }

        if (answer == 'y') {
            playerTurn(player);
        }
    } else {
        printf("\nBust!");
    }
}

// Η σειρά της μηχανής.
void houseTurn(struct Human *house) {
    separate();
    if ((*house).nOfCards == -1) {
        drawCard(house);
        drawCard(house);
    } else {
        drawCard(house);
    }
    printf("\nNumber of cards drawn: %d", (*house).nOfCards + 1);  //* DEBUG
    printf("\nTotal value: %d", (*house).handValue);               //* DEBUG

    if ((*house).handValue <= 21) {
        if ((*house).handValue <= 17) {
            houseTurn(house);
        }
    } else {
        printf("\nBust!");
    }
}