#include "../include/Graphical_Manager.h"

namespace Manager {
    Graphical_Manager* Graphical_Manager::instance = nullptr;

    Graphical_Manager::Graphical_Manager() {
        window = new sf::RenderWindow(sf::VideoMode(static_cast<unsigned int>(WIDTH), static_cast<unsigned int>(HEIGHT)), "Game Window");
        view = window->getDefaultView();
    }

    Graphical_Manager::~Graphical_Manager() {
        delete window;
        for (auto& pair : textures) {
            delete pair.second;
        }
    }

    Graphical_Manager* Graphical_Manager::getInstance() {
        if (instance == nullptr) {
            instance = new Graphical_Manager();
        }
        return instance;
    }

    void Graphical_Manager::show() {
        window->display();
    }

    void Graphical_Manager::clean() {
        window->clear();
    }

    void Graphical_Manager::draw(sf::RectangleShape body) {
        window->draw(body);
    }

    void Graphical_Manager::draw(sf::CircleShape body) {
        window->draw(body);
    }

    void Graphical_Manager::draw(sf::Text* text) {
        window->draw(*text);
    }

    void Graphical_Manager::draw(sf::Sprite& sprite) {
        window->draw(sprite);
    }

    sf::Texture* Graphical_Manager::load_texture(const std::string& path) {
        if (textures.find(path) == textures.end()) {
            sf::Texture* texture = new sf::Texture();
            if (!texture->loadFromFile(path)) {
                delete texture;
                return nullptr;
            }
            textures[path] = texture;
        }
        return textures[path];
    }

    void Graphical_Manager::center(sf::Vector2f position1) {
        view.setCenter(position1);
        window->setView(view);
    }

    void Graphical_Manager::center(sf::Vector2f position1, sf::Vector2f position2) {
        sf::Vector2f center = (position1 + position2) / 2.0f;
        view.setCenter(center);
        window->setView(view);
    }

    void Graphical_Manager::resetView() {
        window->setView(window->getDefaultView());
    }

    sf::RenderWindow* Graphical_Manager::getWindow() const {
        return window;
    }

    sf::Vector2f Graphical_Manager::getViewPosition() {
        return view.getCenter();
    }

    void Graphical_Manager::closeWindow() {
        window->close();
    }

    const bool Graphical_Manager::windowOpen() {
        return window->isOpen();
    }
}
