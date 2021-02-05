#include "event.h"

Event::Event(const Id map, EventOpcode event_type, Id player_id,
            uint32_t pos_x, uint32_t pos_y, float angle, int is_moving, int is_shoting) : 
            map(map), event_type(event_type), player_id(player_id), pos_x(pos_x),
            pos_y(pos_y), angle(angle), is_moving((uint8_t)is_moving),
            is_shoting((uint8_t)is_shoting) {}

Event::Event(const Id map, EventOpcode event_type, Id player_id,
            uint32_t pos_x, uint32_t pos_y, float angle, int life, int resurrected,
            int treasure, int bullets) : 
            map(map), event_type(event_type), player_id(player_id), pos_x(pos_x),
            pos_y(pos_y), angle(angle), life((uint32_t)life), resurrected((uint8_t)resurrected),
            treasure((uint32_t)treasure), bullets((uint32_t)bullets) {}

Event::Event(const Id map, EventOpcode event_type, Id player_id, int value) : 
            map(map), event_type(event_type), player_id(player_id), 
            value((uint32_t)value) {}
Event::Event(const Id map, EventOpcode event_type, Id player_id,
            uint32_t pos_x, uint32_t pos_y) : 
            map(map), event_type(event_type), player_id(player_id),
            pos_x(pos_x), pos_y(pos_y) {}

Event::~Event() {}
        
Event::Event(const Event& other) {
    this->map = other.map;
    this->event_type = other.event_type;
    this->player_id = other.player_id;
    this->pos_x = other.pos_x;
    this->pos_y = other.pos_y;
    this->angle = other.angle;
    this->is_moving = other.is_moving;
    this->is_shoting = other.is_shoting;
    this->life = other.life;
    this->resurrected = other.resurrected;
    this->treasure = other.treasure;
    this->bullets = other.bullets;
    this->value = other.value;
}

Event& Event::operator=(const Event& other) {
    this->map = other.map;
    this->event_type = other.event_type;
    this->player_id = other.player_id;
    this->pos_x = other.pos_x;
    this->pos_y = other.pos_y;
    this->angle = other.angle;
    this->is_moving = other.is_moving;
    this->is_shoting = other.is_shoting;
    this->life = other.life;
    this->resurrected = other.resurrected;
    this->treasure = other.treasure;
    this->bullets = other.bullets;
    this->value = other.value;
    return *this;
}

bool Event::send(const ConnectionId sender, const Socket& peer) {
    std::cout <<"Event: comienza el send()"<< std::endl;
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
            case NEW_PLAYER_EV:
            case RESURRECT_EV: { //id del jugador, id del mapa a abrir, coordenada x, coordenada y, angulo del jugador,vida , las vidas, puntaje, balas
                /*uint32_t buff_player_id[1];
                uint32_t buff_map[1];
                uint32_t buff_pos_x[1];
                uint32_t buff_pos_y[1];
                float buff_angle[1];
                uint32_t buff_life[1];
                uint8_t buff_resurrected[1];
                uint32_t buff_treasure[1];
                uint32_t buff_bullets[1];
                this->player_id = htole32(this->player_id);
                buff_player_id[0] = player_id;
                peer.send((char *)buff_player_id, sizeof(buff_player_id));
                std::cout << "player_id es: " << player_id <<std::endl;
                this->map = htole32(this->map);
                buff_map[0] = map;
                peer.send((char *)buff_map, sizeof(buff_map));
                std::cout << "map es: " << map <<std::endl;
                this->pos_x = htole32(this->pos_x);
                buff_pos_x[0] = pos_x;
                peer.send((char *)buff_pos_x, sizeof(buff_pos_x));
                std::cout << "posx es: " << pos_x <<std::endl;
                this->pos_y = htole32(this->pos_y);
                buff_pos_y[0] = pos_y;
                peer.send((char *)buff_pos_y, sizeof(buff_pos_y));
                std::cout << "posy es: " << pos_y <<std::endl;
                buff_angle[0] = angle;
                peer.send((char *)buff_angle, sizeof(buff_angle));
                buff_life[0] = life;
                this->life = htole32(this->life);
                peer.send((char *)buff_life, sizeof(buff_life));
                std::cout << "life es: " << life <<std::endl;
                buff_resurrected[0] = resurrected;
                peer.send((char *)buff_resurrected, sizeof(buff_resurrected));
                std::cout << "resurrected es: " << (unsigned)resurrected <<std::endl;
                this->treasure = htole32(this->treasure);
                buff_treasure[0] = treasure;
                peer.send((char *)buff_treasure, sizeof(buff_treasure));
                std::cout << "treasure es: " << treasure <<std::endl;
                this->bullets = htole32(this->bullets);
                buff_bullets[0] = bullets;
                peer.send((char *)buff_bullets, sizeof(buff_bullets));
                std::cout << "bullets es: " << bullets <<std::endl;*/
                this->player_id = htole32(this->player_id);
                peer.send((char *)&player_id, sizeof(player_id));
                std::cout << "player_id es: " << player_id <<std::endl;
                this->map = htole32(this->map);
                peer.send((char *)&map, sizeof(map));
                std::cout << "map es: " << map <<std::endl;
                this->pos_x = htole32(this->pos_x);
                this->pos_y = htole32(this->pos_y);
                peer.send((char *)&pos_x, sizeof(pos_x));
                std::cout << "posx es: " << pos_x <<std::endl;
                peer.send((char *)&pos_y, sizeof(pos_y));
                std::cout << "posy es: " << pos_y <<std::endl;
                peer.send((char *)&angle, sizeof(angle));
                std::cout << "angle es: " << angle <<std::endl;
                this->life = htole32(this->life);
                peer.send((char *)&life, sizeof(life));
                std::cout << "life es" << life <<std::endl;
                peer.send((char *)&resurrected, sizeof(resurrected));
                std::cout << "resurrected es: " << (unsigned)resurrected <<std::endl;
                this->treasure = htole32(this->treasure);
                peer.send((char *)&treasure, sizeof(treasure));
                std::cout << "treasure es: " << treasure <<std::endl;
                this->bullets = htole32(this->bullets);
                peer.send((char *)&bullets, sizeof(bullets));
                std::cout << "bullets es: " << bullets <<std::endl;
                break;
            }
            case DELETE_PLAYER_EV: { //id del jugador
                this->player_id = htole32(this->player_id);
                peer.send((char *)&player_id, sizeof(player_id));
                break;
            }
            case ATTACK_EV:
            case BE_ATTACKED_EV:
            case CHANGE_WEAPON_EV: { //id del jugador, disparando (si o no)
                this->player_id = htole32(this->player_id);
                peer.send((char *)&player_id, sizeof(player_id));
                this->value = htole32(this->value);
                peer.send((char *)&value, sizeof(value));
                break;
            }
            case DEATH_EV: { //id del jugador, coordenada x, coordenada y (la llegada de este evento tambien implica que se dropean los objetos a la hora de la muerte)
                this->player_id = htole32(this->player_id);
                peer.send((char *)&player_id, sizeof(player_id));
                this->pos_x = htole32(this->pos_x);
                this->pos_y = htole32(this->pos_y);
                peer.send((char *)&pos_x, sizeof(pos_x));
                peer.send((char *)&pos_y, sizeof(pos_y));
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