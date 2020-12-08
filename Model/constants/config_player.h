// ATENCION: config temporal (después pasar a formato YAML)

#ifndef CONFIG_PLAYER_H
#define CONFIG_PLAYER_H

// Player
#define MAX_RESURRECTIONS 2
#define SUCCESS_MSG "Success."
#define CANT_ATTACK_ITSELF_ERROR_MSG "ERROR: Player can't attack itself."
#define CANT_BE_ATTACKED_ERROR_MSG "ERROR: Player can't attack other player."
#define STATE_CANT_ATTACK_ERROR_MSG "ERROR: Player has a state that doesn't allow him to attack."
#define STATE_CANT_RESURRECT_ERROR_MSG "ERROR: Player has a state that doesn't allow him to resurrect."
#define MAX_RESURRECTIONS_REACHED_ERROR_MSG "ERROR: Player has already resurrected as many times as possible"
#endif