#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	//Default font 
	sf::Font defFont;
	if (defFont.loadFromFile("./assets/arial.TTF"))
		m_fonts["Arial"] = defFont;
	
	//pointer font
	sf::Font poiFont;
	if (defFont.loadFromFile("./assets/HandVetica.ttf"))
		m_fonts["HandVetica"] = defFont;

	sf::Texture appleTtexture;
	if (appleTtexture.loadFromFile("./assets/apple_tree.png"))
		m_textures["appleTree"] = appleTtexture;
/*
	sf::Sprite appleTsprite; 
	appleTsprite.setTexture(appleTtexture);*/

	
}

sf::Texture ResourceManager::getTexture(std::string textureName)
{
	return m_textures[textureName];
}

sf::Font ResourceManager::getFont(std::string fontName)
{

	return m_fonts[fontName];
}
