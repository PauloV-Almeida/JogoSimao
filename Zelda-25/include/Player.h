#ifndef PLAYER_H
#define PLAYER_H

#include "Control.h"
#include "Character.h"
#include "Event_Manager.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades{

#define SPEED 0.3f

	class Player : public Character {
	private:
		bool isFirstPlayer;

	protected:
		bool canJump;
		Controllers::PlayerController* pController;

	public:
		Player();
		~Player();

		void setFirstPlayer(bool isFirstPlayer);
		bool getFirstPlayer() const;

		void moveRight();
		void moveLeft();
		void stopMoving();
		void jump();
		void move();
		virtual void attack() = 0;
		virtual void execute();
		Controllers::PlayerController* getController() const;
	};

} // namespace Entities::Characters

#endif // PLAYER_H
