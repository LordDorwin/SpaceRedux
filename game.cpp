//game.cpp
//Primary class for SpaceRedux

#include <SFML/Graphics.hpp>
#include"player.h"
#include"enemy.h"
#include"group.h"
#include"globals.h"

int main()
{
	const int maxFrameTime = 100000;
	sf::RenderWindow window(sf::VideoMode(1024, 680), "Clunker Spaceship");

	//Create Group of  ships in gameworld
	Group ShipGrp;

	Player player = Player(200, 200);
	ShipGrp.add(&player);
	Enemy enemy = Enemy(300, 300);
	enemy.setTar(&player);
	ShipGrp.add(&enemy);
	Enemy enemy2 = Enemy(300, 400);
	enemy2.setTar(&player);
	ShipGrp.add(&enemy2);
	Enemy enemy3 = Enemy(300, 500);
	enemy3.setTar(&player);
	ShipGrp.add(&enemy3);
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
		ShipGrp.update(frameTime);

		//Draw frame
		window.clear();
		ShipGrp.draw(&window);
		window.display();

	}//End of game Loop

	window.close();
	return 0;
}