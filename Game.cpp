#include "fct.hpp"

int main(){
    SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Surface *mapsurface = NULL;
  SDL_Texture * maptex = NULL;
  int width = 640, height = 480;
  SDL_Surface *perso = NULL;
  SDL_Texture *persotex = NULL;
  int x , y;

  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);
    if (window == NULL){
      std::cout<<"Window cannot be created"<<std::endl;
       std::cout<<SDL_GetError()<<std::endl;
     }

    else{ renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);
      mapsurface = SDL_LoadBMP("img/map.bmp");
      maptex = SDL_CreateTextureFromSurface(renderer, mapsurface);
      SDL_FreeSurface(mapsurface);

      perso = SDL_LoadBMP("img/perso.bmp");
      persotex = SDL_CreateTextureFromSurface(renderer, perso);
      SDL_FreeSurface(perso);
      SDL_Rect srcrect = { 0,0,400,400  };
      x = 150;
      y = 150;
      SDL_Rect dstrect = { x,y, 64, 64 };
      SDL_RenderCopy(renderer,persotex,&srcrect, &dstrect);

      while (1) {
       SDL_Event event;
       if (SDL_PollEvent(&event)) {
         if (event.type == SDL_QUIT){
           break;
         }
         else if (event.type == SDL_KEYDOWN){
           if( event.key.keysym.sym == SDLK_a){
           break;
         }
         else if( event.key.keysym.sym == SDLK_z){
           y -= 5;
         }
         else if( event.key.keysym.sym == SDLK_q){
           x -= 5;
         }
         else if( event.key.keysym.sym == SDLK_s){
           y += 5 ;
         }
         else if( event.key.keysym.sym == SDLK_d){
           x += 5;
         }
       }
     }
           SDL_Rect dstrect = { x,y, 64, 64 };
           SDL_RenderClear(renderer);
           SDL_RenderCopy(renderer, maptex, NULL, NULL);
           SDL_RenderCopy(renderer,persotex,&srcrect, &dstrect);
           SDL_RenderPresent(renderer);
         }
     SDL_DestroyTexture(maptex);
     SDL_DestroyTexture(persotex);
     SDL_DestroyRenderer(renderer);
   }
   SDL_DestroyWindow(window);
   SDL_Quit();
}
