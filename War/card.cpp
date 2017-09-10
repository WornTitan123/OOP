#include "card.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>

int main(){
	Card c;

	std::vector<Card> deck;
	deck.reserve(52);
	for (int r = Ace; r <= King; ++r){
		for (int s = Hearts; s <= Spades; ++s){
			Card c(static_cast<Rank>(r), static_cast<Suit>(s));
			deck.push_back(c);
		}
	}
	for (Card c : deck){
		std::cout << c.get_rank() << ' ' << c.get_suit() << '\n';
	}
	system("pause");
	return 0;
}