#include "Player.h"
#include "Character.h"
#include <SFML/System/Vector2.hpp>

using namespace Entities::Characters;

Player::Player()
    : Character(), pController(nullptr), canJump(true), isFirstPlayer(true) {

    pController = new Controllers::PlayerController();
}

Player::~Player() {}

void Player::setFirstPlayer(bool isFirstPlayer) {
    this->isFirstPlayer = isFirstPlayer;
}

bool Player::getFirstPlayer() const { return isFirstPlayer; }

void Player::moveRight() { setVelX(SPEED); }

void Player::moveLeft() { setVelX(-SPEED); }

void Player::stopMoving() { setVelX(0); }

void Player::jump() {
    if (canJump) {
        setVelY(-2 * SPEED);
    }
}

void Player::move() {
    sf::Vector2f newPos = getPos() + getVel() * pGM->getDeltaTime();
    setPos(newPos);
    pSprite->setPosition(newPos);
}

Controllers::PlayerController* Player::getController() const {
    return pController;
}

void Player::execute() {

    pController->controlPlayer();

    if (!isOnGround())
        fall();

    move();
}

