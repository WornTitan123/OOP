#include "card.hpp"

#include <iostream>
#include<cstdlib>
#include<algorithm>
#include <vector>
#include<ctime>

int main(){
	Card c;
	
	std::uniform_int_distribution<>deckNum(1, 52);

	std::vector<Card> deck;
	deck.reserve(52);
	for (int r = Ace; r <= King; ++r){
		for (int s = Hearts; s <= Spades; ++s){
			Card c(static_cast<Rank>(r), static_cast<Suit>(s));
			deck.push_back(c);
		}
	}
	deck = c.shuffleCards(deck);
	c.viewDeck(deck);
	system("pause");
	return 0;
}