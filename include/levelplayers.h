#pragma once
#include <list>
#include "player.h"

class LevelPlayers {
public:
	static LevelPlayers* getInstance();
	~LevelPlayers();
	void destroy();
	void clearAllPlayers();
	void clearPlayers();
	void addPlayer(Player* player);
	void updatePlayers();
	void renderPlayers();
	int sizePlayers();
	Player* getFrontPlayer();
	void setFrontPlayer(Player* player);
	std::list<Player*> getPlayers(Entity* entity, int range);
private:
	std::list<Player*> players;
	static LevelPlayers* instance;
	LevelPlayers();
};
