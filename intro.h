

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_ttf.h>	
void intro(SDL_Surface *ecran)
{
	SDL_Surface *photo;
	photo = IMG_Load("description.png");
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));  
	SDL_Rect intropos;
	intropos.x = 0;
	intropos.y = 0;
	SDL_BlitSurface(photo, NULL,ecran,&intropos);
	SDL_Flip(ecran);	
	int continuer = 1;
	SDL_Event event;

	while(continuer)
	{
		SDL_WaitEvent(&event); // pour gerer les evenements en sdl 
        if(event.type == SDL_QUIT)//si on veut sortir du programme 
            continuer = 0;

        if(event.type == SDL_KEYDOWN)//si on utulise les touches des claviers 
        {
        	if (event.key.keysym.sym == SDLK_ESCAPE) // si on click sur la touch esc on sors 
            {
				continuer = 0;
            }

        }
	} 

}
