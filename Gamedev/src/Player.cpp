#include <Player.hpp>

    Player::Player(){
        image = SDL_LoadBMP("stick_figure.bmp");

        position.x = 0;
        position.y = 0;
        position.w = 22;
        position.h = 43;

        x = 0.0;
        y = 0.0;

        direction = Direction::NONE;
    }


    void Player::Move_player(SDL_Event const &event){


    switch(event.type)
    {
        case SDL_KEYDOWN:
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);

            if(keys[SDL_SCANCODE_W] == 1)
                direction = Direction::UP;
            else if(keys[SDL_SCANCODE_S] == 1)
                direction = Direction::DOWN;
            else if(keys[SDL_SCANCODE_A] == 1)
                direction = Direction::LEFT;
            else if(keys[SDL_SCANCODE_D] == 1)
                direction = Direction::RIGHT;
            else if(keys[SDL_SCANCODE_P] == 1)
                direction = Direction::NONE;
            break;
    }

    }
    void Player::update(double delta_time){

        Uint8 const *keys = SDL_GetKeyboardState(nullptr);
    
        switch(direction){
            case Direction::NONE:
                x += 0.0;
                y += 0.0;
                break;
            case Direction::UP:
                y = y - (100.0 * delta_time * keys[SDL_SCANCODE_W]);
                break;
            case Direction::DOWN:
                y = y + (100.0 * delta_time * keys[SDL_SCANCODE_S]);
                break;
            case Direction::LEFT:
                x = x - (100.0 * delta_time * keys[SDL_SCANCODE_A]);
                break;
            case Direction::RIGHT:
                x = x + (100.0 * delta_time * keys[SDL_SCANCODE_D]);
                break;
        }

    position.x = x;
    position.y = y;


    }
    void Player::draw(SDL_Surface *window_surface){
        SDL_BlitSurface(image, nullptr, window_surface, &position);

    }

