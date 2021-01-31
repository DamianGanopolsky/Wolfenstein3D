#ifndef __RECEIVER__
#define __RECEIVER__

#include "../Player.h"
#include "../Map_2d.h"
#include "../../Common/thread.h"
#include "../../Common/non_blocking_queue.h"
#include "../../Common/socket.h"
#include "ClientSocket.h"

class Receiver: public Thread {
public:
    Receiver():receiving(true){

    }

    void run() override;

    void stop();

private:
    bool receiving;
    //Player& player;
    //Map_2d& map;

};

#endif