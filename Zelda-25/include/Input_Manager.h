#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include "Subject.h"
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>
#include <map>
#include <string>

namespace Controllers {
	class PlayerController;
} // namespace Controllers

namespace Manager {

	class InputManager : public Observers::Subject {
	private:
		static InputManager* instance;
		std::map<sf::Keyboard::Key, std::string> keyMap;

	private:
		InputManager();
		~InputManager();
		InputManager(const InputManager&) = delete;
		InputManager& operator=(const InputManager&) = delete;

	public:
		static InputManager* getInstance();

		void ProcessKeyPressed(sf::Keyboard::Key key);
		void ProcessKeyReleased(sf::Keyboard::Key key);
	};

} // namespace Managers

#endif // __INPUT_MANAGER_H__
