#include "card.hpp"

#include <iostream>

//shuffles the cards
std::vector<Card> Card::shuffleCards(std::vector<Card> deck){
	std::random_shuffle(deck.begin(),deck.end());
	return deck;
}
//shows current deck of cards
void Card::viewDeck(std::vector<Card> deck){
	for (Card c : deck){
		std::cout << c << '\n';
	}
}

bool
operator==(Card a, Card b)
{
	return a.get_rank() == b.get_rank() &&
		a.get_suit() == b.get_suit();
}

bool
operator!=(Card a, Card b)
{
	return !(a == b);
}

std::ostream&
operator<<(std::ostream& os, Rank r)
{
	switch (r) {
	case Ace:
		os << "Ace of ";
		break;
	case Two:
		os << "2 of ";
		break;
	case Three:
		os << "3 of ";
		break;
	case Four:
		os << "4 of ";
		break;
	case Five:
		os << "5 of ";
		break;
	case Six:
		os << "6 of ";
		break;
	case Seven:
		os << "7 of ";
		break;
	case Eight:
		os << "8 of ";
		break;
	case Nine:
		os << "9 of ";
		break;
	case Ten:
		os << "10 of ";
		break;
	case Jack:
		os << "Jack of ";
		break;
	case Queen:
		os << "Queen of ";
		break;
	case King:
		os << "King of ";
		break;
	}
	return os;
}

std::ostream&
operator<<(std::ostream& os, Suit s)
{
	switch (s) {
	case Hearts:
		os << "Hearts";
		break;
	case Diamonds:
		os << "Diamonds";
		break;
	case Clubs:
		os << "Clubs";
		break;
	case Spades:
		os << "Spades";
		break;
	}
	return os;
}


std::ostream&
operator<<(std::ostream& os, Card c)
{
	return os << c.get_rank() << c.get_suit();
}

