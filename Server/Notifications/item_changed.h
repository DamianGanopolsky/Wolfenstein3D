#ifndef ITEM_CHANGED_H
#define ITEM_CHANGED_H

#include "notification.h"
#include "../../Common/protocol.h"
#include "./../Model/player/player.h"

class ItemChanged : public Notification {
    ItemOpcode item_type;
    Id map;
    Id player_id;
    uint32_t pos_x;
    uint32_t pos_y;
    uint32_t value;

    public:
        ItemChanged(const Id map, ItemOpcode item_type, Id player_id, 
                    uint32_t pos_x, uint32_t pos_y);
        ItemChanged(const Id map, ItemOpcode item_type, Id player_id, 
                    uint32_t pos_x, uint32_t pos_y, int value);
        virtual ~ItemChanged();
        
        ItemChanged(const ItemChanged&) = delete;
        ItemChanged& operator=(const ItemChanged&) = delete;
        ItemChanged(ItemChanged&& other) = delete;
        ItemChanged& operator=(ItemChanged&&) = delete;

        virtual bool send(const ConnectionId sender, const Socket& peer);
};

#endif