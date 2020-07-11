#ifndef _LEVELS_H_
#define _LEVELS_H_
#include "level.h"

class Levels {
public:
	static Levels* getInstance();
	void destroy();
	~Levels();
	Level* spawn;
private:
	Levels();
	static Levels* instance;
};
#endif
