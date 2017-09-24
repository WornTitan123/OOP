#pragma once
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"

class Game{
private:
	int turns;
	int stages;
	bool winner;
	bool warWon;


public:
	Game() = default;
	int playGame();
	std::queue<Card> splitDeck(std::vector<Card>,int,int);
};