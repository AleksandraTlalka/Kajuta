#ifndef BIRD_H
#define BIRD_H

#include "GraphicObject.h"
#include <cmath>


enum class texture_type {
	look_up = 1,
	look_forward = 0,
	look_down = 2
};

class Bird : public GraphicObject
{
private:
	texture_type actualTexture;
	int alive;
	float acceleration;
	float velocity;
	float friction;
	void setTexture(texture_type type);
public:
	Bird(sf::Vector2f pPosition, sf::Vector2f pSize, sf::Texture pTexture, Game* pGame, bool pAlive = true);
	void update(float deltaTime);
	bool isAlive();
	void onCollision();
	bool isOutOfMap();
	bool isColliding(GraphicObject& testedObject);
	void setAcceleration(float acc);
};

#endif BIRD_H