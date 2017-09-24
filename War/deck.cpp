#include "deck.hpp"



void Deck::createDeck(){
	deck.reserve(52);
	for (int r = Ace; r <= King; ++r){
		for (int s = Hearts; s <= Spades; ++s){
			Card c(static_cast<Rank>(r), static_cast<Suit>(s));
			deck.push_back(c);
		}
	}
}
//shuffles the cards
void Deck::shuffleCards(std::vector<Card> deck){
	std::random_shuffle(deck.begin(), deck.end());
}
//shows current deck of cards
void Deck::viewDeck(std::vector<Card> deck){
	int i = 0;
	for (Card c : deck){
		std::cout << c << " ";
		i++;
		if (i == 12){
			std::cout << "\n";
			i = 0;
		}
	}
}
std::vector<Card> Deck::getDeck(){
	return deck;
}