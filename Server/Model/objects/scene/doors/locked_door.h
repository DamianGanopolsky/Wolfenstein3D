#ifndef LOCKED_DOOR_H_
#define LOCKED_DOOR_H_

#include "./../../object.h"

class LockedDoor: public Object {
    public:
        LockedDoor();
        ~LockedDoor();
        bool isOpened();
        void open();
        bool isItem() override;
        bool isBlocking() override;
        Item* getItem() override;
    private:
        int is_opened;
};

#endif    // LOCKED_DOOR_H_
