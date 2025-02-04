#ifndef ENTITY_H
#define ENTITY_H

#include "Ente.h"
#include "IDs.h"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace Entidades {

    const float GRAVITY_VALUE = 10.0f; // Constante global de gravidade

    class Entity : public Ente {
    private:
        sf::Vector2f position;
        sf::Vector2f size;
        bool onGround;
        std::ostream* buffer;
        IDs::IDs id; // Adicionando ID de IDs.h

    protected:
        sf::Vector2f velocity;

    public:
        Entity();
        virtual ~Entity();

        void setVelocity(sf::Vector2f newVelocity);
        void setVelocityX(float velX);
        void setVelocityY(float velY);
        void setPosition(sf::Vector2f newPosition);
        void setOnGround(bool onGround);

        sf::Vector2f getVelocity() const;
        sf::Vector2f getPosition() const;
        bool isOnGround() const;
        sf::Vector2f getSize() const;

        void fall();
        virtual void execute() override; // Garantindo que execute seja substituído
    };

} // namespace Entities

#endif // ENTITY_H

