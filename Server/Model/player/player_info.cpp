#include "./player_info.h"
#include "../constants/config.h"

PlayerInfo::PlayerInfo() : life(100), bullets(8),
                            keys(0), treasure(0), 
                            resurrected(0),
                            kills(0) {
                                this->weapon_type.insert(std::make_pair<Weapon*, int>(&knife, KNIFE_TYPE));
                                this->weapon_type.insert(std::make_pair<Weapon*, int>(&gun, GUN_TYPE));
                                this->weapon_type.insert(std::make_pair<Weapon*, int>(&machine_gun, MACHINE_GUN_TYPE));
                                this->weapon_type.insert(std::make_pair<Weapon*, int>(&chain_cannon, CHAIN_CANNON_TYPE));
                                this->equiped = &gun;
                                this->inventory.push_back(GUN_TYPE);
                                this->inventory.push_back(KNIFE_TYPE);
                            }

PlayerInfo::~PlayerInfo(){}

int PlayerInfo::getLife() {
    return this->life;
}

int PlayerInfo::getNumBullets() {
    return this->bullets;
}

int PlayerInfo::getKey() {
    return this->keys;
}

int PlayerInfo::getTreasure() {
    return this->treasure;
}

int PlayerInfo::getNumResurrection() {
    return this->resurrected;
}

int PlayerInfo::getKills(){
    return this->kills;
}

Weapon* PlayerInfo::getWeaponEquiped() {
    return this->equiped;
}

int PlayerInfo::getWeaponTypeEquiped() {
    switch (this->weapon_type.at(this->equiped)) {
        case KNIFE_TYPE: {
            return KNIFE_TYPE;
        }
        case GUN_TYPE: {
            return GUN_TYPE;
        }
        case MACHINE_GUN_TYPE: {
            return MACHINE_GUN_TYPE;
        }
        case CHAIN_CANNON_TYPE: {
            return CHAIN_CANNON_TYPE;
        }
        default:
            break;
    }
    return -1;
}

std::list <int> PlayerInfo::getInventory() {
    return this->inventory;
}

void PlayerInfo::changeWeaponEquiped(const int& type) {
    for (auto& x: weapon_type) {
        if (x.second == type) {
            this->equiped = x.first;
        }
    }
}

bool PlayerInfo::hasWeapon(int weapon) {
    return (std::find(this->inventory.begin(), this->inventory.end(), weapon) != this->inventory.end());
}
