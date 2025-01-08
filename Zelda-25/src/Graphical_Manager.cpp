#include "../include/Graphical_Manager.h"


namespace Manager
{
	Graphical_Manager* Graphical_Manager::instance = nullptr;

	Graphical_Manager* Graphical_Manager::getInstance()
	{
		if (instance == nullptr)
		{
			instance = new Graphical_Manager();
		}
		return instance;
	}

	Graphical_Manager::Graphical_Manager():
		window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Zelda++")),
		view(sf::Vector2f(WIDTH/2, HEIGHT /2), sf::Vector2f(WIDTH, HEIGHT)),
		textures()
	{
		window->setFramerateLimit(60);
		if (window == nullptr)
		{
			std::cout << "ERROR::ZELDA::Graphical_Manager unable to create a graphical Window" << std::endl;
			exit(1);
		}
		
	}

	Graphical_Manager::~Graphical_Manager()
	{
		for (std::map<std::string, sf::Texture*>::iterator it = textures.begin(); it != textures.end(); it++)
		{
			delete it->second;
		}
		textures.clear();
		delete window;
	}
	
	void Graphical_Manager::show()
	{
		window->display();
	}
	
	void Graphical_Manager::clean()
	{
		window->clear();
	}

	void Graphical_Manager::draw(sf::RectangleShape body)
	{
		window->draw(body);
	}

	void Graphical_Manager::draw(sf::CircleShape body)
	{
		window->draw(body);
	}

	void Graphical_Manager::draw(sf::Text* text)
	{
		window->draw(*text);
	}

	sf::Texture* Graphical_Manager::load_texture(std::string path)
	{
		std::map<const std::string, sf::Texture*>::iterator it = textures.find(path);
		if (it != textures.end())
			return it->second;
		
		sf::Texture* texture = new sf::Texture();
		
		if (!texture->loadFromFile(path))
		{
			std::cout << "ERROR::ZELDA::Graphical_Manager unable to load texture" << std::endl;
			exit(1);
		}
		textures[path] = texture;
		return texture;
	}

	void Graphical_Manager::center(sf::Vector2f position1)
	{
		if (position1.x < WIDTH / 2)
		{
			view.setCenter(WIDTH / 2, position1.y-50.f);
		}
		else
		{
			view.setCenter(position1.x, position1.y-50.f);
		}
		window->setView(view);
	}

	void Graphical_Manager::center(sf::Vector2f position1, sf::Vector2f position2)
	{
		if (((position1.x + position2.x) / 2) < WIDTH / 2)
		{
			view.setCenter(WIDTH / 2, (position1.y + position2.y) / 2 - 50.f);
		}
		else
		{
			view.setCenter((position1.x + position2.x) / 2, (position1.y + position2.y) / 2 - 50.f);
		}
		window->setView(view);
	}

	void Graphical_Manager::resetView()
	{
		view.setCenter(WIDTH / 2, HEIGHT / 2);
		window->setView(view);
	}

	sf::RenderWindow* Graphical_Manager::getWindow() const
	{
		return window;
	}

	void Graphical_Manager::closeWindow()
	{
		window->close();
	}

	const bool Graphical_Manager::windowOpen()
	{
		return window->isOpen();
	}

	sf::Vector2f Graphical_Manager::getViewPosition()
	{
		return view.getCenter();
	}
}