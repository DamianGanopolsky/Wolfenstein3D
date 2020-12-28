#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#include "SdlClasses/SdlWindow.h"
//#include "Event_Handler.h"
#include "MusicSoundtrack.h"
#include <unistd.h>
#include "yaml-cpp/yaml.h"
#include <fstream>  
#include "Map.h"
#include <stdexcept>


int main(int argc,char* argv[]){

    YAML::Node config = YAML::LoadFile("../Yaml_configs/editor_config.yaml");
    int width = config["width"].as<int>();
    int heigth =config["heigth"].as<int>();
    
    int error=SDL_Init(SDL_INIT_VIDEO);
    if(error!=0){
        throw std::invalid_argument("Error  en la inicializacion de sdl \n");
    }
    
    SdlWindow window(width,heigth);
    Map map(window);
   // map.LoadMatrix();
    map.ExpandMap();
    map.printMatrix();
    /*Editor editor(window);
    Event_Handler event_handler;
    bool quit = false;
    //EditorSoundtrack musicsoundtrack;
   // musicsoundtrack.play_editor();
    Main_Window mainwindow(window);
    mainwindow.render_window();
    window.render();

    while (!quit){
        SDL_RenderClear(window.getRenderer());
        quit=event_handler.handleEvents(editor);
        editor.render();
        window.render();
    }

    SDL_Quit();*/
    return 0;
}