
void playerBet(struct Human *player) {
    if ((*player).nOfCards == -1) {
        wprintf(L"\nCurrent Amount of Money: %d", (*player).money);
        wprintf(L"\nInput Starting Bet: ");
        scanf("%d", &((*player).currentBet));

        if ((*player).money < (*player).currentBet) {
            wprintf(L"Not enough money for bet.");
            wprintf(L"\n");

            playerBet(player);
        }

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

            if ((*player).money < (*player).currentBet + betIncrease) {
                wprintf(L"Not enough money for bet.");
                wprintf(L"\n");

                playerBet(player);
            } else {
                (*player).currentBet += betIncrease;
            }
        }
    }
}