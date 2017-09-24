#pragma once

#include "card.hpp"
#include <queue>

class Player{
private:
	std::queue<Card> playersDeck;
public:
	Player() = default;
	std::queue<Card> getPlayersDeck();
	void setPlayersDeck(std::queue<Card>);
	void addCard(Card);
	void removeCard();
};