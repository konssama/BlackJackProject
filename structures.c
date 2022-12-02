
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