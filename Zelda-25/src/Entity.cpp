#include "../include/Ente.h"
#include "../include/list.h"
#include "../include/Graphical_Manager.h"

Manager::Graphical_Manager* Ente::pGM = Manager::Graphical_Manager::getInstance();

Ente::Ente() {
}

Ente::~Ente() {
}

// Implementação de uma classe derivada de Ente para exemplificar
class Entity : public Ente {
private:
    int id;
    std::string name;
public:
    Entity(int id, const std::string& name) : id(id), name(name) {}
    ~Entity() {}

    void run() override {
        // Exemplo de uso do Graphical_Manager
        sf::RectangleShape shape(sf::Vector2f(100.f, 100.f));
        shape.setFillColor(sf::Color::Green);
        pGM->draw(shape);
        pGM->show();
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    std::string getName() const {
        return name;
    }

    void setName(const std::string& name) {
        this->name = name;
    }
};

// Exemplo de uso da lista com a classe Entity
void exampleUsage() {
    Lists::List<Entity> entityList;
    Entity* entity1 = new Entity(1, "Entity1");
    Entity* entity2 = new Entity(2, "Entity2");

    entityList.push(entity1);
    entityList.push(entity2);

    for (auto it = entityList.get_first(); it != nullptr; ++it) {
        (*it)->run();
    }

    entityList.clear();
}