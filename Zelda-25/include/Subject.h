#ifndef SUBJECT_H
#define SUBJECT_H

#include <SFML/Window/Keyboard.hpp>
#include <set>

class Observer;

class Subject {
public:
    std::set<Observer*>* observers;

public:
    virtual ~Subject();

    virtual void subscribe(Observer* o);
    virtual void unsubscribe(Observer* o);

    virtual void notifyKeyPressed(sf::Keyboard::Key key);
    virtual void notifyKeyReleased(sf::Keyboard::Key key);

protected:
    Subject();
};

#endif // SUBJECT_H