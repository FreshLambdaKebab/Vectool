#pragma once

#include <SFML\Graphics.hpp>

#include "SDVector.h"
#include "Graphics.h"

enum class Operation{ADD,SUB,MUL};

class Application
{
public:
	Application();
	~Application();

	void Initialize();
	void Run();
	void Render();
	void Update();

	//functions to display info
	//void Display(const Operation& op);
	void DisplayAddInfo();
	void DisplaySubInfo();
	void DisplayMultInfo();

private:
	void QueryUser();

	sf::RenderWindow* m_window;

	//create the vector objects 
	SDVector vec1;
	SDVector vec2;
	SDVector resultantVec;
	Graphics m_graphics;

	//window resolution
	const int m_screenWidth = 800;
	const int m_screenHeight = 600;

	//opration char
	char m_op;

	//x and y coords for the vectors
	float m_vec1X, m_vec1Y;
	float m_vec2X, m_vec2Y;

	//test text rendering
	sf::Font m_font;
	sf::Text m_text;
};

