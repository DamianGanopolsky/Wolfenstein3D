#ifndef COMMAND_STOP_ROTATING_H
#define COMMAND_STOP_ROTATING_H

#include "./command.h"

class CommandStopRotating : public Command {
    public:
        CommandStopRotating(ConnectionId id_caller);
        ~CommandStopRotating();
        void run(Game& game) override;
};

#endif