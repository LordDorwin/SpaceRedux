//game.cpp
//Primary class for SpaceRedux

#include <list>
#include <SFML/Graphics.hpp>
#include"player.h"
#include"globals.h"

int main()
{
	const int maxFrameTime = 100000;
	sf::RenderWindow window(sf::VideoMode(1024, 680), "Clunker Spaceship");

	//Create list of  Entities in gameworld
	std::list<Entity*> entList;

	Player player = Player(200, 200);
	entList.push_front(&player);

	sf::Clock mainClock; //starting the main game clock

	sf::Time elapsedTime; //creating the time varaiable
	int frameTime;

	//Game Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			player.thrForward();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			player.thrLeft();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			player.thrRight();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			player.thrBack();
		}

		//Update Mouse position
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		mouse::x = mousePos.x;
		mouse::y = mousePos.y;

		//Calculate frameTime
		sf::Time elapsedTime = mainClock.restart();
		frameTime = elapsedTime.asMicroseconds();
		frameTime = std::min(frameTime, maxFrameTime);

		//Update Entities
		entList.front()->update(frameTime);

		//Draw frame
		window.clear();
		entList.front()->draw(&window);
		window.display();

	}//End of game Loop

	window.close();
	return 0;
}