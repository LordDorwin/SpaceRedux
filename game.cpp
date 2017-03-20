//game.cpp
//Primary class for SpaceRedux

#include <SFML/Graphics.hpp>
#include"player.h"
#include"globals.h"

int main()
{
	const int maxFrameTime = 100000;
	sf::RenderWindow window(sf::VideoMode(1024, 680), "Clunker Spaceship");

	Player player = Player(200, 200);
	sf::Clock mainClock; //starting the main game clock

	sf::Time elapsedTime; //creating the time varaiable
	int frameTime;
	//Game Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				printf("death is the only escape\n");
			}*/
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			player.thrForward();
			//printf("forward\n");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			player.thrLeft();
			//printf("left\n");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player.thrRight();
			//printf("right\n");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			player.thrBack();
			//printf("back\n");
		}
		sf::Vector2i mousePos = sf::Mouse::getPosition(window); // window is a sf::Window
		mouse::x = mousePos.x;
		mouse::y = mousePos.y;
		sf::Time elapsedTime = mainClock.restart();
		frameTime = elapsedTime.asMicroseconds();
		
		frameTime = std::min(frameTime, maxFrameTime);
		//printf("%d\n", frameTime);
		player.update(frameTime);


		window.clear();
		window.draw(player.sprite);
		window.display();

	}//End of game Loop

	return 0;
}