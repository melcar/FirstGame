#include <SDL2/SDL.h>
#include <iostream>
#include "fct.hpp"

int main(){
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Surface *mapsurface = NULL;
  SDL_Texture * maptex = NULL;
  int width = 640, height = 480;

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
       }
     }
           SDL_RenderClear(renderer);
           SDL_RenderCopy(renderer, maptex, NULL, NULL);
           SDL_RenderPresent(renderer);
         }
     SDL_DestroyTexture(maptex);
     SDL_DestroyRenderer(renderer);
   }
   SDL_DestroyWindow(window);
   SDL_Quit();
}
