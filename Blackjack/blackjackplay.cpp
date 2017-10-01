#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "blackjackplay.h"
#include "Card.h"


using namespace std;


Deck::Deck()
{
	size = 52;
	int counter = 0;
	int pointnum;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 14; j++)
        {
            if(j==1)
            {
                pointnum = 11;
            }
            if(j<10)
            {
                pointnum = j;
            }
            if(j>9)
            {
                pointnum = 10;
            }
			storage[counter].setCard(i, j, pointnum);
			counter++;
		}
	}
}


Card Deck::deal()
{
	size--;
	Card card1 = storage[size];
	return card1;
}



void Deck::shuffle()
{
	srand(time(0));
	int a, b;

	for (int i = 0; i < size; i++)
    {
		a = rand()%size;
		b = rand()%size;
		Card temp = storage[a];
		storage[a] = storage[b];
		storage[b] = temp;
	}

}


int Deck::cardsLeft()
{
	return size;
}
