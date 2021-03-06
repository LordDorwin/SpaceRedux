//game.cpp
//Primary class for SpaceRedux

#include <SFML/Graphics.hpp>
#include"player.h"
#include"ally.h"
#include"enemy.h"
#include"group.h"
#include"globals.h"

int main()
{
	const int maxFrameTime = 100000;
	sf::RenderWindow window(sf::VideoMode(1024, 680), "Clunker Spaceship");

	//Create Group of  ships in gameworld
	Group ShipGrp;

	//Create entities
	Ally ally1 = Ally(250, 200);
	ShipGrp.add(&ally1);
	Ally ally2 = Ally(300, 200);
	ShipGrp.add(&ally2);
	Enemy enemy1 = Enemy(300, 300);
	ShipGrp.add(&enemy1);
	Enemy enemy2 = Enemy(300, 400);
	ShipGrp.add(&enemy2);
	Enemy enemy3 = Enemy(300, 500);
	ShipGrp.add(&enemy3);

	//Set Targets
	ally1.setTar(&enemy1);
	ally2.setTar(&enemy2);
	enemy1.setTar(&ally1);
	enemy2.setTar(&ally1);
	enemy3.setTar(&ally1);

	//Create player and set initial control
	Player player = Player();
	player.setControl(&ally1);

	sf::Clock mainClock; //starting the main game clock

	sf::Time elapsedTime; //creating the time varaiable
	int frameTime;

	//Create and set view:
	sf::View gameView(sf::Vector2f(100, 100), sf::Vector2f(1024, 680));
	window.setView(gameView);

	//Game Loop
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::Resized)
			{
				//Update the view to the new size of the window
				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
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
		sf::Vector2i mousePosView = sf::Mouse::getPosition(window);
		sf::Vector2f mousePosWorld = window.mapPixelToCoords(mousePosView);
		mouse::x = mousePosWorld.x;
		mouse::y = mousePosWorld.y;

		//Calculate frameTime
		sf::Time elapsedTime = mainClock.restart();
		frameTime = elapsedTime.asMicroseconds();
		frameTime = std::min(frameTime, maxFrameTime);

		//Update view
		gameView.setCenter(player.getx(), player.gety());
		window.setView(gameView);

		printf("%d\n", frameTime);
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