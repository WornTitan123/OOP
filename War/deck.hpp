#pragma once

#include "player.hpp"
#include "card.hpp"

#include <iostream>
#include <vector>

struct Deck{
private:
	std::vector<Card> deck;

public:
	Deck() = default;
	std::vector<Card> getDeck();
	void setDeck(std::vector<Card>);

	//member functions
	void shuffleCards(std::vector<Card>);
	void viewDeck(std::vector<Card>);
	void createDeck();
};