#ifndef _RANDOM_LEVEL_H_
#define _RANDOM_LEVEL_H_
#include "level.h"

class RandomLevel: public Level {
public:
	RandomLevel(int width, int height);
	~RandomLevel();
protected:
	void generateLevel();
};
#endif
