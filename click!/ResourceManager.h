#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class ResourceManager
{
public:
	ResourceManager();
	void drawCookieAmount(unsigned long long);

private:
	std::map<std::string, sf::Font> m_fonts;
	std::map<std::string, sf::Sprite> m_sprites;
	std::map<std::string, sf::Texture> m_textures;
	
};