#ifndef ENTITYLIST_H
#define ENTITYLIST_H

#include "list.h"
namespace Entities {
    class Entity;
}
namespace Lists {

    class EntityList {
    private:
        List<Entities::Entity> entities;

    public:
        EntityList();
        ~EntityList();

        void include(Entities::Entity* pE);
        void remove(Entities::Entity* pE);
        int getSize() const;
        void clear();
        List<Entities::Entity>::Iterator<Entities::Entity> begin() const;
        List<Entities::Entity>::Iterator<Entities::Entity> end() const;
    };

}

#endif
