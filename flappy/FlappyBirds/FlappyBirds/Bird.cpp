#include "Bird.h"

#include "const.h"

void Bird::setTexture(texture_type type)
{
	sf::Vector2u textureSize = texture.getSize();
	shape.setTextureRect(sf::IntRect(0, textureSize.y / 3 * int(type), textureSize.x, textureSize.y / 3));
}

Bird::Bird(sf::Vector2f pPosition, sf::Vector2f pSize, sf::Texture pTexture, Game* pGame, bool pAlive)
	: alive(pAlive),
	velocity(V_MIN),
	acceleration(A_MIN),
	friction(0),
	actualTexture(texture_type::look_forward),
	GraphicObject(pPosition, pSize, pTexture, pGame)
{
	setTexture(actualTexture);
}


void Bird::update(float deltaTime)
{
	totalTime += deltaTime;
	if (totalTime >= switchTime)
	{
		texture_type newActualTexture;
		totalTime -= switchTime;
		if (friction > 2) friction = 0;
		friction += 0.05;
		acceleration -= atan(friction);
		if (acceleration < A_MIN) acceleration = A_MIN;
		velocity += acceleration;
		if (velocity > V_MAX) velocity = V_MAX;
		else if (velocity < V_MIN) velocity = V_MIN;

		if (velocity > 0) newActualTexture = texture_type::look_up;
		else if (velocity < 0) newActualTexture = texture_type::look_down;
		else if (velocity == 0) newActualTexture = texture_type::look_forward;
		if (newActualTexture != actualTexture)
		{
			actualTexture = newActualTexture;
			setTexture(actualTexture);
		}
		move({ 0,-velocity });
	}
}


bool Bird::isAlive()
{
	return alive;
}

void Bird::onCollision()
{
	alive = false;
}

bool Bird::isOutOfMap()
{
	if (position.y + BIRD_HEIGHT / 2 > WINDOW_HEIGHT)
		return true;
	return false;
}

bool Bird::isColliding(GraphicObject& testedObject)
{
	return false;
}

void Bird::setAcceleration(float acc)
{
	acceleration = acc;
	friction = 0;
}
