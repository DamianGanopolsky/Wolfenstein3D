#include "YamlParser.h"
#include <iostream>
#include "../Server/Model/constants/const_object_map.h"

#define CUADRICULA 64


std::string jugadores[]{"0","1"};

YamlParser::YamlParser(std::string YamlPath){

}


std::map <std::pair<int,int>,int> YamlParser::load_map(std::string YamlPath){

    map= YAML::LoadFile(YamlPath);
    /* Chain Cannon */
    const YAML::Node& chain_cannon = map["Map"]["Chain_Cannon"];
    std::pair<int,int> map_position;
    for (YAML::const_iterator it = chain_cannon["position"].begin(); it != chain_cannon["position"].end(); ++it) {
        
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,MAP_CHAIN_CANNON});
    }

    const YAML::Node& door= map["Map"]["Door"];
    for (YAML::const_iterator it = door["position"].begin(); it != door["position"].end(); ++it) {
        
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,MAP_LOCKED_DOOR});
    }

    const YAML::Node& food= map["Map"]["Food"];
    for (YAML::const_iterator it = food["position"].begin(); it != food["position"].end(); ++it) {
        
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,MAP_FOOD});
    }

    const YAML::Node& medical_kit= map["Map"]["Medical_Kit"];
    for (YAML::const_iterator it = medical_kit["position"].begin(); it != medical_kit["position"].end(); ++it) {
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,MAP_KIT});
    }
    

    /* Automatic gun */
    const YAML::Node& automatic_gun = map["Map"]["Automatic_Gun"];

    for (YAML::const_iterator it = automatic_gun["position"].begin(); it != automatic_gun["position"].end(); ++it) {
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,MAP_MACHINE_GUN});
    }

    /* Treasure */
    const YAML::Node& treasure=map["Map"]["Treasure"];
    for (YAML::const_iterator it = treasure["position"].begin(); it != treasure["position"].end(); ++it) {
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,MAP_CUP});
    }

    /* Bullets */
    const YAML::Node& bullet=map["Map"]["Bullets"];
    for (YAML::const_iterator it = bullet["position"].begin(); it != bullet["position"].end(); ++it) {
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,MAP_BULLET});
    }

    /* Keys */

    const YAML::Node& key=map["Map"]["Key"];
    for (YAML::const_iterator it = key["position"].begin(); it != key["position"].end(); ++it) {
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,MAP_KEY});
    }

    /* Red Wall */
    const YAML::Node& red_wall=map["Map"]["Red_Wall"];
    

    for (YAML::const_iterator it = red_wall["position"].begin(); it != red_wall["position"].end(); ++it) {
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,MAP_WALL});
    }

    /* Players */

    
    const YAML::Node& players=map["Map"]["Players"];

    for (YAML::const_iterator it = players["position"].begin(); it != players["position"].end(); ++it) {
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map[map_position]=MAP_PLAYER;
    }
    
    return objects_map;
}

std::map <int,std::pair<int,int>> YamlParser::load_players(std::string YamlPath){
    map= YAML::LoadFile(YamlPath);
    const YAML::Node& players=map["Map"]["Players"];
    std::pair<int,int> map_position;
    int player_number=1;

    for (YAML::const_iterator it = players["position"].begin(); it != players["position"].end(); ++it) {
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        players_spawn_map[player_number]=map_position;
        player_number++;
    }
    return players_spawn_map;
}

void YamlParser::Write_Map(std::string YamlPathToWrite,std::map <int,\
std::vector<std::pair<int,int>>> map,int height,int width){

    YAML::Emitter out;
    int players_=0;
    for (auto const& x : map){
        if(x.first==MAP_PLAYER){
            players_=x.second.size();
        }
    }
    out << YAML::BeginMap;
    out << YAML::Key<< "Map";
    out << YAML::Value << YAML::BeginMap;
    out << YAML::Key << "Cant_players";
    out << YAML::Value << players_;
    out << YAML::Key << "map_dimentions";
    out << YAML::Value << YAML::BeginMap;
    out << YAML::Key << "height";
    out << YAML::Value << height;
    out << YAML::Key << "width";
    out << YAML::Value << width;
    out << YAML::EndMap;
    int players_count=0;

    for (auto const& x : map){

        switch(x.first){
            case MAP_PLAYER:
                out << YAML::Key << "Players";
                break;
            case MAP_CUP:
                out << YAML::Key << "Treasure";
                break;
            case MAP_KIT:
                out << YAML::Key << "Medical_Kit";
                break;
            case MAP_KEY:
                out << YAML::Key << "Key";
                break;
            case MAP_MACHINE_GUN:
                out << YAML::Key << "Automatic_Gun";
                break;
            case MAP_CHAIN_CANNON:
                out << YAML::Key << "Chain_Cannon";
                break;
            case MAP_FOOD:
                out << YAML::Key << "Food";
                break;
            case MAP_BULLET:
                out << YAML::Key << "Bullets";
                break;
            case MAP_WALL:
                out << YAML::Key << "Red_Wall";
                break;
            case MAP_LOCKED_DOOR:
                out << YAML::Key << "Door";
                break;
            default:
                break;
        }
        out << YAML::Value << YAML::BeginMap;
        out << YAML::Key << "position";
        out << YAML::Value << YAML::BeginSeq;

        for(std::pair<int,int> position : x.second) {
            if(x.first==MAP_PLAYER){
                players_count++;
            }
            out << YAML::BeginMap;
            out << YAML::Key << "x";
            out << YAML::Value << position.first*CUADRICULA;
            out << YAML::Key << "y";
            out << YAML::Value << position.second*CUADRICULA;
            out << YAML::EndMap;
        }
        out << YAML::EndSeq;
        out << YAML::EndMap;
    }
    out << YAML::EndMap;
    std::ofstream fileOut(YamlPathToWrite);
    fileOut << out.c_str();
}

int YamlParser::Map_Height(){
    return map["Map"]["map_dimentions"]["height"].as<int>();
}

int YamlParser::Map_Width(){
    return map["Map"]["map_dimentions"]["width"].as<int>();
}