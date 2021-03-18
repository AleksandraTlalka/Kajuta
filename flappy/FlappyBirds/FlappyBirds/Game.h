#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "GraphicObject.h"
#include "Bird.h"
#include "Obstruction.h"
#include "Pipe.h"

#include <ctime>
#include <string>


class Game
{
public:
	sf::RenderWindow* window;
	std::vector<GraphicObject*> objects;
	int score;
	sf::Font fontNumbers;
	sf::Font fontLetters;
	sf::Text score_text;
	sf::Text end_text;
	Bird* bird;
	sf::RenderWindow* getRenderWindow();
	Game();
	~Game();
	void removeObject(GraphicObject* objectToRemove);
private:
	sf::Texture pipeTexture;
	sf::Texture groundTexture;
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::RectangleShape ground;
	void handlePlayerJump(sf::Clock& birdJumpClock);
	void startGameLoop();
	void init();
};

#endif GAME_H