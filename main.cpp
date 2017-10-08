
#include <SDL/SDL.h>

SDL_Surface* image = NULL;
SDL_Surface* backbuffer = NULL;

int main ( int argc, char* argv[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL failed to initialize!");
        SDL_Quit();
        return 0;
    }

    backbuffer = SDL_SetVideoMode(800,600,32,SDL_SWSURFACE);
    SDL_WM_SetCaption("SDL!!!", NULL);

    //Load the image
    image = SDL_LoadBMP("image.bmp");

    if(image == NULL)
    {
        printf("Image failed to load!\n");
        SDL_Quit();
        return 0;
    }

    //Draw the image
    SDL_BlitSurface(image, NULL, backbuffer, NULL);
    SDL_Flip(backbuffer);

    //wait
    SDL_Delay(3000);

    //Close
    SDL_Quit();
    return 1;
}
