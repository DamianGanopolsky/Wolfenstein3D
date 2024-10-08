#include "SdlWindow.h"
#include <iostream>

SdlWindow::SdlWindow(float width,float height):Width(width),Height(height){


    window = SDL_CreateWindow("SDL_ttf in SDL2",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width,
    height, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

void SdlWindow::render(){
    SDL_RenderPresent(this->renderer);
}
SDL_Renderer* SdlWindow::getRenderer() const{
    return this->renderer;
}

void SdlWindow::set_full_screen(){
    SDL_SetWindowFullscreen(window,0);
}

float SdlWindow::getHeight() const{
    return Height;
}

float SdlWindow::getWidth() const{
    return Width;
}

SdlWindow::~SdlWindow(){
    if(this->renderer){
        SDL_DestroyRenderer(renderer);
        this->renderer= nullptr;
    }
    if(this->window){
        SDL_DestroyWindow(window);
        this->window= nullptr;
    }
}