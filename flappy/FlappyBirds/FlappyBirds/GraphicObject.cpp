#include "GraphicObject.h"
#include "Game.h"

#include "const.h"

GraphicObject::GraphicObject(sf::Vector2f pPosition, sf::Vector2f pSize, sf::Texture pTexture, Game* pGame)
	:position(pPosition),
	texture(pTexture),
	game(pGame),
	totalTime(0),
	switchTime(0.015)
{
	shape.setSize(pSize);
	shape.setPosition(pPosition);
	shape.setTexture(&texture);
}

void GraphicObject::setPosition(sf::Vector2f pPosition)
{
	position.x = pPosition.x;
	position.y = pPosition.y;
	shape.setPosition(position);
}

sf::Vector2f GraphicObject::getPosition()
{
	return position;
}


void GraphicObject::draw()
{
	game->getRenderWindow()->draw(shape);
}

bool GraphicObject::isColliding(GraphicObject& testedObject)
{
	if (this->getCollisionBox().intersects(testedObject.getCollisionBox()))
	{
		this->onCollision();
		testedObject.onCollision();
		return true;
	}
	return false;
}

void GraphicObject::move(sf::Vector2f shift)
{
	position.x += shift.x;
	position.y += shift.y;
	shape.setPosition(position);
}

sf::FloatRect GraphicObject::getCollisionBox()
{
	return sf::FloatRect(shape.getPosition(), shape.getSize());
}
