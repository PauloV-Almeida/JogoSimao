#include "../include/Ente.h"
#include "../include/Graphical_Manager.h" 
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <string>

int Ente::cont = 0; // Inicializando o membro cont
Manager::Graphical_Manager* Ente::pGM = nullptr;

Ente::Ente() : id(cont++) {
    pSprite = new sf::Sprite();
    pTexture = new sf::Texture();
    setTarget();
}

Ente::~Ente() {
    delete pSprite;
    delete pTexture;
    cont--;
}

void Ente::setGerenciadorGrafico(Manager::Graphical_Manager* ppGM) {
    if (ppGM != nullptr) {
        pGM = ppGM;
    }
}

void Ente::atualizaSprite(sf::Texture* pTexture) {
    std::clog << "funcao Ente::atualizaSprite" << std::endl;
    pSprite->setTexture(*pTexture);
    pSprite->setTextureRect(sf::IntRect(0, 0, 100, 100));
    pSprite->setScale(3.f, 3.f);
}

bool Ente::setTexture(const std::string& path) {
    if (pTexture->loadFromFile(path)) {
        atualizaSprite(pTexture);
        return true;
    }
    else {
        std::cerr << "Erro em loadFromFile" << std::endl;
        return false;
    }
}

sf::Sprite Ente::getSprite() { return *pSprite; }

void Ente::setTarget() {
    if (pGM) {
        pAlvo = pGM->getWindow();
    }
    else {
        std::cerr << "Erro em setTarget" << std::endl;
    }
}

void Ente::desenhar() {
    if (pGM) {
        pGM->draw(*pSprite); // Agora a função draw aceita sf::Sprite
    }
    else {
        std::clog << "Nullptr em desenharEnte" << std::endl;
    }
}

