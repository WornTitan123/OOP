#include "card.hpp"

Card::Card(int i){ id = i; }

Suit::Suit(int id, Rank r, Color c){
	Card card(id);
	rank = r;
	color = c;
}

Joker::Joker(int id, Color c){
	Card card(id);
	color = c;
}

Club::Club(int id, Rank r){
	Suit s(id, r, Black);
}

Diamond::Diamond(int id, Rank r){
	Suit s(id, r, Red);
}

Heart::Heart(int id, Rank r){
	Suit s(id, r, Red);
}

Spade::Spade(int id, Rank r){
	Suit s(id, r, Black);
}


void Deck::createDeck(){
	int id = 0;
	for (int i = Ace; i <= King; i++){
		deck.push_back(new Spade(0, static_cast<Rank>(i)));
		deck.push_back(new Heart(1, static_cast<Rank>(i)));
		deck.push_back(new Diamond(2, static_cast<Rank>(i)));
		deck.push_back(new Club(3, static_cast<Rank>(i)));
	}

	deck.push_back(new Joker(-1, Black));
	deck.push_back(new Joker(-1, Black));

	std::cout << deck.size() << "\n";
}
void Deck::shuffleDeck(std::vector<Card*> deck){
	std::random_shuffle(deck.begin(), deck.end());
}

