#include <time.h>

// Δίνει την τιμή 0 στο "value" της κάθε καρτας και τιμή '_' στο "symbol" της. Χωρίς αυτήν οι κάρτες έπαιρναν φαινομενικά τυχαίες τιμές.
void preInitializeDeck(struct Card *pDeck) {
    for (int i = 0; i < 52; i++) {
        (*pDeck).value = 0;
        (*pDeck).symbol = '_';
        pDeck++;
    }
}

// Δίνει τιμές στον deck[52] κάνοντας τον μία ρεαλιστική τράπουλα.
void initializeDeck(struct Card *pDeck) {
    preInitializeDeck(pDeck);  // Δίνει την τιμή 0 στο "value" της κάθε καρτας και τιμή '_' στο "symbol" της. Χωρίς αυτήν οι κάρτες έπαιρναν φαινομενικά τυχαίες τιμές.

    wchar_t currentLoopedSymbol[4] = {
        0x2667, 0x2664, 0x2661, 0x2662  // Τα 4 σύμβολα που μπορεί να πάρει μία κάρτα.(Clover, Spade, Heart, Diamond)
    };

    int i = 0;  // index του currentLoopedSymbol[] 0-3.
    int k = 0;  // η τιμή που πρέπει να πάρει το "value" της κάρτας στην συγκεκριμένη επανάληψη.

    while (i < 4) {  // Θέλουμε να επαναλάβουμε την ίδια διαδικασία με τα values, μία για κάθε σύμβολο.
        k = 0;

        while (k < 10) {  // Στις 10 πρώτες κάρτες (Άσος-10) δίνουμε value 1-10
            k++;
            (*pDeck).value = k;
            (*pDeck).symbol = currentLoopedSymbol[i];
            pDeck++;
        }  // τρέχει 10 φορές.

        while (k < 40) {  // Μετά οι φιγούρες έχουν value 20, 30 και 40 αντίστοιχα μέσα στο πρόγραμμα, όμως όλες μετράνε για 10 στο παιχνίδι.
            k += 10;
            (*pDeck).value = k;
            (*pDeck).symbol = currentLoopedSymbol[i];
            pDeck++;
        }  // τρέχει 3 φορές.

        i++;
    }  // τρέχει 4 φορές. Άρα συνολικά έχουμε (10+3)*4 = 52 επαναλήψεις, μία για κάθε μοναδική κάρτα.
}

void bubbleSort(int array[], float basedOn[]) {  // Ένα απλό bubble sort.
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
    struct Card *start = pDeck;  // Η αρχή του array deck[].
    struct Card newDeck[52];     // Εδώ αποθηκεύονται προσωρινά οι μπερδεμένες κάρτες. Στο τέλος της συνάρτησης επιστρέφονται στο αρχικό deck[52].
    int indexes[52];             // Οι τιμές indexes[] χρησιμοποιόυνται για τις μετατοπίσεις του pDeck.
    float weights[52];           // τυχαίες τιμές (0-1). Με βάση αυτές θα γίνει η ταξινόμηση (μπέρδεμα) του indexes[].

    for (int i = 0; i < 52; i++) {
        indexes[i] = i;  // Κάθε κελί του indexes παίρνει ως τιμή τον αντίστοιχο αριθμό του κελιού.
    }

    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        weights[i] = ((float)rand() / (float)(RAND_MAX)) * 1;  // Δίνουμε τυχαίες τιμές στον weights[52] (0-1).
    }

    bubbleSort(indexes, weights);  // Κάνουμε bubble sort τον indexes[52] με βάση τις τυχαίες τιμές wights[52], ώστε να μπερδευτεί ο indexes.

    // Με τη σειρά του indexes θα βάλουμε όλες τις κάρτες του deck[52] σε ένα newDeck[52].
    for (int i = 0; i < 52; i++) {
        pDeck = start + indexes[i];  // Σε κάθε επανάληψη μετατοπίζουμε το pointer του deck indexes[i] θέσεις.
        newDeck[i] = *pDeck;         // και κρατάμε την κάρτα που δείχνει το pointer στην καινούρια στοίβα.
    }

    // Επιστρέφουμε τις τιμές του newDeck[52] στον αρχικό.
    pDeck = start;
    for (int i = 0; i < 52; i++) {
        *pDeck = newDeck[i];
        pDeck++;
    }
}