#ifndef __PLAYER_HANDLER_H__
#define __PLAYER_HANDLER_H__

#include "Player.h"
#include "Map_2d.h"
#include "ClientConnector/Sender.h"
#include "ClientConnector/ClientSocket.h"

class Player_handler {
public:
	Player_handler(Player& player,Map_2d& MAP);
	//Player_handler(Player_handler&& other);
	~Player_handler();

	bool handle();

private:
	// Es necesario protegerlos de race condition?
	Player& player;
	Map_2d& map;
	bool quit;
	bool moving;
	bool rotating;

	//ClientSocket& clisocket;
	//Sender sender;
	
};

#endif
