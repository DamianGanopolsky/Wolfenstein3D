#include "Player.h"
#include <utility>
#include <iostream>
#include <cmath>
#include <unistd.h>


#define ROTATION_SIZE 5.0
#define DISPLACEMENT 8
#define PI 3.14159265

Player::Player(New_Player_Event player_initial_info) :
				pos_x(player_initial_info.pos_x), pos_y(player_initial_info.pos_y),\
				 vision_angle(player_initial_info.angle),player_id(player_initial_info.player_id)\
				 ,info(player_initial_info.life,player_initial_info.resurrected,player_initial_info.score,\
				 player_initial_info.bullets) {
	
}

Player::~Player() {
}

int Player::get_id(){
	return player_id;
}

void Player::resurrect_player(New_Player_Event player_new_info){
	pos_x=player_new_info.pos_x;
	pos_y=player_new_info.pos_y;
	vision_angle=player_new_info.angle;
	info.update_info(player_new_info.life,player_new_info.resurrected,\
	player_new_info.score,player_new_info.bullets);
}

float Player::get_angle() const {
	return this->vision_angle;
}

int Player::get_pos_x() const {
	return this->pos_x;
}

int Player::get_pos_y() const {
	return this->pos_y;	
}

 
Player_info& Player::get_info() {
	return this->info;
}

void Player::add_bullets(int bullets){
	this->info.ammo = bullets;
}

void Player::change_health(int new_health){
	this->info.health=new_health;
}

void Player::change_score(int new_score){
	this->info.scores=new_score;
}

int Player::get_weapon(){
	return this->info.weapon;
}

void Player::update_position_and_angle(int X,int Y,float ANGLE){
	this->pos_x=X;
	this->pos_y=Y;
	this->vision_angle=ANGLE;
}

void Player::update_lives(int lives){
	this->info.lives=lives;
}

void Player::left_rotation() {
	float new_vision_angle = this->vision_angle + ROTATION_SIZE;
	this->vision_angle = new_vision_angle >= 360.0 ? new_vision_angle - 360.0 : new_vision_angle;
}

void Player::right_rotation() {
	float new_vision_angle = this->vision_angle - ROTATION_SIZE;
	this->vision_angle = new_vision_angle < 0.0 ? 360.0 + new_vision_angle : new_vision_angle;
}

void Player::move_up() {
	this->pos_x += (int) (DISPLACEMENT * cos(this->vision_angle * PI / 180.0));
	this->pos_y -= (int) (DISPLACEMENT * sin(this->vision_angle * PI / 180.0));
}

void Player::move_down() {
	this->pos_x -= (int) (DISPLACEMENT * cos(this->vision_angle * PI / 180.0));
	this->pos_y += (int) (DISPLACEMENT * sin(this->vision_angle * PI / 180.0));
}

void Player::move_left() {
	this->pos_x -= (int) (DISPLACEMENT * sin(this->vision_angle * PI / 180.0));
	this->pos_y -= (int) (DISPLACEMENT * cos(this->vision_angle * PI / 180.0));	
}	
void Player::move_right() {
	this->pos_x += (int) (DISPLACEMENT * sin(this->vision_angle * PI / 180.0));
	this->pos_y += (int) (DISPLACEMENT * cos(this->vision_angle * PI / 180.0));	
}

void Player::shoot(int bullets) {
	soundmanager.play_sound(info.weapon);
	switch(info.weapon){
		case 0:
		case 1:
		case 3:{
			this->info.weapon_status=2;
			break;
		}
		case 2:{
			this->info.weapon_status=6;
			break;
		}		
	}
	if(info.weapon!=0){
		this->info.ammo=bullets;
	} 
}

void Player::change_weapon(int weapon){
	this->info.weapon=weapon;
}