#include "../include/Entity.h"

namespace Entities {

    Entity::Entity() : onGround(false), buffer(nullptr), id(IDs::IDs::vazio) {
        pSprite = new sf::Sprite();
        pTexture = new sf::Texture();
        setTarget();
    }

    Entity::~Entity() {
        delete pSprite;
        delete pTexture;
    }

    void Entity::setVelocity(sf::Vector2f newVelocity) {
        velocity = newVelocity;
    }

    void Entity::setVelocityX(float velX) {
        velocity.x = velX;
    }

    void Entity::setVelocityY(float velY) {
        velocity.y = velY;
    }

    void Entity::setPosition(sf::Vector2f newPosition) {
        position = newPosition;
        pSprite->setPosition(position);
    }

    void Entity::setOnGround(bool onGround) {
        this->onGround = onGround;
    }

    sf::Vector2f Entity::getVelocity() const {
        return velocity;
    }

    sf::Vector2f Entity::getPosition() const {
        return position;
    }

    bool Entity::isOnGround() const {
        return onGround;
    }

    sf::Vector2f Entity::getSize() const {
        return size;
    }

    void Entity::fall() {
        if (!onGround) {
            velocity.y += GRAVITY_VALUE; // Usando a constante global GRAVITY_VALUE
        }
    }

    void Entity::execute() {
        // Implementação do método execute
    }

} // namespace Entities

