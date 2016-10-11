#include "fct.hpp"


int main(){
    SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Texture * Background = NULL;
  int width = 640, height = 480;
  SDL_Texture *Perso = NULL;
  int x , y;


  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);
    if (window == NULL){
      std::cout<<"Window cannot be created"<<std::endl;
       std::cout<<SDL_GetError()<<std::endl;
     }

    else{ renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);

      Background = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("img/map.bmp"));

      Perso = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("img/perso.bmp"));


      SDL_Rect srcrect = { 0,0,400,400};
      x = 0;
      y = 0;
      //SDL_Rect dstrect = { x,y, 64, 64 };
      while (1) {
        if (y!= height -64){
          if(y < height -64){
            y= y+1;
          }
          else if(y > height -64){
            y = height - 64;
          }

        }
       SDL_Event event;
        if (SDL_PollEvent(&event)) {
         if (event.type == SDL_QUIT or  event.key.keysym.sym == SDLK_a){
           break;
         }
         else if(event.key.keysym.sym == SDLK_SPACE and y == height -64){
           y -= 250;
         }
       }


           SDL_Rect dstrect = { x,y, 64, 64 };
           SDL_RenderClear(renderer);
           SDL_RenderCopy(renderer, Background, NULL, NULL);
           SDL_RenderCopy(renderer,Perso,&srcrect, &dstrect);
           SDL_RenderPresent(renderer);
         }

     SDL_DestroyTexture(Background);
     SDL_DestroyTexture(Perso);
     SDL_DestroyRenderer(renderer);
   }
   SDL_DestroyWindow(window);
   SDL_Quit();
}
