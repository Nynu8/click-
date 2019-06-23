#include "ResourceManager.h"

ResourceManager::ResourceManager()
{	
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
	if (first->loadFromFile("./assets/upgrade1.png"))
		m_textures["upgrade1"] = first;

	sf::Texture* second = new sf::Texture();
	if (second->loadFromFile("./assets/upgrade2.png"))
		m_textures["upgrade2"] = second;

	sf::Texture* third = new sf::Texture();
	if (third->loadFromFile("./assets/upgrade3.png"))
		m_textures["upgrade3"] = third;

	sf::Texture* background = new sf::Texture();
	if (background->loadFromFile("./assets/wood.jpg"))
		m_textures["wood"] = background;
	m_textures["wood"]->setRepeated(true);
}
