//game.cpp
//Primary class for SpaceRedux

#include <SFML/Graphics.hpp>
#include"player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 680), "SFML works!");

	Player player = Player(200, 200);

	//Game Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			player.thrForward();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			player.thr
		}
		player.update();

		window.clear();
		window.draw(player.sprite);
		window.display();

	}//End of game Loop

	return 0;
}