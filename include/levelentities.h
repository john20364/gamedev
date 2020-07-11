#ifndef _LEVEL_ENTITIES_H_
#define _LEVEL_ENTITIES_H_
#include <list>
#include "entity.h"

class LevelEntities {
public:
	static LevelEntities* getInstance();
	~LevelEntities();
	void destroy();
	void clearAllEntities();
	void clearEntities();
	void addEntity(Entity* entity);
	void updateEntities();
	void renderEntities();
	int sizeEntities();
private:
	static LevelEntities* instance;
	std::list<Entity*> entities;
	LevelEntities();
};
#endif
