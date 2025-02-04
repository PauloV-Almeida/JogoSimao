#include "EntityList.h"

namespace Lists {

	EntityList::EntityList() : entities() {}
	EntityList::~EntityList() { entities.clear(); }
	void EntityList::include(Entities::Entity* pE) { entities.include(pE); }
	void EntityList::remove(Entities::Entity* pE) { entities.remove(pE); }
	const int EntityList::getSize() const { return entities.getSize(); }
	void EntityList::clear() { entities.clear(); }
	List<Entities::Entity>::Iterator EntityList::begin() const {
		return entities.begin();
	}
	List<Entities::Entity>::Iterator EntityList::end() const {
		return entities.end();
	}
}
