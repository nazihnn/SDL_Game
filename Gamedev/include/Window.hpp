#ifndef Window_H
#define Window_H
    #include <iostream>
    #include <memory>
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
    #include <Player.hpp>
    
    class Window{
    private:

        const int SCREEN_WIDTH = 640;
        const int SCREEN_HEIGHT = 480;

        SDL_Window* window;        
        SDL_Surface* screenSurface;
        SDL_Event event; 

        SDL_Renderer *m_window_renderer;

        Player player;

        

    public:

        Window();
        ~Window();
       void loop();
       void update(double delta_time);
       void draw();
    
    };



#endif