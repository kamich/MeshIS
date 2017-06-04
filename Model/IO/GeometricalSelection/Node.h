#ifndef NODE_H_
#define NODE_H_
#include "SFML/Graphics/CircleShape.hpp"
#include <memory>
class Node
{
public:

	Node(int x, int y);

	double x;
	double y;

	bool selected;

	void select();
	void deselect();

	sf::CircleShape* getShape();

private:

	std::unique_ptr<sf::CircleShape> shape;
};

#endif