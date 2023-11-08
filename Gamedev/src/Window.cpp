#include <Window.hpp>


SDL_Surface *load_surface(char const *path)
{
    SDL_Surface *image_surface = SDL_LoadBMP(path);

    if(!image_surface)
        return 0;
    
    return image_surface;
}
  Window::Window()
         {


            //Initialize SDL
            if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
            {
                printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
            }
            else
            {
                //Create window
                window = SDL_CreateWindow( "MAZE RUNNER!!!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
                if( window == NULL )
                {
                    printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
                }
                else
                {
                    //Get window surface
                    screenSurface = SDL_GetWindowSurface( window );

                    
                }
            }

           

        }

        Window::~Window(){

             //Destroy window
            SDL_DestroyWindow( window );

            //Quit SDL subsystems
            SDL_Quit();
        }

        void Window::loop(){

        
            bool keep = true; 
            while( keep == true ){ 
                while( SDL_PollEvent( &event ) >0 ){ 

                    player.Move_player(event);
                    switch(event.type){
                        case SDL_QUIT:
                            keep= false;
                            break;
                    }
                } 

                update(1.0/60.0);
                draw(); 
            }

            
        }
        
        
       void Window::update(double delta_time){
            player.update(delta_time);

       }

       void Window::draw(){

        SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 0));

        player.draw(screenSurface);

        SDL_UpdateWindowSurface(window);

       }
    