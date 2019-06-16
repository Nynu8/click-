#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class ResourceManager
{
public:
	ResourceManager();
	sf::Texture getTexture(std::string textureName);
	sf::Font getFont(std::string textureName);

private:
	std::map<std::string, sf::Font> m_fonts;
	std::map<std::string, sf::Texture> m_textures;
	
}; 