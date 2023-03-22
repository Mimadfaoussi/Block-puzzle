#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <time.h>
#include <SDL/SDL_ttf.h>
#define DEF_CONSTANTES


#define TAILLE_BLOC 40
#define NB_BLOCS_LARGEUR 10
#define NB_BLOCS_HAUTEUR 10
#define LARGEUR_FENETRE  (TAILLE_BLOC * NB_BLOCS_LARGEUR)
#define HAUTEUR_FENETRE (TAILLE_BLOC * NB_BLOCS_HAUTEUR)


void grila(SDL_Surface *ecran);


void partie2(SDL_Surface *ecran)
{
      int carte[NB_BLOCS_LARGEUR][NB_BLOCS_HAUTEUR] = {0};//tableau pour gerer la grille 
      int co = 0,li = 0; // la supprisison 
      int v; // hadi wlh ghire nsite 3lach dertha mais tbanli bech nmdlha w9tach tetbedel xD
      int select; // pour eviter le cas ou 2 pieces  sont les meme 
      SDL_Surface *new;
      new = IMG_Load("new.png");
      time_t t;
      srand((unsigned) time(&t));
      SDL_Surface *move=NULL;
      SDL_Surface *space = NULL;


      SDL_Surface *pieces[18];
      SDL_Surface *small[18];
      pieces[0]=IMG_Load("a.png");
      pieces[1]=IMG_Load("b.png");
      pieces[2]=IMG_Load("c.png");
      pieces[3]=IMG_Load("d.png");
      pieces[4]=IMG_Load("e.png");
      pieces[5]=IMG_Load("f.png");
      pieces[6]=IMG_Load("g.png");
      pieces[7]=IMG_Load("h.png");
      pieces[8]=IMG_Load("i.png");
      pieces[9]=IMG_Load("j.png");
      pieces[10]=IMG_Load("k.png");
      pieces[11]=IMG_Load("l.png");
      pieces[12]=IMG_Load("m.png");
      pieces[13]=IMG_Load("n.png");
      pieces[14]=IMG_Load("o.png");
      pieces[15]=IMG_Load("p.png");
      pieces[16]=IMG_Load("q.png");
      pieces[17]=IMG_Load("r.png");

      small[0]=IMG_Load("a.png");
      small[1]=IMG_Load("bs.png");
      small[2]=IMG_Load("cs.png");
      small[3]=IMG_Load("ds.png");
      small[4]=IMG_Load("es.png");
      small[5]=IMG_Load("fs.png");
      small[6]=IMG_Load("gs.png");
      small[7]=IMG_Load("hs.png");
      small[8]=IMG_Load("is.png");
      small[9]=IMG_Load("js.png");
      small[10]=IMG_Load("ks.png");
      small[11]=IMG_Load("ls.png");
      small[12]=IMG_Load("ms.png");
      small[13]=IMG_Load("ns.png");
      small[14]=IMG_Load("os.png");
      small[15]=IMG_Load("ps.png");
      small[16]=IMG_Load("qs.png");
      small[17]=IMG_Load("rs.png");

      SDL_Rect pos; //pour gerer l'emplacement des pieces 
      SDL_Rect pos1,pos2,pos3; //pour gerer les 3 pieces du dessu 
      SDL_Rect spacePosition; //pour gerer l espace qui contient les 3 pieces(un grand carre qui va contenir les 3 pieces )


      //SDL_Surface *space = NULL; 

      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));    

      space = IMG_Load("space.png");

      // la place du piece 1 
      pos1.x = 40;
      pos1.y = 500;

      // la place du piece 2 
      pos2.x = 200;
      pos2.y = pos1.y;

      // la place du piece 3 
      pos3.x = 360;
      pos3.y = pos1.y;


      spacePosition.x = 40;
      spacePosition.y = 460;


      SDL_Rect posnew;//pour gerer les places des carre vide apres la suppression 

      SDL_Rect *pcarte; //pour gerer l emplacement en tableau des entier

      SDL_Event event; // pour gerer les evenement 
      int placed = 0;
      

      int one = rand() % 17;
      int two =  rand() % 17;
      int three = rand() % 17;
      TTF_Init();
      TTF_Font *police = NULL;
      SDL_Color couleurNoire = {0, 0, 0};
      police = TTF_OpenFont("arial.ttf",30);
     
      SDL_Surface *texte = NULL;

      SDL_Rect positiontext;
      positiontext.x = 470; 
      positiontext.y = 40;
      SDL_Flip(ecran);

      SDL_BlitSurface(small[one], NULL, ecran, &pos1); //mettre on position les mini pieces dans les position 1 2 et 3 
      SDL_BlitSurface(small[two], NULL, ecran, &pos2);
      SDL_BlitSurface(small[three], NULL, ecran, &pos3);



    int continuer =1,j,i;


    texte = TTF_RenderText_Blended(police, "scoore !", couleurNoire);
    SDL_BlitSurface(texte, NULL, ecran, &positiontext);
    while (continuer)
    {
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT)
        continuer = 0;
      if (event.type == SDL_KEYDOWN)
      {
        if (event.key.keysym.sym == SDLK_ESCAPE)
          continuer = 0;
      }



      move = pieces[one];
      select = 1;
      v = 0;


      if (move == pieces[0])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 )
        {
          while(i<=9)
          {
            if (carte[j][i]==0 && placed == 0)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i] = 1;
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 

      if (move == pieces[1])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i]==0 && carte[j][i+1]==0 && placed == 0&& i+1<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i] = 1;
              carte[j][i+1]=1;
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 
      if (move == pieces[2])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i]==0 && carte[j][i+1]==0 && carte[j][i+2]==0 && placed == 0&& i+2<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i] = 1;
              carte[j][i+1]=1;
              carte[j][i+2]=1; 
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 
      if (move == pieces[3])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i]==0 && carte[j][i+1]==0 && carte[j+1][i+1]==0 && placed == 0&& i+1<=9&&j+1<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i] = 1;
              carte[j][i+1]=1;
              carte[j+1][i+1]=1; 
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 
      if (move == pieces[4])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i]==0 && carte[j][i+1]==0 && carte[j+1][i+1]==0 && carte[j+1][i]==0 && placed == 0&& i+1<=9&&j+1<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i] = 1;
              carte[j][i+1]=1;
              carte[j+1][i+1]=1; 
              carte[j+1][i]= 1;
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 

      if (move == pieces[5])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i]==0 && carte[j+1][i]==0 && carte[j+2][i]==0 && carte[j+1][i+1]==0 && placed == 0&& i+1<=9&&j+2<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i] = 1;
              carte[j+1][i]=1;
              carte[j+1][i+1]=1; 
              carte[j+2][i]= 1;
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 

      if (move == pieces[6])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i]==0 && carte[j+1][i]==0 && carte[j+2][i]==0 && carte[j+3][i]==0 && placed == 0 &&j+3<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i] = 1;
              carte[j+1][i]=1;
              carte[j+2][i]=1; 
              carte[j+3][i]= 1;
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 
      if (move == pieces[7])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i]==0 && carte[j+1][i]==0 && carte[j+2][i]==0 && carte[j+3][i]==0 &&carte[j+4][i]==0 && placed == 0 &&j+4<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i] = 1;
              carte[j+1][i]=1;
              carte[j+2][i]=1; 
              carte[j+3][i]= 1;
              carte[j+4][i]= 1;
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 

      if (move == pieces[8])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i]==0 && carte[j][i+1]==0 && carte[j][i+2]==0 && carte[j+1][i+2]==0 &&carte[j+2][i+2]==0 && placed == 0 &&j+2<=9 && i+2<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i] = 1;
              carte[j][i+1]=1;
              carte[j][i+2]=1; 
              carte[j+1][i+2]= 1;
              carte[j+2][i+2]= 1;
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 

      if (move == pieces[9])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i]==0 && carte[j][i+1]==0 && carte[j+1][i+1]==0 && carte[j+2][i+1]==0 &&carte[j+2][i]==0 && placed == 0 &&j+2<=9 && i+1<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i] = 1;
              carte[j][i+1]=1;
              carte[j+1][i+1]=1; 
              carte[j+2][i+1]= 1;
              carte[j+2][i]= 1;
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 

      if (move == pieces[10])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i]==0 && carte[j][i+1]==0 && carte[j][i+2]==0 && carte[j+1][i]==0 &&carte[j+1][i+1]==0 && carte[j+1][i+2]==0 &&carte[j+2][i]==0 && carte[j+2][i+1]==0 &&carte[j+2][i+2]==0 && placed == 0 &&j+2<=9 && i+2<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i] = 1;
              carte[j][i+1]=1;
              carte[j][i+2]=1; 
              carte[j+1][i]= 1;
              carte[j+1][i+1]= 1;
              carte[j+1][i+2]= 1;
              carte[j+2][i]= 1;
              carte[j+2][i+1]= 1;
              carte[j+2][i+2]= 1;
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 

      if (move == pieces[11])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i+1]==0 && carte[j+1][i]==0 && carte[j+1][i+1]==0 && carte[j+1][i+2]==0  && placed == 0 && j+1<=9 && i+2<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i+1] = 1;
              carte[j+1][i]=1;
              carte[j+1][i+1]=1; 
              carte[j+1][i+2]= 1;
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 

      if (move == pieces[12])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i+1]==0 && carte[j+1][i]==0 && carte[j+1][i+1]==0 && placed == 0 && j+1<=9 && i+1<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i+1] = 1;
              carte[j+1][i]=1;
              carte[j+1][i+1]=1; 
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 

      if (move == pieces[13])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i]==0 && carte[j][i+1]==0 && carte[j+1][i]==0 && placed == 0 && j+1<=9 && i+1<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i] = 1;
              carte[j+1][i]=1;
              carte[j][i+1]=1; 
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 

      if (move == pieces[14])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i]==0 && carte[j][i+1]==0 && carte[j][i+2]==0 && carte[j+1][i]==0 && carte[j+2][i]==0  && placed == 0 && j+2<=9 && i+2<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i] = 1;
              carte[j][i+1]=1;
              carte[j][i+2]=1;
              carte[j+1][i]=1;
              carte[j+2][i]=1;

              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 
      if (move == pieces[15])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i+2]==0 && carte[j+1][i+2]==0 && carte[j+2][i+2]==0 && carte[j+2][i+1]==0 && carte[j+2][i]==0  && placed == 0 && j+2<=9 && i+2<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i+2] = 1;
              carte[j+1][i+2]=1;
              carte[j+2][i+2]=1;
              carte[j+2][i+1]=1;
              carte[j+2][i]=1;

              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 
      if (move == pieces[16])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i]==0 && carte[j][i+1]==0 && carte[j][i+2]==0 && carte[j][i+3]==0 &&carte[j][i+4]==0 && placed == 0 && i+4<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i] = 1;
              carte[j][i+1]=1;
              carte[j][i+2]=1; 
              carte[j][i+3]= 1;
              carte[j][i+4]= 1;
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 

      if (move == pieces[17])
      {
        i = 0;
        j = 0;
        placed = 0;

        while(j<=9 && placed == 0)
        {
          while(i<=9 && placed == 0)
          {
            if (carte[j][i]==0 && carte[j][i+1]==0 && carte[j][i+2]==0 && carte[j+1][i+1]==0 && placed == 0&& j+1<=9 && i+2<=9)
            {
              pos.x = (i*40)+40;
              pos.y = (j*40)+40;
              SDL_BlitSurface(move, NULL, ecran, &pos);
              SDL_Flip(ecran);
              SDL_Delay(200);
              placed = 1;
              carte[j][i] = 1;
              carte[j][i+1]=1;
              carte[j][i+2]=1; 
              carte[j+1][i+1]= 1;
              v = 1;
            }
            i = i+1;

           }
            
          j = j+1;
          i = 0;
        }

      }//end of if condition 
      
      for (int j = 0; j <= 9; ++j)
      {
        co = 0;
        li = 0;
        for (int i = 0; i <=9; ++i)
        {
          if (carte[j][i]==0)
          {
            co = 1;
          }
          if (carte[i][j] == 0)
          {
            li = 1;
          }

        }
        if (li == 0)
        {
          for (int i = 0; i <=9; ++i)
          {
            carte[i][j] = 0;
            posnew.x = ((j*40)+40);
            posnew.y = (i*40)+40;
            //SDL_Delay(120);
            grila(ecran);
            SDL_Flip(ecran);
            SDL_BlitSurface(new, NULL, ecran,&posnew);
          }
        }
        if (co == 0)
        {
          for (int i = 0; i <=9; ++i)
          {
            carte[j][i] = 0;
            posnew.x = ((i*40)+40);
            posnew.y = (j*40)+40;
            SDL_Delay(120);
            grila(ecran);
            SDL_Flip(ecran);
            SDL_BlitSurface(new, NULL, ecran,&posnew);
          }
        }
      }

      if (v == 1)
      {
        one = rand() % 17;
      }
      move = pieces[two];
      select = 2;
      v = 0;


      grila(ecran);
      SDL_Flip(ecran);
      SDL_Delay(200);


    }// end of loop 

}// end of function 

