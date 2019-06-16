#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	//Default font 
	sf::Font* defFont = new sf::Font();
	if (defFont->loadFromFile("./assets/arial.TTF"))
		m_fonts["Arial"] = defFont;
	
	//pointer font
	sf::Font* poiFont = new sf::Font();
	if (defFont->loadFromFile("./assets/HandVetica.ttf"))
		m_fonts["HandVetica"] = defFont;

	sf::Texture* appleTtexture = new sf::Texture();
	if (appleTtexture->loadFromFile("./assets/apple_tree.png"))
		m_textures["appleTree"] = appleTtexture;
/*
	sf::Sprite appleTsprite; 
	appleTsprite.setTexture(appleTtexture);*/

	
}
