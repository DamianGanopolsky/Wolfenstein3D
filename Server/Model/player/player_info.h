#ifndef PLAYER_INFO_H_
#define PLAYER_INFO_H_

#include <list>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include "../objects/items/weapons/weapon.h"
#include "../objects/items/weapons/gun.h"
#include "../objects/items/weapons/knife.h"
#include "../objects/items/weapons/machine_gun.h"
#include "../objects/items/weapons/chain_cannon.h"
#include "../constants/YamlConfig.h"

class PlayerInfo {
   friend class Player;
   private:
      int life;
      int bullets;
      int keys;
      int treasure;
      int resurrected;
      int kills;
      Weapon* equiped;
      Knife knife;
      Gun gun;
      MachineGun machine_gun;
      ChainCannon chain_cannon;
      std::list <int> inventory;
      std::unordered_map<Weapon*, int> weapon_type;
   
   public:
      explicit PlayerInfo();
      ~PlayerInfo();
      int getLife();
      int getNumBullets();
      int getKey();
      int getTreasure();
      int getNumResurrection();
      int getKills();
      Weapon* getWeaponEquiped();
      int getWeaponTypeEquiped();
      void changeWeaponEquiped(const int& type);
      std::list <int>getInventory();
      bool hasWeapon(int weapon);
};

#endif    // PLAYER_INFO_H_
