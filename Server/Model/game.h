#ifndef GAME_H
#define GAME_H

#include <unordered_map>
#include <string>
#include <algorithm>

class ClientsConnected;
#include "./../Notifications/event.h"
#include "./../Notifications/item_changed.h"
#include "../../Common/defs.h"
#include "./map/map.h"
#include "./map/object_map.h"
#include "./constants/const_object_map.h"
#include "./player/player.h"
#include "./interactor.h"
#include "./post_game.h"

class Game {
    std::string map_Yaml;
    std::string path_Yaml;
    std::unordered_map<ConnectionId, Player> players;
    std::unordered_map<ConnectionId, std::string> players_by_name;
    std::unordered_map<ConnectionId, std::pair<int, int>> players_in_map;
    std::unordered_map<ConnectionId, std::pair<int, int>> respawn_positions;
    ClientsConnected& clients_connected;
    PostGame post_game;
    Id map_id;
    Map map;
    bool game_ended;
    ObjectMap objMap;
    int rate;
    int height;
    int width;

    void _notifyEvent(const ConnectionId id, const Response& response, EventOpcode event_type);
    //void _notifyResponse(const ConnectionId id, const Response& response);
    void _notifyItemChanged(const ConnectionId id, ItemOpcode item_type);
    void _notifyItemDropped(const ConnectionId id, ItemOpcode item_type, int x, int y);
    void _notifyMovementEvent(const ConnectionId id, const Response& response);
    void _notifyChangeWeaponEvent(const ConnectionId id, const Response& response, int weapon);
    Response _canMove(Map& map, Player& player, std::pair<int, int> next_pos);
    bool _changeCell(PlayerPosition &pos, std::pair<int, int> &next_pos);
    //ItemOpcode _getItemOpcode(const char* message); ///falta implmentar
    bool _interactWith(Player& player, Map map, Object* obj);///falta implmentar
    void _getPlayerPosition(ConnectionId new_player_id);
    void _attack(const ConnectionId id, int iteration);
    std::pair<ConnectionId, double> _getTargetAttacked(ConnectionId attacker_id);
    void _reduceBullets(const ConnectionId id);
    void _move(const ConnectionId id);
    void _deletePlayer(ConnectionId id);
    bool is_player_target(int pos_x_attacker, int pos_y_attacker, float vision_angle_attacker, \
        int pos_x_other_player,int pos_y_other_player);
    void _dropItems(ConnectionId id, int pos_x, int pos_y);
    std::pair<int, int> _getNearestCellEmpty(int pos_x, int pos_y);
    void _playerDied(const ConnectionId id, Response& response);

    public:
        Game(ClientsConnected& clients_connected, std::string map_Yaml, int& rate);
        ~Game();

        Game(const Game&) = delete;
        Game& operator=(const Game&) = delete;
        Game(Game&& other) = delete;
        Game& operator=(Game&& other) = delete;

        void newPlayer(const ConnectionId id, std::string& nickname);
        void notifyNewPlayer(const ConnectionId id);
        void deletePlayer(const ConnectionId id);
        bool updatePlayers(int& iteration);

        void updateOpenDoorsLifetime(const int iteration);

        void startMovingUp(const ConnectionId id);
        void startMovingDown(const ConnectionId id);
        void startMovingLeft(const ConnectionId id);
        void startMovingRight(const ConnectionId id);
        void stopMoving(const ConnectionId id);
        void startRotatingLeft(const ConnectionId id);
        void startRotatingRight(const ConnectionId id);
        void stopRotating(const ConnectionId id);
        void startShooting(const ConnectionId id);
        void stopShooting(const ConnectionId id);
        void openDoor(const ConnectionId id);
        void changeWeapon(const ConnectionId id, const int& weapon);
        bool receiveAttack(const ConnectionId, int& damage);


};

#endif