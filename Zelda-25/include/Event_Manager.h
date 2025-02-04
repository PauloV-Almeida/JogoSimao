#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "Graphical_Manager.h"
#include "Input_Manager.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>

namespace Entidades {
    class Player;

} // namespace Characters

namespace Manager {

    class EventManager {
    private:
        static EventManager* instance;

        sf::Window* pWindow;
        Graphical_Manager* pGM;
        InputManager* pIM;

    private:
        EventManager();
        ~EventManager();
        EventManager(const EventManager&) = delete;
        EventManager& operator=(const EventManager&) = delete;

    public:
        static EventManager* getInstance();

        void setGM(Graphical_Manager* pGM);
        void setIM(InputManager* pIM);
        void processEvents();
    };

}

#endif // EVENT_MANAGER_H
