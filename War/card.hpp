#pragma once

#include <iosfwd>
#include <utility>
#include <vector>
#include<algorithm>
#include<random>

enum Rank{
	Ace,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King
};

//suits of cards in a deck
enum Suit{
	Hearts,
	Diamonds,
	Clubs,
	Spades
};

class Card{
private:
	Rank rank;
	Suit suit;

public:
	Card() = default;
	Card(Rank r, Suit s)
		:rank(r), suit(s){}

	//accessor
	//observer
	Rank get_rank() const { return this->rank; }
	Suit get_suit() const { return suit; }

	//mutator
	//modifier
	void set_rank(Rank r){ rank = r; }
	void set_suit(Suit s){ suit = s; }

	//member functions
	std::vector <Card> shuffleCards(std::vector<Card>);
	void viewDeck(std::vector<Card>);

};
//equality comparsion
bool operator ==(Card a, Card b);
bool operator !=(Card a, Card b);

std::ostream& operator<<(std::ostream& os, Card c);
std::ostream& operator<<(std::ostream& os, Rank r);
std::ostream& operator<<(std::ostream& os, Suit r);
