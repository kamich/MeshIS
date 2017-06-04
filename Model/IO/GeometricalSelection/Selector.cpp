#include "Selector.h"
#include "Node.h"

Selector::Selector(SelectorShape selector_shape, sf::Color color)
	: selector_shape(selector_shape)
{
	rectangle_selector.setFillColor(color);
	rectangle_selector.setOutlineColor(color);
	rectangle_selector.setOutlineThickness(2);

	circle_selector.setFillColor(color);
	circle_selector.setOutlineColor(color);
	circle_selector.setOutlineThickness(2);
}

void Selector::changeSelectorShape(SelectorShape selector_shape)
{
	this->selector_shape = selector_shape;
}

void Selector::setSelectorPosition(sf::Vector2f mouse_down_position)
{
	rectangle_selector.setPosition(mouse_down_position);
	circle_selector.setPosition(mouse_down_position);
}

void Selector::drawSelector(sf::RenderWindow& window, sf::Vector2f selector_size)
{
	switch (selector_shape)
	{
	case SelectorShape::Square:
		rectangle_selector.setSize(selector_size);
		window.draw(rectangle_selector);
		break;
	case SelectorShape::Circle:
		circle_selector.setRadius(std::max(selector_size.x, selector_size.y) / 2.0f);
		window.draw(circle_selector);
		break;
	}
}

void Selector::selectNodes(std::vector<std::vector<Node>>& nodes)
{
	if (selector_shape == SelectorShape::Square)
	{
		auto R_start_x = std::min(rectangle_selector.getPosition().x, rectangle_selector.getPosition().x + rectangle_selector.getSize().x);
		auto R_start_y = std::min(rectangle_selector.getPosition().y, rectangle_selector.getPosition().y + rectangle_selector.getSize().y);
		auto R_end_x = std::max(rectangle_selector.getPosition().x, rectangle_selector.getPosition().x + rectangle_selector.getSize().x);
		auto R_end_y = std::max(rectangle_selector.getPosition().y, rectangle_selector.getPosition().y + rectangle_selector.getSize().y);

		for (auto& rows : nodes)
		{
			for (auto& node : rows)
			{
				if (node.x > R_start_x && node.x < R_end_x &&
					node.y > R_start_y && node.y < R_end_y)
				{
					node.select();
				}
				else
				{
					node.deselect();
				}
			}
		}
	}

	else if (selector_shape == SelectorShape::Circle)
	{
		auto C_start_x = circle_selector.getPosition().x + circle_selector.getRadius();
		auto C_start_y = circle_selector.getPosition().y + circle_selector.getRadius();

		for (auto& rows : nodes)
		{
			for (auto& node : rows)
			{
				auto distance = sqrtf(std::pow(node.x - C_start_x, 2) + std::pow(node.y - C_start_y, 2));
				if (distance < std::abs(circle_selector.getRadius()))
				{
					node.select();
				}
				else
				{
					node.deselect();
				}
			}
		}
	}
}