
void playerBet(struct Human *player) {
    //! Δεν ελέγχει αν ο παίκτης έχει τα λεφτά που θέλει να ποντάρει.
    if ((*player).nOfCards == -1) {
        wprintf(L"\nCurrent Amount of Money: %d", (*player).money);
        wprintf(L"\nInput Starting Bet: ");
        scanf("%d", &((*player).currentBet));
    } else {
        wprintf(L"\nCurrent Amount of Money: %d", (*player).money);
        wprintf(L"\nCurrent Bet: %d. Increase? (y/n)", (*player).currentBet);

        char answer;
        scanf("\n%c", &answer);

        if (answer != 'y' && answer != 'n') {
            do {
                wprintf(L"\nIncompatible answer");
                wprintf(L"\nWould you like to draw another card? (y/n)");
                scanf("\n%c", &answer);
            } while (answer != 'y' && answer != 'n');
        }

        if (answer == 'y') {
            int betIncrease = 0;
            wprintf(L"\nBy how much?");
            scanf("%d", &betIncrease);
            (*player).currentBet += betIncrease;
        }
    }
}