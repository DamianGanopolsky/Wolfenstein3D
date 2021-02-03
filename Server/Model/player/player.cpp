#include "player.h"


Player::Player(std::string& nickname, Id id_player) :  
                player_id(id_player), pos(), 
                info(), state(new Alive(id_player)),
                nickname(nickname), alive(true), 
                moving(false), rotating(false), 
                shooting(false) {}

Player::Player(int pos_x, int pos_y, std::string& nickname, 
                Id id_player) : 
                player_id(id_player), pos(), 
                info(), state(new Alive(id_player)),
                nickname(nickname), alive(true), 
                moving(false), rotating(false), 
                shooting(false) {}

Player::~Player() {
    delete this->state;
}

void Player::_die() {
    delete this->state;
    this->state = new Dead(this->player_id);
    this->alive = false;
    //Drop droper;
    /*if (droper.drop(this->info, this->info.getWeaponEquiped())) {
        //map.addItem(posx, posy, target->info.getWeaponEquiped());
    }
    if (droper.drop(this->info, bullet)) {
        //map.addItem(posx, posy, bullet);
    }
    if (droper.drop(this->info, key)) {
        int num_keys = this->info.getKey();
        for (int i = 0; i<= num_keys; i++) {
            //map.addItem(posx, posy, key);
        }
    }
    if (droper.drop(this->info, corpse)) {
        //map.addItem(posx, posy, corpse);
    }*/
}
Response Player::_updateMovement() {
    /*std::pair<int, int> next_pos = this->getPos().getNextPos(this->getPos().getDirection());
    Response can_move = _canMove(map, player, next_pos);
    if (can_move.success && ((can_move.message) !=  NO_ITEM_PICKED_UP_MSG)) {
        _notifyMovementEvent(id, player.update(iteration));
         _notifyItemChanged(id, can_move, _getItemOpcode(can_move.message));
    } else if (can_move.success) {
        _notifyMovementEvent(id, player.update(iteration));
    } else {
        _notifyMovementEvent(id, Response(false, CANT_MOVE_UP_ERROR_MSG));
    }*/
    return Response(true, SUCCESS_MSG);
}

Response Player::_updateRotation() {
    return Response(true, SUCCESS_MSG);
}

PlayerPosition Player::getPos() {
    return this->pos;
}

PlayerInfo Player::getInfo() {
    return this->info;
}

State* Player::getState() {
    return this->state;
}

std::string Player::getNickname() {
    return this->nickname;
}

bool Player::isAlive() {
    return this->alive;
}

bool Player::isMoving() {
    return this->moving;
}

bool Player::isShooting() {
    return this->shooting;
}
Response Player::update(int iteration) {
    //cosas de cooldown
    if (this->moving) {
        return (_updateMovement());
    }
    if (this->rotating) {
        return (_updateRotation());
    }
    //sacar esto:
    return Response(SUCCESS_MSG, SUCCESS_MSG);
}

Response Player::startMovingUp() {
    if (!this->state->canMove()) {
        return Response(false, CANT_MOVE_UP_ERROR_MSG);
    }
    this->pos.changeDirection(UP_DIR);
    this->moving = true;
    return Response(true, SUCCESS_MSG);
}

Response Player::startMovingDown() {
    if (!this->state->canMove()) {
        return Response(false, CANT_MOVE_DOWN_ERROR_MSG);
    }
    this->pos.changeDirection(DOWN_DIR);
    this->moving = true;
    return Response(true, SUCCESS_MSG);
}

Response Player::startMovingRight() {
    if (!this->state->canMove()) {
        return Response(false, CANT_MOVE_RIGHT_ERROR_MSG);
    }
    this->pos.changeDirection(RIGHT_DIR);
    this->moving = true;
    return Response(true, SUCCESS_MSG);
}

Response Player::startMovingLeft() {
    if (!this->state->canMove()) {
        return Response(false, CANT_MOVE_LEFT_ERROR_MSG);
    }
    this->pos.changeDirection(LEFT_DIR);
    this->moving = true;
    return Response(true, SUCCESS_MSG);
}

Response Player::stopMoving() {
    this->moving = false;
    return Response(true, SUCCESS_MSG);
}

Response Player::startRotatingLeft() {
    this->pos.changeRotation(LEFT_ROTATION_DIR);
    this->rotating = true;
    return Response(true, SUCCESS_MSG);
}

Response Player::startRotatingRight() {
    this->pos.changeRotation(RIGHT_ROTATION_DIR);
    this->rotating = true;
    return Response(true, SUCCESS_MSG);
}

Response Player::stopRotating() {
    this->rotating = false;
    return Response(true, SUCCESS_MSG);
}

Response Player::useWeapon(Id id, Id id_target, Player* target, int& damage) {
    if (this == target) {
        Response(false, CANT_ATTACK_ITSELF_ERROR_MSG);
    }
    if (!target->getState()->canBeAttacked()) {
        Response(false, CANT_BE_ATTACKED_ERROR_MSG);
    }
    Weapon* weapon = this->getInfo().getWeaponEquiped();
    weapon->attack(damage);
    target->receiveAttack(damage);
    return Response(true, SUCCESS_MSG);
}

Response Player::receiveAttack(int& damage) {
    this->info.reduceLife(damage);
    if (this->info.getLife() == 0) {
        this->_die();
        return Response(true, PLAYER_DIED_MSG);
    }
    return Response(true, SUCCESS_MSG);
}

Response Player::resurrect() {
    if(!this->state->resurrect()) {
        return Response(false, STATE_CANT_RESURRECT_ERROR_MSG);
    } else if (this->info.getNumResurrection() == MAX_RESURRECTIONS) {
       return Response(false, MAX_RESURRECTIONS_REACHED_ERROR_MSG); 
    }
    delete this->state;
    this->state = new Alive(this->player_id);
    return Response(true, SUCCESS_MSG);
    //poner todos los valores iniciales de vida, balas, etc
}

Response Player::changeWeapon(Weapon* weapon) {
    if(this->info.hasWeapon(weapon)){
        this->info.changeWeaponEquiped(weapon);
        return Response(true, SUCCESS_MSG);
    }
    return Response(false, NO_WEAPON_IN_INVENTORY_ERROR_MSG);
}