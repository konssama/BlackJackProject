
// Η σειρά του ανθρώπου.
void playerTurn(struct Human *player) {
    drawCard(player);
    printf("\n%d", (*player).handValue);

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
    drawCard(house);
    printf("\n%d", (*house).handValue);

    if ((*house).handValue <= 21) {
        if ((*house).handValue <= 17) {
            houseTurn(house);
        }
    } else {
        printf("\nBust!");
    }
}