#include <iostream>
#include "include/spawnfactory.h"
#include "include/levelentities.h"
#include "include/normalparticle.h"

SpawnFactory* SpawnFactory::instance = NULL;

SpawnFactory* SpawnFactory::getInstance() {
	if (instance == NULL) {
		instance = new SpawnFactory();
	}
	return instance;
}

void SpawnFactory::destroy() {
	if (instance) {
		delete instance;
		instance = NULL;
	}
}

void SpawnFactory::build(Type type, Level* level, void* data) { 
	if (type == Type::NORMAL_PARTICLE) {
		SpawnParticleData sd = *((SpawnParticleData*)data);
		for (int i = 0; i < sd.amount; ++i) {
			Entity* entity = NULL;
			entity = new NormalParticle(sd.x, sd.y, sd.xa, sd.ya, sd.life);
			if (entity) {
				entity->init(level);
				LevelEntities::getInstance()->addEntity(entity);
			}
		}	
	} else if (type == Type::MOB) {
	}
}

SpawnFactory::SpawnFactory() {
}

SpawnFactory::~SpawnFactory() {
}
