#ifndef ENTE_H
#define ENTE_H

#include <SFML/Graphics.hpp>
#include "IDs.h"

namespace Manager {
    class Graphical_Manager; // Declaração antecipada
}

class Ente {
protected:
    static Manager::Graphical_Manager* pGM;
    sf::Sprite* pSprite;
    sf::Texture* pTexture;
    sf::RenderWindow* pAlvo;
    const int id;
    static int cont; // Adicionando a declaração do membro cont

public:
    Ente();
    virtual ~Ente();

    virtual void execute() = 0; // Adicionando o método virtual puro

    void setGerenciadorGrafico(Manager::Graphical_Manager* ppGM);
    void atualizaSprite(sf::Texture* pTexture);
    bool setTexture(const std::string& path);
    sf::Sprite getSprite();
    void setTarget();
    void desenhar();
};

#endif // ENTE_H

