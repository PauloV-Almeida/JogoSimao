#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"
#include <SFML/System/Vector2.hpp>

namespace Entities {

	namespace Characters {

		class Character : public Entities::Entity {
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

	} // namespace Characters

} // namespace Entities

#endif // CHARACTER_H

