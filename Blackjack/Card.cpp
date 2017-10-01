#include <iostream>
#include <string>
#include "Card.h"


using namespace std;


Card::Card()
{
	rank;
	suit;
	realpoint;
}


Card::Card(int s, int r, int p)
{
	rank = r;
	suit = s;
	realpoint = p;
}


void Card::setCard(int s, int r, int p)
{
	rank = r;
	suit = s;
	realpoint = p;
}


int Card::getValue()
{
	return rank;
}

int Card::getPoint()
{
    return realpoint;
}


void Card::display()
{
    switch(rank)
            {
            default:
            cout << rank << " ";
            break;
            case 0:
            cout << "Joker" << " ";
            break;
            case 11:
            cout << "Jacker" << " ";
            break;
            case 12:
            cout << "Queen" << " ";
            break;
            case 13:
            cout << "King" << " ";
            break;
            }
            switch(suit)
            {
            case 0:
            cout << "clubs" << "     ";
            break;
            case 1:
            cout << "hearts" << "     ";
            break;
            case 2:
            cout << "diamonds" << "     ";
            break;
            case 3:
            cout << "spades" << "     ";
            break;
            }
}

