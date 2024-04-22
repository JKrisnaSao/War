#include "war.h"
#include "deck.h"
#include <iostream>

size_t War::getp1DeckSize() const {
	return p1Deck.draw_deck.size();
}

size_t War::getp2DeckSize() const {
	return p2Deck.draw_deck.size();
}
War::War() {
	deck.shuffle();

	for (int i = 0; i < 26; i++) {		//split the deck to both players 
		p1Deck.draw_deck.push(deck.draw());
		p2Deck.draw_deck.push(deck.draw());
	}
}

void War::play() {
	while (!p1Deck.draw_deck.empty() && !p2Deck.draw_deck.empty()) { //turning one card 
		Card* p1Card = p1Deck.draw_deck.top();
		p1Deck.draw_deck.pop();

		Card* p2Card = p2Deck.draw_deck.top();
		p2Deck.draw_deck.pop();

		std::cout << "Player 1 draws " << p1Card->print() << std::endl;
		std::cout << "Player 2 draws " << p2Card->print() << std::endl;

		//comparing the cards that they drew 

		if (p1Card->compareValue(*p2Card) > 0) {
			std::cout << "Player 1 wins the round" << std::endl;
			p1Deck.draw_deck.push(p1Card);
			p1Deck.draw_deck.push(p2Card);

		}
		else if (p1Card->compareValue(*p2Card) < 0) {
			std::cout<< "Player 2 wins the round" << std::endl;
			p2Deck.draw_deck.push(p1Card);
			p2Deck.draw_deck.push(p2Card);
		}
		else {
			std::cout << "It;s a tie! War starts ..." << std::endl;

			std::vector<Card*> warPile;

			Card* wCard1 = p1Deck.draw_deck.top();
			p1Deck.draw_deck.pop();
			warPile.push_back(wCard1);

			Card* wCard2 = p2Deck.draw_deck.top();
			p2Deck.draw_deck.pop();
			warPile.push_back(wCard2);


			Card* wCard1Face = p1Deck.draw_deck.top();
			p1Deck.draw_deck.pop();
			warPile.push_back(wCard1Face);

			Card* wCard2Face = p2Deck.draw_deck.top();
			p2Deck.draw_deck.pop();
			warPile.push_back(wCard2Face);

			std::cout << "Player 1's war card is " << wCard1Face->print() << std::endl;
			std::cout << "Player 2's war card is " << wCard2Face->print() << std::endl;


			//comparing the war cards
			if (wCard1Face->compareValue(*wCard2Face) > 0) {
				std::cout << "Player 1 wins the war" << std::endl;
				for (Card* card : warPile) {
					p1Deck.draw_deck.push(card);
				}
			}
			else if (wCard1Face->compareValue(*wCard2Face) < 0) {
				std::cout << "Player 2 wins the war " << std::endl;
				for (Card* card : warPile) {
					p2Deck.draw_deck.push(card);
				}
			}
			else {
				std::cout << "Another tie! War continues " << std::endl;
			}
		}

	}
	if (p1Deck.draw_deck.empty()) {
		std::cout << "Player 2 wins the game" << std::endl;
	}
	else {
		std::cout << "Player 1 wins the game" << std::endl;
	}
}