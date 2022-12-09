
//* CURRENTLY UNUSED

void playerBet(struct Human *player) {
    if ((*player).nOfCards == -1) {
        printf("\nCurrent Amount of Money: %d", (*player).money);
        printf("\nInput Starting Bet: ");
        scanf("%d", &((*player).currentBet));
    } else {
        printf("\nCurrent Amount of Money: %d", (*player).money);
        printf("\nCurrent Bet: %d. Increase? (y/n)", (*player).currentBet);

        char answer;
        scanf("\n%c", &answer);

        if (answer != 'y' && answer != 'n') {
            do {
                printf("\nIncompatible answer");
                printf("\nWould you like to draw another card? (y/n)");
                scanf("\n%c", &answer);
            } while (answer != 'y' && answer != 'n');
        }

        if (answer == 'y') {
            int betIncrease = 0;
            printf("\nBy how much?");
            scanf("%d", &betIncrease);
            (*player).currentBet += betIncrease;
        }
    }
}