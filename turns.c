#include <unistd.h>

// Η σειρά του ανθρώπου.
void playerTurn(struct Human *player) {
    playerBet(player);

    if ((*player).nOfCards == -1) {
        drawCard(player);
        drawCard(player);
    } else {
        drawCard(player);
    }

    drawScreen(player);

    if ((*player).handValue <= 21) {
        char answer;

        wprintf(L"\nWould you like to draw another card? (y/n)");
        scanf("\n%c", &answer);

        if (answer != 'y' && answer != 'n') {
            do {
                wprintf(L"\nIncompatible answer");
                wprintf(L"\nWould you like to draw another card? (y/n)");
                scanf("\n%c", &answer);
            } while (answer != 'y' && answer != 'n');
        }

        if (answer == 'y') {
            playerTurn(player);
        }
    } else {
        wprintf(L"\nBust!");
    }
}

// Η σειρά της μηχανής.
void houseTurn(struct Human *house) {
    if ((*house).nOfCards == -1) {
        drawCard(house);
        drawCard(house);
    } else {
        drawCard(house);
    }

    drawScreen(house);
    sleep(1);

    if ((*house).handValue <= 21) {
        if ((*house).handValue <= 17) {
            houseTurn(house);
        }
    } else {
        wprintf(L"\nBust!");
    }
}