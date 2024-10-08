#ifndef __CLIENTMANAGER_H__
#define __CLIENTMANAGER_H__

#include "Panel_window.h"
#include "Player.h"
#include "Player_info.h"
#include "Player_handler.h"
#include "ClientConnector/Receiver.h"
#include "ClientConnector/Sender.h"
#include "ClientConnector/ClientSocket.h"
#include "SdlClasses/MusicSoundtrack.h"
#include "../Common/thread.h"
#include "ClientConnector/ReceiveController.h"
#include "../Common/blocking_queue.h"
#include "Client.h"
#include <iostream>
#include "Yaml/YamlConfigClient.h"

class ClientManager {
public:
    ClientManager(std::string Host,std::string Port,std::string Nickname);

    void start();

    ~ClientManager();
private:
    std::string host;
    std::string port;
    std::string nickname;
};








#endif