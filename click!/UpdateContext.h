#pragma once
#include <SFML/Graphics.hpp>

struct UpdateContext
{
	float m_deltaTime;
	sf::RenderWindow* m_pWindow;
};