#pragma once

#include <SFML\Graphics.hpp>
#include "SDVector.h"

struct Graphics
{
	void DrawLine(sf::RenderWindow& window, float x1, float y1, float x2, float y2, sf::Color color)
	{
		sf::Vertex line[] =
		{
			sf::Vertex({ x1,y1 },color),
			sf::Vertex(sf::Vector2f(x2,y2),color)
		};

		window.draw(line, 2, sf::Lines);
	}
	void DrawLine(sf::RenderWindow& window, const SDVector& startPos, const SDVector& endPos,sf::Color color)
	{
		sf::Vertex line[] =
		{
			sf::Vertex({ startPos.GetX(),startPos.GetY() },color),
			sf::Vertex(sf::Vector2f(endPos.GetX(),endPos.GetY()),color)
		};

		window.draw(line, 2, sf::Lines);
	}
	//TODO: overload this function to support different paramaters

};

