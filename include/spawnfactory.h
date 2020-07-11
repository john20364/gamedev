#ifndef _SPAWN_FACTORY_H_
#define _SPAWN_FACTORY_H_
#include "spawndata.h"

class SpawnFactory {
public:
	enum Type {NORMAL_PARTICLE, MOB};
	static SpawnFactory* getInstance();
	void build(Type type, Level* level, void* data);
	void destroy();
	~SpawnFactory();
private:
	static SpawnFactory* instance;
	SpawnFactory();
};
#endif
