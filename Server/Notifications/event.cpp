#include "event.h"

Event::Event(const Id map, EventOpcode event_type, Id player_id,
            uint32_t pos_x, uint32_t pos_y, float angle, int is_moving, int is_shoting) : 
            map(map), event_type(event_type), player_id(player_id), pos_x(pos_x),
            pos_y(pos_y), angle(angle), is_moving(is_moving), is_shoting(is_shoting) {}

Event::Event(const Id map, EventOpcode event_type, Id player_id,
            uint32_t pos_x, uint32_t pos_y, float angle, int life, int resurrected,
            int treasure, int bullets) : 
            map(map), event_type(event_type), player_id(player_id), pos_x(pos_x),
            pos_y(pos_y), angle(angle), life(life), resurrected(resurrected),
            treasure(treasure), bullets(bullets) {}

Event::Event(const Id map, EventOpcode event_type, Id player_id, int is_shoting) : 
            map(map), event_type(event_type), player_id(player_id), 
            is_shoting(is_shoting) {}
Event::Event(const Id map, EventOpcode event_type, Id player_id, int life): 
            map(map), event_type(event_type), player_id(player_id),
            life(life) {}
Event::Event(const Id map, EventOpcode event_type, Id player_id,
            uint32_t pos_x, uint32_t pos_y) : 
            map(map), event_type(event_type), player_id(player_id),
            pos_x(pos_x), pos_y(pos_y) {}
Event::Event(const Id map, EventOpcode event_type, Id player_id, int weapon) : 
            map(map), event_type(event_type), player_id(player_id),
            weapon(weapon) {}

Event::~Event() {}
        
/*Event::Event(const Event& other) {
    this->map = other.map;
    this->player = other.player;
    this->event_type = other.event_type;
}

Event& Event::operator=(const Event& other) {
    this->map = other.map;
    this->player = other.player;
    this->event_type = other.event_type;
    return *this;
}*/

bool Event::send(const ConnectionId sender, const Socket& peer) {
    try{
        uint8_t buffer[2];
        buffer[0] = EVENT_OPCODE;
        buffer[1] = event_type;
        peer.send((char *)buffer, 2);
        switch (event_type) {
            case MOVEMENT_EV: { //id del jugador, coordenada x, coordenada y, angulo del jugador, moviendo (1-si o 0-no), disparando (si o no)
                this->player_id = htole32(this->player_id);
                peer.send((char *)&player_id, sizeof(player_id));
                this->pos_x = htole32(this->pos_x);
                this->pos_y = htole32(this->pos_y);
                peer.send((char *)&pos_x, sizeof(pos_x));
                peer.send((char *)&pos_y, sizeof(pos_y));
                peer.send((char *)&angle, sizeof(angle));
                peer.send((char *)&is_moving, sizeof(is_moving));
                peer.send((char *)&is_shoting, sizeof(is_shoting));
                break;
            }
            case (NEW_PLAYER_EV | RESURRECT_EV) : { //id del jugador, id del mapa a abrir, coordenada x, coordenada y, angulo del jugador,vida , las vidas, puntaje, balas
                this->player_id = htole32(this->player_id);
                peer.send((char *)&player_id, sizeof(player_id));
                this->map = htole32(this->map);
                peer.send((char *)&map, sizeof(map));
                this->pos_x = htole32(this->pos_x);
                this->pos_y = htole32(this->pos_y);
                peer.send((char *)&pos_x, sizeof(pos_x));
                peer.send((char *)&pos_y, sizeof(pos_y));
                peer.send((char *)&angle, sizeof(angle));
                peer.send((char *)&life, sizeof(life));
                peer.send((char *)&resurrected, sizeof(resurrected));
                peer.send((char *)&treasure, sizeof(treasure));
                peer.send((char *)&bullets, sizeof(bullets));
                break;
            }
            case DELETE_PLAYER_EV: { //id del jugador
                this->player_id = htole32(this->player_id);
                peer.send((char *)&player_id, sizeof(player_id));
                break;
            }
            case ATTACK_EV: { //id del jugador, disparando (si o no)
                this->player_id = htole32(this->player_id);
                peer.send((char *)&player_id, sizeof(player_id));
                peer.send((char *)&is_shoting, sizeof(is_shoting));
                break;
            }
            case BE_ATTACKED_EV: { //id del jugador, entero con la vida que tengo( la que voy a mostrar)
                this->player_id = htole32(this->player_id);
                peer.send((char *)&player_id, sizeof(player_id));
                peer.send((char *)&life, sizeof(life));
                break;
            }
            case DEATH_EV: { //id del jugador, coordenada x, coordenada y (la llegada de este evento tambien implica que se dropean los objetos a la hora de la muerte)
                this->player_id = htole32(this->player_id);
                peer.send((char *)&player_id, sizeof(player_id));
                this->map = htole32(this->map);
                peer.send((char *)&map, sizeof(map));
                this->pos_x = htole32(this->pos_x);
                this->pos_y = htole32(this->pos_y);
                break;
            }
            case CHANGE_WEAPON_EV: { //id del jugador, {0,1,2,3} 0=CUCHILLO, 1=pistola, ...
                this->player_id = htole32(this->player_id);
                peer.send((char *)&player_id, sizeof(player_id));
                peer.send((char *)&weapon, sizeof(weapon));
                break;
            }
            default:
                throw Exception("Unknown event type.");
                break;
            }

    } catch (const std::exception& e) {
        return false;
    }
    return true;
}