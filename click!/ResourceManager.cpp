#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	//Default font 
	sf::Font defFont;
	if (!defFont.loadFromFile("HandVetica.ttf"))
		m_fonts["Arial"] = defFont;
	
	//pointer font
	sf::Font poiFont;
	if (!defFont.loadFromFile("HandVetica.ttf"))
		m_fonts["Arial"] = defFont;
	
}