void grila(SDL_Surface *ecran)
{
      SDL_Surface *ligne[11]={NULL}; //we create 10 surfaces-pointers  each one of them gonna take an espace and we will make them lines
      SDL_Surface *colone[11]={NULL};
      SDL_Rect position;

      int i,j=40;
    for (int i = 0; i <= 10; ++i)
    {
      ligne[i] = SDL_CreateRGBSurface(SDL_HWSURFACE,400,1,32,0,0,0,0);//la hauteur 1 pour les lignes 
    }

    for (int i = 0; i <=10; ++i)
    {
        position.x = 40;
        position.y = j;
        SDL_FillRect(ligne[i],NULL,SDL_MapRGB(ecran->format,0,0,0));
        SDL_BlitSurface(ligne[i],NULL,ecran,&position);
        j = j+40;
    }

    for (int i = 0; i <= 10; ++i)
    {
      colone[i] = SDL_CreateRGBSurface(SDL_HWSURFACE,1,400,32,0,0,0,0);// largeur 1 pour les colones  
    }
    j = 40;

    for (int i = 0; i <= 10; ++i)
    {
            position.x = j;
        position.y = 40;
        SDL_FillRect(colone[i],NULL,SDL_MapRGB(ecran->format,0,0,0));
        SDL_BlitSurface(colone[i],NULL,ecran,&position);
        j = j+40;
        SDL_FreeSurface(ligne[i]);
        SDL_FreeSurface(colone[i]);

    }

      
}

