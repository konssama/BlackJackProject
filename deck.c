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

// Fisher-Yates Algorithm.
void shuffle(struct Card *pDeck) {
    struct Card newDeck[52];
    struct Card *start = pDeck;
    int a = 0;
    int b = 51;
    int offset = 0;

    for (int i = 0; i < 52; i++) {
        offset = (rand() % (b - a + 1)) + a;  // add random offset to pDeck pointer (0 - 51)
        pDeck += offset;
        newDeck[i] = *pDeck;
    }

    pDeck = start;
    for (int i = 0; i < 52; i++) {
        *pDeck = newDeck[i];
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp, flag = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // introducing a flag to monitor swapping
            if (arr[j] > arr[j + 1]) {
                // swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                // if swapping happens update flag to 1
                flag = 1;
            }
        }
        // if value of flag is zero after all the iterations of inner loop
        // then break out
        if (flag == 0) {
            break;
        }
    }

    // print the sorted array
    printf("Sorted Array: ");
    for (i = 0; i < n; i++) {
        printf("%d  ", arr[i]);
    }
}

// Fisher-Yates Algorithm. Ο(n^2)
// void shuffleDeck(struct Card *pDeck) {
//     struct Card newDeck[52];
//     struct Card *start = pDeck;
//     int a = 0;
//     int b = 51;
//     int offset = 0;

//     for (int i = 0; i < 52; i++) {
//         offset = (rand() % (b - a + 1)) + a;  // add random offset to pDeck pointer (0 - 51)
//         pDeck += offset;
//         newDeck[i] = *pDeck;
//     }

//     pDeck = start;
//     for (int i = 0; i < 52; i++) {
//         *pDeck = newDeck[i];
//     }
// }

// Improved Fisher-Yates Algorithm. Ελπίζω.
void shuffleDeck(struct Card *pDeck) {
    struct Card *start = pDeck;  // Η αρχή του array deck[].
    int indexes[52];             // Οι τιμές indexes[] χρησιμοποιόυνται για τις μετατοπίσεις του pDeck.
    float weights[52];           // τυχαίες τιμές (0-1). Με βάση αυτές θα γίνει η ταξινόμηση του indexes[].

    for (int i = 0; i < 52; i++) {
        indexes[i] = i;
    }
    for (int i = 0; i < 52; i++) {
        weights[i] = (rand() % (1 - 0 + 1)) + 0;
    }
}
