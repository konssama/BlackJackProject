#include <stdio.h>
#include <stdlib.h>

//Δίνει την τιμή 0 στο "value" της κάθε καρτας και τιμή '_' στο "symbol" της. Χωρίς αυτήν οι κάρτες έπαιρναν φαινομενικά τυχαίες τιμές.
void preInitializeDeck(struct Card *pDeck) {
    for (int i = 0; i < 52; i++) {
        (*pDeck).value = 0;
        (*pDeck).symbol = '_';
        pDeck++;
    }
}

//Δίνει τιμές στον πίνακα deck[] που αρχικά ήταν άδειος.
void initializeDeck(struct Card *pDeck) {
    preInitializeDeck(pDeck);                            //Δίνει την τιμή 0 στο "value" της κάθε καρτας και τιμή '_' στο "symbol" της. Χωρίς αυτήν οι κάρτες έπαιρναν φαινομενικά τυχαίες τιμές.
    char currentLoopedSymbol[4] = {'c', 's', 'd', 'h'};  //Τα 4 σύμβολα που μπορεί να πάρει μία κάρτα.
    int i = 0;                                           // index του currentLoopedSymbol[] 0-3.
    int k = 0;                                           // η τιμή που πρέπει να το "value" της κάρτας στην συγκεκριμένη επανάληψη.

    while (i < 4) {
        k = 0;
        while (k < 10) {
            k++;
            (*pDeck).value = k;
            (*pDeck).symbol = currentLoopedSymbol[i];
            pDeck++;
        }
        while (k < 40) {
            k += 10;
            (*pDeck).value = k;
            (*pDeck).symbol = currentLoopedSymbol[i];
            pDeck++;
        }
        i++;
    }
}

void bubbleSort(int array[], float basedOn[]) {
    int n = 52;
    int tempI;
    float tempF;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (basedOn[j] > basedOn[j + 1]) {
                tempI = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tempI;

                tempF = basedOn[j];
                basedOn[j] = basedOn[j + 1];
                basedOn[j + 1] = tempF;
            }
        }
    }
}

// Improved Fisher-Yates Algorithm. Δεν καταλαβαίνω πως.
void shuffleDeck(struct Card *pDeck) {
    int i;
    struct Card *start = pDeck;  // Η αρχή του array deck[].
    struct Card newDeck[52];     //Εδώ αποθηκεύονται οι μπερδεμένες κάρτες.
    int indexes[52];             // Οι τιμές indexes[] χρησιμοποιόυνται για τις μετατοπίσεις του pDeck.
    float weights[52];           // τυχαίες τιμές (0-1). Με βάση αυτές θα γίνει η ταξινόμηση του indexes[].

    for (i = 0; i < 52; i++) {
        indexes[i] = i;
    }
    for (i = 0; i < 52; i++) {
        weights[i] = ((float)rand() / (float)(RAND_MAX)) * 1;
    }

    bubbleSort(indexes, weights);

    for (int i = 0; i < 52; i++) {
        pDeck = start + indexes[i];
        newDeck[i] = *pDeck;
    }

    pDeck = start;
    for (int i = 0; i < 52; i++) {
        *pDeck = newDeck[i];
        pDeck++;
    }
}