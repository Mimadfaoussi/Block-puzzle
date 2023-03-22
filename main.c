#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
#include "partie3.h"
#include "intro.h"
//#include "piece.h"
	
#define DEF_CONSTANTES


#define TAILLE_BLOC 40
#define NB_BLOCS_LARGEUR 10
#define NB_BLOCS_HAUTEUR 10
#define LARGEUR_FENETRE  (TAILLE_BLOC * NB_BLOCS_LARGEUR)
#define HAUTEUR_FENETRE (TAILLE_BLOC * NB_BLOCS_HAUTEUR)

void intro(SDL_Surface *ecran);
void principale(SDL_Surface *ecran);
void partie3(SDL_Surface *ecran);
void partie2(SDL_Surface *ecran);
int main(int argc, char *argv[])
{
	SDL_Surface *ecran = NULL, *menu = NULL;

	
	SDL_Event event;
    SDL_Rect positionMenu;
	int continuer = 1;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetIcon(IMG_Load("a.png"), NULL); // L'icône doit être chargée avant SDL_SetVideoMode
	SDL_WM_SetCaption("block Puzzle", NULL);
	ecran = SDL_SetVideoMode(1000,600,32,SDL_HWSURFACE);//we creat the principel surface that have 400 in hight and 500 in width and 32 color
    Uint32 color = SDL_MapRGB(ecran->format,174,60,234);
    SDL_FillRect(ecran, NULL,color);
    //we creat the principel surface that have 400 in hight and 500 in width and 32 color
    //creation(ecran);
    menu = IMG_Load("menu.png");
    positionMenu.x = 0;
    positionMenu.y = 0;
    SDL_BlitSurface(menu, NULL, ecran, &positionMenu);

    SDL_Flip(ecran);
    //SDL_Flip(ecran);
	while (continuer)
  	{
    	SDL_WaitEvent(&event);
    	switch(event.type)
    	{
    	   case SDL_QUIT:
       		 continuer = 0;
             break;

       		case SDL_KEYDOWN://un evenement de clavier 
            switch (event.key.keysym.sym)//entrer la touche du clavier 
            {
            	case SDLK_j : 
            		//principale(ecran);
            		break;
                    
            	case SDLK_ESCAPE : 
            		continuer =0;
            		break;

            }break;

            case SDL_MOUSEBUTTONDOWN : 
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (event.button.x >=423 && event.button.x<=600 && event.button.y>=333 && event.button.y<=358)
                    {
                        principale(ecran);

                    }
                    if (event.button.x >=423 && event.button.x<=600 && event.button.y>=384 && event.button.y<=412)
                    {
                        partie2(ecran);

                    }
                    if (event.button.x >=423 && event.button.x<=637 && event.button.y>=430 && event.button.y<=462)
                    {
                        partie3(ecran);

                    }

                    if (event.button.x >=423 && event.button.x<=650 && event.button.y>=480 && event.button.y<=510)
                    {
                        intro(ecran);

                    }
                }
            }break;
    	}
        //SDL_Flip(ecran);
    	//SDL_Flip(ecran);
  	}


	SDL_FreeSurface(menu);
	SDL_Quit();


}
