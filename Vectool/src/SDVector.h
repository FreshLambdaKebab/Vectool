#pragma once

#include <SFML\Graphics.hpp>
#include <string>

class SDVector
{
public:
	SDVector();
	SDVector(float x,float y);
	~SDVector();

	void PrintVector(const std::string& vecName);
	void DrawVector(sf::RenderWindow& window,sf::Color color);

	std::string& ToString()const;

	//getters
	inline float GetX()const { return m_x; }
	inline float GetY()const { return m_y; }
	std::string GetName()const { return m_vecName; }

	//setters
	inline void SetX(float x) { m_x = x; }
	inline void SetY(float y) { m_y = y; }
	inline void Set(float x = 0.0f, float y = 0.0f) { m_x = x, m_y = y; }

	//useful vector functions
	float Length();
	float LengthSquared();
	void Normalize();

	//overloading operational operators
	SDVector operator + (const SDVector& vec);
	SDVector operator - (const SDVector& vec);
	SDVector operator / (const SDVector& vec);

	//multiplication will use the dot product
	float dot(const SDVector& vec);
	SDVector Add(const SDVector& vec1, const SDVector& vec2);

private:
	float m_x, m_y;
	std::string m_vecName;
};

