#pragma once
#include <SFML/Graphics.hpp>

struct UpdateContext
{
	float m_DeltaTime;
	sf::RenderWindow* m_pWindow;
};