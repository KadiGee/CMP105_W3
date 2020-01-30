#include "Level.h"
bool moveRight;

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	circle.setRadius(25);
	circle.setPosition(200, 287.5);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);

	playerCirc.setRadius(10);
	playerCirc.setPosition(100, 100);
	playerCirc.setFillColor(sf::Color::Yellow);
	playerCirc.setOutlineColor(sf::Color::Red);
	playerCirc.setOutlineThickness(2.f);

	speed = 500.f;
	moveRight = true;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

	sf::Vector2f playerPos = playerCirc.getPosition();

	if (input->isKeyDown(sf::Keyboard::Up))
	{
		if (playerPos.y > 0) {
			std::cout << "Up\n";
			playerCirc.move(0, speed * dt * -1);
		}
	}
	if (input->isKeyDown(sf::Keyboard::Down))
	{
	
		std::cout << "Down\n";
		playerCirc.move(0, speed * dt);

	}
	if (input->isKeyDown(sf::Keyboard::Left))
	{

		std::cout << "Left\n";
		playerCirc.move(speed * dt * -1, 0);

	}
	if (input->isKeyDown(sf::Keyboard::Right))
	{

		std::cout << "Right\n";
		playerCirc.move(speed * dt, 0);
	}
}

// Update game objects
void Level::update(float dt)
{
	sf::Vector2f circlePos = circle.getPosition();
	sf::Vector2u pos = (window->getSize());

	float rad = circle.getRadius();

	if (circlePos.x + 2* rad>=pos.x)
	{
		moveRight = false;
	}
	else if (circlePos.x<= 0)
	{
		moveRight = true;
	}

	if (moveRight==true)
	{
		circle.move(speed * dt, 0);
	}
	else 
	{
		circle.move(speed * dt * -1, 0);
	}


	//if (playerPos.x + 20 <= pos.x && playerPos.x>=0 && playerPos.y +20<=pos.y && playerPos.y>=0)
	//{

	//	switch (direction) {
	//	case 'u':
	//		playerCirc.move(0, speed * dt * -1);
	//		break;
	//	case 'd':
	//		playerCirc.move(0, speed * dt);
	//		break;
	//	case 'l':
	//		playerCirc.move(speed * dt * -1, 0);
	//		break;
	//	case 'r':
	//		playerCirc.move(speed * dt, 0);
	//		break;
	//	default:
	//		std::cout << "default\n";
	//		break;
	//	}
	//}





}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(circle);
	window->draw(playerCirc);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}