enum Rank{
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

//suits of cards in a deck
enum Suit{
	Hearts,
	Diamonds,
	Clubs,
	Spades
};

class Card{
private:
	Rank rank;
	Suit suit;

public:
	Card() = default;
	Card(Rank r, Suit s)
		:rank(r), suit(s){}

	//accessor
	//observer
	Rank get_rank() const { return rank; }
	Suit get_suit() const { return suit; }

	//mutator
	//modifier
	void set_rank(Rank r){ rank = r; }
	void set_suit(Suit s){ suit = s; }

};