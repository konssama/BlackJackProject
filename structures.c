
struct Card {
    int value;
    char symbol;
};

struct Human {
    char name;
    struct Card currentHand[10];
    int nOfCards;
    int handValue;
    int money;
    int currentBet;
};