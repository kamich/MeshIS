#ifndef SELECTOR_H_
#define SELECTOR_H_
#include "SFML/Graphics.hpp"

class Node;

enum class SelectorShape
{
	Square,
	Circle
};

class Selector
{
public:
	Selector(SelectorShape selector_shape, sf::Color color);
	SelectorShape selector_shape;
	void changeSelectorShape(SelectorShape selector_shape);
	void drawSelector(sf::RenderWindow& window, sf::Vector2f selector_size);
	void setSelectorPosition(sf::Vector2f mouse_down_position);
	void selectNodes(std::vector<std::vector<Node>>& nodes);

private:
	sf::RectangleShape rectangle_selector;
	sf::CircleShape circle_selector;
};

#endif