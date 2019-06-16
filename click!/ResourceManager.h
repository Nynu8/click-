#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class ResourceManager
{
public:
	ResourceManager();
	const sf::Texture* getTexture(const std::string &textureName) const;
	const sf::Font* getFont(const std::string &fontName) const;

private:
	std::map<std::string, sf::Font*> m_fonts;
	std::map<std::string, sf::Texture*> m_textures;
	
}; 

inline const sf::Texture* ResourceManager::getTexture(const std::string &textureName) const { return m_textures.at(textureName); }
inline const sf::Font* ResourceManager::getFont(const std::string &fontName) const { return  m_fonts.at(fontName); }
