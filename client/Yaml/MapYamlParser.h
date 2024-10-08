#include <string>
#include "yaml-cpp/yaml.h"
#include <map>
#include <unordered_map>
#include <iostream>
#include <fstream>

class MapYamlParser{

private:
    std::map <std::pair<int,int>,int> objects_map;

    std::map<int,int> walls_map;
    
    YAML::Node map;

    std::string yamlpath;

public:

    MapYamlParser(std::string YamlPath);

    std::map <std::pair<int,int>,int> load_objects();

    std::map<int,int> get_boxes();

    int Map_Height();

    int Map_Width();

    int get_map_players();

};