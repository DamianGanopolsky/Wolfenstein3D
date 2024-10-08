#include "LogInController.h"
#include <iostream>

LogInController::LogInController(LoginView& LoginView):loginview(LoginView){
    
}

void LogInController::run(){
    bool quit = false;
    while (!quit){
        quit=handle_events();
        loginview.render();
    }
}

bool LogInController::handle_events(){

	SDL_Event event;
	bool quit=false;

	//bool moving=false;
	while(SDL_PollEvent(&event)!=0){
        switch (event.type){   

            case SDL_KEYDOWN:

                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:  //Salir de la pantalla
                        quit=true;
                        break;
                }
            case SDL_QUIT:
                quit=true;
                break;
            case SDL_TEXTINPUT:
                break;
            case SDL_MOUSEBUTTONDOWN:  //Clickear(no necesariamente soltar)
                break;
            case SDL_MOUSEBUTTONUP: //Evento soltar despues de clickear
                break;
        }
    }
    return quit;
}
