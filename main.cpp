#include <iostream>
#include "war.h"

int main()
{
    War game;
    std::string choice;

    do {
        std::cout << "Press 'c' to continue or 'f' to forfeit: ";
        std::cin >> choice;

        if (choice == "f") {
            std::cout << "Player 1 has " << game.getp1DeckSize() << " cards left." << std::endl;
            std::cout << "Player 2 has " << game.getp2DeckSize() << " cards left." << std::endl;
            break;
        }

        game.play();

    } while (true);

    return 0;
}