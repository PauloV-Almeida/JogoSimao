#ifndef GRAPHICAL_MANAGER_H
#define GRAPHICAL_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>

#define WIDTH 800.0f
#define HEIGHT 600.0f

namespace Manager {
    class Graphical_Manager {
    private:
        sf::RenderWindow* window; // janela do jogo
        sf::View view; // câmera do jogo
        std::map<std::string, sf::Texture*> textures;

        // padrão singleton
        Graphical_Manager();
        static Graphical_Manager* instance;
    public:
        ~Graphical_Manager();
        static Graphical_Manager* getInstance();
        void show();
        void clean();
        void draw(sf::RectangleShape body);
        void draw(sf::CircleShape body);
        void draw(sf::Text* text);
        void draw(sf::Sprite& sprite); // Adicionando a sobrecarga para sf::Sprite
        sf::Texture* load_texture(const std::string& path);

        void center(sf::Vector2f position1);
        void center(sf::Vector2f position1, sf::Vector2f position2);
        void resetView();
        sf::RenderWindow* getWindow() const;
        sf::Vector2f getViewPosition();
        void closeWindow();
        const bool windowOpen();
    };
}

#endif // GRAPHICAL_MANAGER_H
