#ifndef ENTITY_H
#define ENTITY_H

#include "Ente.h"
#include <string>

class Entity : public Ente {
private:
    int id;
    std::string name;

public:
    // Construtor com parâmetros
    Entity(int id = 0, const std::string& name = "Unnamed");

    // Destrutor
    ~Entity();

    // Método run sobrescrito
    void run() override;

    // Getters e Setters
    int getId() const;
    void setId(int id);

    std::string getName() const;
    void setName(const std::string& name);
};

#endif