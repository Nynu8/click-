#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class ResourceManager
{
public:
	ResourceManager();
	const sf::Texture* GetTexture(const std::string &textureName) const;
	const sf::Font* GetFont(const std::string &fontName) const;

private:
	std::map<std::string, sf::Font*> m_fonts;
	std::map<std::string, sf::Texture*> m_textures;
}; 

inline const sf::Texture* ResourceManager::GetTexture(const std::string &textureName) const { return m_textures.at(textureName); }
inline const sf::Font* ResourceManager::GetFont(const std::string &fontName) const { return  m_fonts.at(fontName); }
