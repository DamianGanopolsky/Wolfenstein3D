#ifndef __EDITOR_H__
#define __EDITOR_H__

#include <SDL2/SDL.h>
#include "SdlClasses/SdlWindow.h"
#include "Scene.h"


class Editor{
private:
    struct position initial_position;
    struct position final_position;
    SdlWindow& window;
    Scene scene;
    bool is_clicked_correctly;
    bool is_dragging;

public:
    Editor(SdlWindow& Window);

    void HandleLeftClickPress(SDL_Event* event);

    void HandleMovementWASD(SDL_Event* event);

    void HandleMotion(SDL_Event* event);

    void HandleTextInput(SDL_Event* event);

    void HandleRightClickPress(SDL_Event* event);

    void HandleRightClickRelease(SDL_Event* event);

    void HandleLeftClickRelease(SDL_Event* event);

    void render();

	~Editor();
};

#endif