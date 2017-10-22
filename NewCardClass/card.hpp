#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
enum Rank
{
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

enum Color
{
	Black,
	Red
};

class Card{

private:
	int id;
public:
	Card() = default;
	Card(int);
	virtual ~Card() = default;
};
struct Suit :Card{
	Color color;
	Rank rank;
	Suit() = default;
	Suit(int, Rank,Color);
};

//Is a card with no suit
struct Joker :Card{
	Color color;
	Joker(int, Color);
};

//The names of the actually Suits
struct Club :Suit{
	Club(int, Rank);
};
struct Diamond :Suit{
	Diamond(int, Rank);
};
struct Heart : Suit{
	Heart(int, Rank);
};
struct Spade :Suit{
	Spade(int, Rank);
};

//A number of Cards together
struct Deck{
	std::vector<Card*> deck;
	Deck() = default;
	void createDeck();
	void viewDeck(std::vector<Card*>);
	void shuffleDeck(std::vector<Card*>);
};