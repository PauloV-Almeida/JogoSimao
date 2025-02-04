#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"
#include <SFML/System/Vector2.hpp>

namespace Entidades {

	class Character : public Entity {
	private:
		int hp;
		int numLives;
		bool lookingLeft;

	public:
		Character();
		virtual ~Character();

		virtual void move();

		void setLookingLeft(bool lookingLeft);
	};


} // namespace Entities

#endif // CHARACTER_H
