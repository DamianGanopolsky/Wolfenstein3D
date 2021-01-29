#include "MapYamlParser.h"
#define KEY 4
#define MEDICAL_KIT 5
#define TREASURE 6
#define FOOD 7
#define AUTOMATIC_GUN 8
#define BULLETS 9
#define CHAIN_CANNON 10





YamlParser::YamlParser(std::string YamlPath){
    //map= YAML::LoadFile(YamlPath);
}




std::map <std::pair<int,int>,int> YamlParser::load_objects(std::string YamlPath){

    map= YAML::LoadFile(YamlPath);
    /* Chain Cannon */
    //const YAML::Node& initial_map=map["Map"];
    //std::cout << initial_map["map_dimentions"]["height"] << std::endl;
    //const YAML::Node& chain_cannon = initial_map["Chain_Cannon"];
    const YAML::Node& chain_cannon = map["Map"]["Chain_Cannon"];
    std::pair<int,int> map_position;
    for (YAML::const_iterator it = chain_cannon["position"].begin(); it != chain_cannon["position"].end(); ++it) {
        
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,CHAIN_CANNON});
    }

    /* FOOD */

    const YAML::Node& food= map["Map"]["Food"];
    for (YAML::const_iterator it = food["position"].begin(); it != food["position"].end(); ++it) {
        
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,FOOD});
    }


    /* MEDICAL_KIT */
    const YAML::Node& medical_kit= map["Map"]["Medical_Kit"];
    for (YAML::const_iterator it = medical_kit["position"].begin(); it != medical_kit["position"].end(); ++it) {
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,MEDICAL_KIT});
    }
    

    /* Automatic gun */
    //const YAML::Node& initial_map=map["Map"];

    //const YAML::Node& automatic_gun = initial_map["Weapons"]["Automatic_Gun"];
    const YAML::Node& automatic_gun = map["Map"]["Automatic_Gun"];

    for (YAML::const_iterator it = automatic_gun["position"].begin(); it != automatic_gun["position"].end(); ++it) {
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,AUTOMATIC_GUN});
    }

    /* Treasure */

    //const YAML::Node& treasure=initial_map["Treasures"]["Treasure"];
    //const YAML::Node& treasure=initial_map["Treasure"];
    const YAML::Node& treasure=map["Map"]["Treasure"];
    for (YAML::const_iterator it = treasure["position"].begin(); it != treasure["position"].end(); ++it) {
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,TREASURE});
    }

    /* Bullets */
    const YAML::Node& bullet=map["Map"]["Bullets"];
    for (YAML::const_iterator it = bullet["position"].begin(); it != bullet["position"].end(); ++it) {
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,BULLETS});
    }

    /* Keys */

    const YAML::Node& key=map["Map"]["Key"];
    for (YAML::const_iterator it = key["position"].begin(); it != key["position"].end(); ++it) {
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,KEY});
    }
    return objects_map;
}

/*
std::map<int,bool> get_boxes(){
    const YAML::Node& red_wall=map["Map"]["Red_Wall"];
    

    for (YAML::const_iterator it = red_wall["position"].begin(); it != red_wall["position"].end(); ++it) {
        const YAML::Node& pos = *it;
        map_position.first=pos['x'].as<int>();;
        map_position.second=pos['y'].as<int>();;
        objects_map.insert({map_position,WALL});
    }
}
*/
int YamlParser::Map_Height(){
    //return initial_map["map_dimentions"]["height"].as<int>();
    return map["Map"]["map_dimentions"]["height"].as<int>();
}

int YamlParser::Map_Width(){
    //return initial_map["map_dimentions"]["width"].as<int>();
    return map["Map"]["map_dimentions"]["width"].as<int>();
}