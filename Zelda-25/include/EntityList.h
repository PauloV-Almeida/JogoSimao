#ifndef ENTITYLIST_H
#define ENTITYLIST_H

#include "list.h"
namespace Entidades {
    class Entity;
}
namespace Lists {

    class EntityList {
    private:
        List<Entidades::Entity> entities;

    public:
        EntityList();
        ~EntityList();

        void include(Entidades::Entity* pE);
        void remove(Entidades::Entity* pE);
        int getSize() const;
        void clear();
        List<Entidades::Entity>::Iterator<Entidades::Entity> begin() const;
        List<Entidades::Entity>::Iterator<Entidades::Entity> end() const;
    };

}

#endif
