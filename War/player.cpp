#include "player.hpp"

std::queue<Card> Player::getPlayersDeck(){
	return playersDeck;
}
void Player::setPlayersDeck(std::queue<Card> deck){
	playersDeck = deck;
}
void Player::addCard(Card c){
	playersDeck.push(c);
}
void Player::removeCard(){
	playersDeck.pop();
}