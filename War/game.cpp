#include "game.hpp"

int Game::playGame(){

	Deck d;
	Player p1, p2;
	Card hand1, hand2;
	std::vector<Card> warHand1, warHand2;

	int end = 26;
	int start = 0;
	std::queue<Card> hand;

	d.createDeck();
	d.shuffleCards(d.getDeck());
	hand = splitDeck(d.getDeck(), end, start);
	p1.setPlayersDeck(hand);
	end = 52;
	start = 26;
	hand = splitDeck(d.getDeck(), end, start);
	p2.setPlayersDeck(hand);

	turns = 0;
	winner = false;
	while (!winner){
		warWon = false;
		stages = 0;
		hand1 = p1.getPlayersDeck().front();
		hand2 = p2.getPlayersDeck().front();
		p1.removeCard();
		p2.removeCard();
		if (hand1.get_rank() > hand2.get_rank()){
			p1.addCard(hand2);
			p1.addCard(hand1);
		}
		else if (hand1.get_rank() < hand2.get_rank()){
			p2.addCard(hand1);
			p2.addCard(hand2);
		}
		else {
			for (int i = 0 + stages; i < 5 + stages; ++i){
				
				warHand1.push_back(p1.getPlayersDeck().front());
				if (p1.getPlayersDeck().empty() || p2.getPlayersDeck().empty()){ break; winner = true; }
				warHand2.push_back(p2.getPlayersDeck().front());
				if (p1.getPlayersDeck().empty() || p2.getPlayersDeck().empty()){ break; winner = true; }
				p1.removeCard();
				p2.removeCard();
			}
			if (warHand1[4 + stages].get_rank() < warHand2[4 + stages].get_rank()){
				for (int i = 0; i < 5 + stages; ++i){
					p1.addCard(warHand1[i]);
					p1.addCard(warHand2[i]);
				}
				warHand1.clear();
				warHand2.clear();
			}
			else if (warHand1[4 + stages].get_rank() > warHand2[4 + stages].get_rank()){
				for (int i = 0; i < 5 + stages; ++i){
					p2.addCard(warHand1[i]);
					p2.addCard(warHand2[i]);
				}
				warHand1.clear();
				warHand2.clear();
			}
			else{
				stages += 5;
				turns++;
			}
		}
		turns++;
		if (p1.getPlayersDeck().size() == 0 || p2.getPlayersDeck().size() == 0){
			winner = true;
		}
		
	}

	return turns;
}
std::queue<Card> Game::splitDeck(std::vector<Card> deck ,int end,int start){
	std::queue<Card> hand;
	for (int i = start; i < end; ++i){
		hand.push(deck[i]);
	}
	return hand;
}