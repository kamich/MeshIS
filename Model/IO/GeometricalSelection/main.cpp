#include <SFML/Graphics.hpp>
#include <vector>

#include "Node.h"
#include "Selector.h"

int width = 1000;
int height = 500;
int rows = 20;
int cols = 20;
bool selecting = false;


std::vector<std::vector<Node>> createNodes(int rows, int cols);
void drawNodes(sf::RenderWindow& window, std::vector<std::vector<Node>>& Nodes);

int main()
{
	std::vector<std::vector<Node>> Nodes = createNodes(rows, cols);
	sf::Vector2f mouse_down_position;
	sf::Vector2f mouse_current_position;

	Selector selector(SelectorShape::Square, sf::Color(0, 0, 255, 50));

	sf::RenderWindow window(sf::VideoMode(width, height), "Geometrical Selection Demo");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			else if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::C:
					selector.changeSelectorShape(SelectorShape::Circle);
					break;
				case sf::Keyboard::S:
					selector.changeSelectorShape(SelectorShape::Square);
					break;
				}
				
			}

			else if (event.type == sf::Event::MouseButtonPressed &&
					 event.mouseButton.button == sf::Mouse::Left)
			{
				mouse_down_position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
				selecting = true;
				selector.setSelectorPosition(mouse_down_position);
			}
			else if (event.type == sf::Event::MouseButtonReleased &&
					 event.mouseButton.button == sf::Mouse::Left)
			{
				selecting = false;
			}

			if (selecting)
			{
				mouse_current_position = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
			}
		}

		window.clear(sf::Color::White);
		drawNodes(window, Nodes);
		if (selecting)
		{
			auto size_x = mouse_current_position.x - mouse_down_position.x;
			auto size_y = mouse_current_position.y - mouse_down_position.y;
			selector.drawSelector(window, { size_x, size_y });
			selector.selectNodes(Nodes);
		}
		window.display();
	}

	return 0;
}

std::vector<std::vector<Node>> createNodes(int rows, int cols)
{
	int rows_gap = height / rows;
	int cols_gap = width / cols;
	std::vector<std::vector<Node>> Nodes(rows);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			Nodes[i].emplace_back(j * cols_gap, i * rows_gap);
		}
	}

	return Nodes;
}

void drawNodes(sf::RenderWindow& window, std::vector<std::vector<Node>>& Nodes)
{
	for (auto& row : Nodes)
	{
		for (auto& node : row)
		{
			//std::cout << "Drawing: " << node.x << " " << node.y << std::endl;
			window.draw(*node.getShape());
		}
	}
}