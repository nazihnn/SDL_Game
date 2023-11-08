#ifndef Player_H
#define Player_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Player{

private:   

    enum class Direction
    {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    Direction    direction;
    SDL_Surface *image;
    SDL_Rect     position;
    double       x;
    double       y;

public:
    

    Player();
    void Move_player(SDL_Event const &event);
    void update(double delta_time);
    void draw(SDL_Surface *window_surface);
      
};


#endif 