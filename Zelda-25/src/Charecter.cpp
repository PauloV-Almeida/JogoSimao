#include "Entities/Characters/Character.h"
#include <SFML/System/Vector2.hpp>

using namespace Entities::Characters;

Character::Character()
    : Entity(), hp(100), numLives(3), lookingLeft(false) {}

Character::~Character() {}

void Character::move() {
    sf::Vector2f newPos = getPos() + (velocity * pGM->getDeltaTime());
    setPos(newPos);
    pSprite->setPosition(newPos);
}

void Character::setLookingLeft(bool lookingLeft) {
    this->lookingLeft = lookingLeft;
}