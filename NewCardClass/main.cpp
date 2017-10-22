#include "card.hpp"

#include <cstdlib>
#include <iostream>

int main(){

	Deck d;
	d.createDeck();
	d.shuffleDeck(d.deck);

	system("pause");
	return 0;
}