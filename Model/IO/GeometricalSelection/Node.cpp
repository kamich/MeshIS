#include "Node.h"

Node::Node(int x, int y) 
	: 
	x(x),
	y(y), 
	selected(false) 
{
	shape = std::make_unique<sf::CircleShape>(5);
	shape.get()->setFillColor(sf::Color::Black);
	shape.get()->setPosition(x, y);
}

void Node::select()
{
	selected = true;
	shape.get()->setFillColor(sf::Color::Green);
}
void Node::deselect()
{
	selected = false;
	shape.get()->setFillColor(sf::Color::Black);
}

sf::CircleShape* Node::getShape()
{
	return shape.get();
}