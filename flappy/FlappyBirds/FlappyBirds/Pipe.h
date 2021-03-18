#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>
#include "GraphicObject.h"


enum class pipe_type {
	pipe_top = 1,
	pipe_bottom = 0
};

class Game;
class Pipe : public GraphicObject
{
private:
	pipe_type type;
	void setTexture(pipe_type type);
public:
	virtual void move(sf::Vector2f shift);
	Pipe(sf::Vector2f pPosition, sf::Vector2f pSize, sf::Texture pTexture, Game* pGame, pipe_type type);
	void update(float deltaTime);
	~Pipe();
};


class Ground : public GraphicObject
{
public:
	Ground (sf::Vector2f pPosition, sf::Vector2f pSize, sf::Texture pTexture, Game* pGame);
	void update(float deltaTime);
	~Ground();
};

#endif PIPE_H