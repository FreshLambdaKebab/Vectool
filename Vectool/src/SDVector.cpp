#include "SDVector.h"

#include <iostream>

SDVector::SDVector() :
	m_x(0.0f),
	m_y(0.0f),
	m_vecName("")
{
}

SDVector::SDVector(float x, float y):
	m_x(x),
	m_y(y)
{
	Set(x, y);
}

SDVector::~SDVector()
{
}

void SDVector::PrintVector(const std::string& vecName)
{
	m_vecName = vecName;
	//give the vector a name and print out its details, formatted.
	std::cout << m_vecName.c_str() << "(" << m_x << "," << m_y << ")" << std::endl;
}

void SDVector::DrawVector(sf::RenderWindow& window,sf::Color color)
{
	sf::Vertex line[] =
	{
		sf::Vertex({ 400,300 },color),
		sf::Vertex(sf::Vector2f(400 + m_x, 300 - m_y),color)
	};

	window.draw(line, 2, sf::Lines);
}


float SDVector::Length()
{
	float length = sqrt(m_x * m_x + m_y * m_y);

	return length;
}

float SDVector::LengthSquared()
{
	float length = m_x * m_x + m_y * m_y;

	return length;
}

void SDVector::Normalize()
{
	float length = this->Length();

	//be sure to not divide by zero!!
	if (length == 0.0f)
	{
		m_x = 0.0f;
		m_y = 0.0f;

		return;
	}

	m_x /= length;
	m_y /= length;
}

SDVector SDVector::operator+(const SDVector & vec)
{
	//create a temporary vector to add onto desired vector
	SDVector tempVec = *this;//it equals a dereferenced pointer to this class
	tempVec.m_x += vec.m_x;
	tempVec.m_y += vec.m_y;

	return tempVec;
}

SDVector SDVector::operator-(const SDVector & vec)
{
	SDVector tempVec = *this;
	tempVec.m_x -= vec.m_x;
	tempVec.m_y -= vec.m_y;

	return tempVec;
}

float SDVector::dot(const SDVector & vec)
{
	float dot = m_x * vec.m_x + m_y * vec.m_y;

	return dot;
}

SDVector SDVector::Add(const SDVector & vec1, const SDVector & vec2)
{
	SDVector resultantVec;

	resultantVec.m_x = vec1.m_x + vec2.m_x;
	resultantVec.m_y = vec1.m_y + vec2.m_y;

	return resultantVec;
}

