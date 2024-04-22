#ifndef WAR_H
#define WAR_H
#include "deck.h"

class War {
private:
	Deck deck;
	Deck p1Deck;
	Deck p2Deck;

public:
	War();
	void play();
	size_t getp1DeckSize() const;
	size_t getp2DeckSize() const;
};

#endif