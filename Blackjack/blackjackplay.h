#ifndef Blackjackplay_H
#define Blackjackplay_H
#include "Card.h";

using namespace std;

class Deck
{
    protected:
	Card storage[52];
	int size;

    public:
	Deck();

	Card deal();

	void shuffle();

	int cardsLeft();

};


#endif

