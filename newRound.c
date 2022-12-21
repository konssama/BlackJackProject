
char askForReplay() {
    char answer;
    wprintf(L"\nWould you like to play again? (y/n)");
    scanf("\n%c", &answer);

    if (answer != 'y' && answer != 'n') {
        do {
            wprintf(L"\nIncompatible answer");
            wprintf(L"\nWould you like to play again? (y/n)");
            scanf("\n%c", &answer);
        } while (answer != 'y' && answer != 'n');
    }

    return answer;
}

char findWinner(struct Human *player, struct Human *house) {
    char winner;
    if ((*player).handValue <= 21) {
        houseTurn(house);
        if ((*house).handValue <= 21) {
            if ((*player).handValue > (*house).handValue) {
                winner = (*player).name;
            } else {
                winner = (*house).name;
            }
        } else {
            winner = (*player).name;
        }
    } else {
        winner = (*house).name;
    }

    return winner;
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
    (*player).currentBet = 0;                     // Πόσα απο αυτά έχει ποντάρει.

    (*house).name = 'h';
    initializeHand(&((*house).currentHand)[0]);
    (*house).nOfCards = -1;
    (*house).handValue = 0;
    (*house).currentBet = 0;

    if (roundNumber == 1) {
        (*player).money = 100;  // Τα χρήματα που του έχουν απομείνει.
        (*house).money = 100;
    }
}

struct Card *top;
int roundNumber = 1;
struct Human player;
struct Human house;
void newRound(struct Card *pDeck) {
    top = pDeck + 51;  // Ένα pointer που θα δείχνει πάντα την πάνω-πάνω κάρτα.

    setDefaultValues(&player, &house);  // Οι 2 παίκτες παίρνουν όλες τις αρχικές τιμές τους.

    playerTurn(&player);

    char winner = findWinner(&player, &house);

    if (winner == player.name) {
        player.money += player.currentBet;
        house.money -= player.currentBet;
        wprintf(L"\nPlayer Wins");
    } else {
        player.money -= player.currentBet;
        house.money += player.currentBet;
        wprintf(L"\nHouse Wins");
    }

    if (player.money > 0 && house.money > 0) {
        if (askForReplay() == 'y') {
            roundNumber++;
            shuffleDeck(pDeck);
            newRound(pDeck);
        }
    } else if (player.money <= 0) {
        wprintf(L"Game Over. You have run out of money");
    } else {
        wprintf(L"Game Over. The house has run out of money");
    }
}