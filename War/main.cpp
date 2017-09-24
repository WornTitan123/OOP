#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
#include "game.hpp"

#include <queue>
#include <iostream>


int main(){
	Game g;

	int turnsToWin = 0;
	int simulationNumber = 0;

	do{
		std::cout << "HOW many games of War do you want to simulation?" << std::endl;
		std::cin >> simulationNumber;
	} while (simulationNumber <= 0);

	//test functions for deck class
	/*Deck d;
	Player p1, p2;
	std::queue<Card> hand;
	d.createDeck();
	d.shuffleCards(d.getDeck());
	d.splitDeck(d.getDeck(), p1, p2);
	hand = p1.getPlayersDeck();
	std::cout << hand.size() << "\n";*/

	for (int i = 0; i < simulationNumber; ++i){
		turnsToWin += g.playGame();
	}
	std::cout << "The average for your " << simulationNumber << "is " << turnsToWin / simulationNumber << std::endl;

	g.playGame();
	system("pause");
	return 0;
}