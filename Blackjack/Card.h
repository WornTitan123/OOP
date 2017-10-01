#ifndef CARD_H
#define CARD_H

using namespace std;


class Card
{
    private:
	int rank;
	int suit;
	int realpoint;
    public:
	Card();

	Card(int suit, int rank, int realpoint);

	void setCard(int suit, int rank, int realpoint);

	int getValue();

	int getPoint();

	void display();


};

#endif
