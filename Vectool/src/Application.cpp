#include "Application.h"

#include <iostream>

Application::Application()
{

}

Application::~Application()
{
	if (m_window)
	{
		delete m_window;
		m_window = nullptr;
	}
}

void Application::Initialize()
{
	//create window
	m_window = new sf::RenderWindow(sf::VideoMode(m_screenWidth, m_screenHeight), "Vectool");

	//ask the user which operation they want, then initialize the vectors and output the information the user wanted
	QueryUser();

	if (!m_font.loadFromFile("res/fonts/pricedown bl.ttf"))
	{
		std::cout << "Error: could not load font\n";
	}

	m_text.setFont(m_font);
	m_text.setString("the slow black fox crawled under the energetic cat");
	m_text.setCharacterSize(24);
	m_text.setFillColor(sf::Color::Green);
	m_text.setPosition({ 10,10 });
}

void Application::Run()
{
	//main loop
	while (m_window->isOpen())
	{
		//handle events
		sf::Event windowEvent;
		while (m_window->pollEvent(windowEvent))
		{
			if (windowEvent.type == sf::Event::Closed)
			{
				m_window->close();
			}
			//check if user pressed escape to close
			if (windowEvent.key.code == sf::Keyboard::Escape)
			{
				m_window->close();
			}

		}

		//do everything
		//clear the screen to users desired color
		m_window->clear(sf::Color::Black);

		//update and render
		Update();
		Render();

		m_window->display();
	}

}

void Application::Render()
{
	//draw the axis
	m_graphics.DrawLine(*m_window, 400, 0,400,600,sf::Color::Blue);//verticle
	m_graphics.DrawLine(*m_window, 0, 300, 800, 300,sf::Color::Red);//horizontal

	vec1.DrawVector(*m_window,sf::Color::Yellow);
	if (m_op == '+')
	{//////////////////////RENDER ADDITION(+) VECTORS///////////////////////////////////////////
	 //draw vector 1
		m_graphics.DrawLine(*m_window, SDVector(400,300), SDVector(400 + vec1.GetX(), 300 - vec1.GetY()), sf::Color::Yellow);

		//draw vector 2
		m_graphics.DrawLine(*m_window, SDVector(400 + vec1.GetX(), 300 - vec1.GetY()),//implemented vec2 to be drawn on the tip of vector 1(6/3/17)
			SDVector(400 + vec1.GetX() + vec2.GetX(), 300 - vec1.GetY() - vec2.GetY()),sf::Color::Cyan);

		//draw resultant vector
		//draw the resulatant vector
		m_graphics.DrawLine(*m_window, SDVector(400, 300), SDVector(400 + vec1.GetX() + vec2.GetX(), 300 - vec1.GetY() - vec2.GetY()),sf::Color::Green);
	
		m_window->draw(m_text);
	}

	if (m_op == '-')
	{//////////////////////RENDER SUBTRACTION(-) VECTORS///////////////////////////////////////////
	 //draw vector 1
		m_graphics.DrawLine(*m_window, SDVector(400, 300), SDVector(400 + vec1.GetX(), 300 - vec1.GetY()),sf::Color::Yellow);

		//draw vector 2
		m_graphics.DrawLine(*m_window, SDVector(400, 300),//implemented vec2 to be drawn on the tip of vector 1(6/3/17)
			SDVector(400 + vec1.GetX() + vec2.GetX(), 300 - vec1.GetY() - vec2.GetY()),sf::Color::Cyan);

		//draw resultant vector
		//draw the resulatant vector
		m_graphics.DrawLine(*m_window, SDVector(400 + vec1.GetX(), 300 - vec1.GetY()),
			SDVector(400 + vec1.GetX() + vec2.GetX(), 300 - vec1.GetY() - vec2.GetY()),sf::Color::Green);
	}
	
}

void Application::Update()
{
}

void Application::DisplayAddInfo()
{
	resultantVec = vec1 + vec2;
	std::cout << "--------------------------------------------------\n";
	printf("Resultant vector co-ords- X:%f Y:%f", resultantVec.GetX(), resultantVec.GetY());
}

void Application::DisplaySubInfo()
{
	resultantVec = vec1 - vec2;
	std::cout << "--------------------------------------------------\n";
	printf("Resultant vector co-ords- X:%f Y:%f", resultantVec.GetX(), resultantVec.GetY());
}

/*void AppScene::DisplayDivInfo()
{
resultantVec = vec1 / vec2;
std::cout << "--------------------------------------------------\n";
printf("Resultant vector co-ords- X:%f Y:%f", resultantVec.GetX(), resultantVec.GetY());
}*/

void Application::DisplayMultInfo()
{
	float dot = vec1.GetX() * vec2.GetX() + vec1.GetY() * vec2.GetY();

	std::cout << "--------------------------------------------------\n";
	printf("Resultant scalar value= %f", dot);

}

void Application::QueryUser()
{
	printf("Which operation do you want to do with 2 vectors? \n");

	std::cin >> m_op;
	switch (m_op)
	{
	case '+':
	{
		printf("Set X coord for vector1: ");
		std::cin >> m_vec1X;
		vec1.SetX(m_vec1X);
		printf("Set Y coord for vector1: ");
		std::cin >> m_vec1Y;
		vec1.SetY(m_vec1Y);
		vec1.PrintVector("Vector1");

		//get input for second vector
		printf("Set X coord for vector2: ");
		std::cin >> m_vec2X;
		vec2.SetX(m_vec2X);
		printf("Set Y coord for vector2: ");
		std::cin >> m_vec2Y;
		vec2.SetY(m_vec2Y);
		vec2.PrintVector("Vector2");
		DisplayAddInfo();
	}break;
	case '-':
	{
		printf("Set X coord for vector1: ");
		std::cin >> m_vec1X;
		vec1.SetX(m_vec1X);
		printf("Set Y coord for vector1: ");
		std::cin >> m_vec1Y;
		vec1.SetY(m_vec1Y);
		vec1.PrintVector("Vector1");

		//get input for second vector
		printf("Set X coord for vector2: ");
		std::cin >> m_vec2X;
		vec2.SetX(m_vec2X);
		printf("Set Y coord for vector2: ");
		std::cin >> m_vec2Y;
		vec2.SetY(m_vec2Y);
		vec2.PrintVector("Vector2");
		DisplaySubInfo();
	}break;
	case '*':
	{
		printf("Set X coord for vector1: ");
		std::cin >> m_vec1X;
		vec1.SetX(m_vec1X);
		printf("Set Y coord for vector1: ");
		std::cin >> m_vec1Y;
		vec1.SetY(m_vec1Y);
		vec1.PrintVector("Vector1");

		//get input for second vector
		printf("Set X coord for vector2: ");
		std::cin >> m_vec2X;
		vec2.SetX(m_vec2X);
		printf("Set Y coord for vector2: ");
		std::cin >> m_vec2Y;
		vec2.SetY(m_vec2Y);
		vec2.PrintVector("Vector2");

		DisplayMultInfo();
	}break;
	case '/':
	{
		printf("DOING DIVISION\n");

	}break;
	default:
		printf("THAT IS NOT A VALID OPERATION!\n");
	}
}

