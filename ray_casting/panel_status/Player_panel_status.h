#ifndef __STATUS_PANEL_H__
#define __STATUS_PANEL_H__

#include <SDL2/SDL.h>
#include "../Player_info.h"
#include <SDL2/SDL.h>
#include "Element_panel_status.h"

class Player_panel_status {
public:
	explicit Player_panel_status(SDL_Renderer*& renderer);
	Player_panel_status();
	Player_panel_status(Player_panel_status&& other);
	Player_panel_status& operator=(Player_panel_status&& other);
	~Player_panel_status();

	void copy_to_rederer(Player_info& player_info);
	SDL_Texture* get_texture(int value, int id);

private:
	SDL_Renderer* renderer;
	SDL_Texture* status_tex;
	Element_panel_status face_status;
	Element_panel_status weapon_status;
	Element_panel_status number_status;
	Element_panel_status guardia_status;

	void copy_to_rederer_weapon(int id);
	void copy_to_rederer_face(int health);
	void copy_to_rederer_lives(int lives);
	void copy_to_rederer_health(int health);
	void copy_to_rederer_ammo(int health);
	void copy_to_rederer_number(int number, int digits, SDL_Rect& SrcR, bool is_cero);
};

#endif
