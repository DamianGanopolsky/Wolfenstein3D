#include <SDL2/SDL.h>

class Event_Handler{
private:
    SDL_Event event;
    bool quit;

public:
    Event_Handler(){

    }

    bool handleEvents();

	~Event_Handler();
};