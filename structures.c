
struct Card {  // Κάθε "Card" έχει μία τιμή "int value" (1-10 για τους αριθμούς ενώ οι φιγούρες στο εσωτερικά του προγράμματος συμβολίζονται J=20, Q=30, Κ=40) και μία "char symbol" ('c', 's', 'd', 'h').
    int value;
    char symbol;
};

struct Human {
    char name;                    // Χρησιμοποιείται για να αναγνωρίσουμε το παίκτη. p = Player, h = House.
    struct Card currentHand[10];  // Το "χέρι" του παίκτη.
    int nOfCards;                 // Τόσες κάρτες έχει ο παίκτης. Χρησιμοποιείται ως index του currentHand[10].
    int handValue;                // Η συνολική αξία των καρτών που έχει τραβήξει ο παίκτης μέχρι τώρα.
    int money;                    // Τα χρήματα που του έχουν απομείνει.
    int currentBet;               // Πόσα απο αυτά έχει ποντάρει.
};