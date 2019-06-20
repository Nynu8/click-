#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	//Default font 
	sf::Font* defFont = new sf::Font();
	if (defFont->loadFromFile("./assets/arial.TTF"))
		m_fonts["Arial"] = defFont;
	
	//pointer font
	sf::Font* poiFont = new sf::Font();
	if (poiFont->loadFromFile("./assets/HandVetica.ttf"))
		m_fonts["HandVetica"] = poiFont;

	//instruction font
	sf::Font* insFont = new sf::Font();
	if (insFont->loadFromFile("./assets/ubuntu.ttf"))
		m_fonts["ubuntu"] = insFont;

	sf::Texture* logoTexture = new sf::Texture();
	if (logoTexture->loadFromFile("./assets/logo.png"))
		m_textures["logo"] = logoTexture;

	sf::Texture* appleTtexture = new sf::Texture();
	if (appleTtexture->loadFromFile("./assets/apple_tree.png"))
		m_textures["appleTree"] = appleTtexture;

	sf::Texture* first = new sf::Texture();
	if (first->loadFromFile("./assets/click.png"))
		m_textures["first"] = first;

	sf::Texture* second = new sf::Texture();
	if (second->loadFromFile("./assets/second.png"))
		m_textures["second"] = second;

	sf::Texture* third = new sf::Texture();
	if (third->loadFromFile("./assets/third.png"))
		m_textures["third"] = third;

	sf::Texture* background = new sf::Texture();
	if (background->loadFromFile("./assets/wood.jpg"))
		m_textures["wood"] = background;
	m_textures["wood"]->setRepeated(true);
/*
	sf::Sprite appleTsprite; 
	appleTsprite.setTexture(appleTtexture);*/

	
}
