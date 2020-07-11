#ifndef _SPAWN_LEVEL_H_
#define _SPAWN_LEVEL_H_
#include "level.h"
#include <sstream>

class SpawnLevel : public Level {
public:
	SpawnLevel(std::string path);	
	~SpawnLevel();
protected:
	void loadLevel(std::string path);
private:
};
#endif
