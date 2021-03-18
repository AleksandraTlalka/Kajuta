#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>
#include "const.h"
#include "UpdateableObject.h"


class Game;
class GraphicObject
{
protected:
	Game* game;
	sf::RectangleShape shape;
	sf::Texture texture;
	sf::Vector2f position;
	float switchTime;
	float totalTime;
public:
	GraphicObject(sf::Vector2f pPosition, sf::Vector2f pSize, sf::Texture pTexture, Game* pGame);
	void setPosition(sf::Vector2f pPosition);
	sf::Vector2f getPosition();
	virtual ~GraphicObject(void) {};
	virtual void onCollision() {};
	virtual void draw();
	virtual bool isColliding(GraphicObject& testedObject);
	virtual void move(sf::Vector2f shift);
	sf::FloatRect getCollisionBox();
	virtual void update(float deltaTime) = 0;
};

#endif OBJECT_H