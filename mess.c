#include <stdio.h>
#include <stdlib.h>

struct Card {
    int value;
    char symbol;
};

struct Human {
    struct Card currentCard;
    struct Card currentHand[10];
    int money;
    int currentBet;
};

//Δίνει την τιμή 0 στο "value" της κάθε καρτας και τιμή '_' στο "symbol" της. Χωρίς αυτήν οι κάρτες έπερναν φαινομενικά τυχαίες τιμές.
void preInitializeDeck(struct Card deck[]) {
    for (int i = 0; i < 52; i++) {
        deck[i].value = 0;
        deck[i].symbol = '_';
    }
}

//Δίνει τιμές στον πίνακα deck[] που αρχικά ήταν άδειος.
void initializeDeck(struct Card deck[]) {
    preInitializeDeck(deck);                             //Δίνει την τιμή 0 στο "value" της κάθε καρτας και τιμή '_' στο "symbol" της. Χωρίς αυτήν οι κάρτες έπερναν φαινομενικά τυχαίες τιμές.
    char currentLoopedSymbol[4] = {'c', 's', 'd', 'h'};  //Τα 4 σύμβολα που μπορέι να πάρει μία κάρτα.
    int i = 0;                                           // index του deck[] 0-51.
    int j = 0;                                           // index του currentLoopedSymbol[] 0-3.
    int k = 0;                                           // η τιμή που πρέπει να το "value" της κάρτας στην συγκεκριμένη επανάληψη.

    while (j < 4) {
        k = 0;
        while (k < 10) {
            k++;
            deck[i].value = k;
            deck[i].symbol = currentLoopedSymbol[j];
            i++;
        }
        while (k < 40) {
            k += 10;
            deck[i].value = k;
            deck[i].symbol = currentLoopedSymbol[j];
            i++;
        }
        j++;
    }
}

void shuffle(struct Card deck[]) {
    size_t i;
    for (i = 0; i < 52 - 1; i++) {
        size_t j = i + rand() / (RAND_MAX / (52 - i) + 1);
        int t = deck[j].value;
        char s = deck[j].symbol;

        deck[j].value = deck[i].value;
        deck[j].symbol = deck[i].symbol;

        deck[i].value = t;
        deck[i].symbol = s;
    }
}

// WIP
//  void drawCard(struct Card x, struct Card deck[], int top) {
//      x = deck[top];
//      top--;
//      return;
//  }

// DEBUG FUNCTION
void printDeck(struct Card deck[]) {
    for (int i = 0; i < 52; i++) {
        printf("\n%d of %c", deck[i].value, deck[i].symbol);
    }
}

// DEBUG FUNCTION
void seperate(void) {
    printf("\n//////////////////////////////////////////////////////////////////////////////////////////");
}