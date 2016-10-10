#include "fct.hpp"


int main(){
    SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Texture * Background = NULL;
  int width = 640, height = 480;
  SDL_Texture *Perso = NULL;
  int x , y;
  SDL_Texture *Text;
  long int Time =0;
  std::string str_Time;
  const char *char_Time ;


  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);
    if (window == NULL){
      std::cout<<"Window cannot be created"<<std::endl;
       std::cout<<SDL_GetError()<<std::endl;
     }

    else{ renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_TARGETTEXTURE);

      Background = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("img/map.bmp"));

      Perso = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("img/perso.bmp"));

      TTF_Init();
      //SDL_Surface *TTF_RenderText_Solid(TTF_Font *font, const char *text, SDL_Color fg);
      TTF_Font *font = TTF_OpenFont("font/3Dventure.ttf", 65);
      SDL_Color Color = {20, 100, 30};


      //Text = SDL_CreateTextureFromSurface(renderer,TTF_RenderText_Solid(font, "222.", Color));

      SDL_Rect srcrect = { 0,0,400,400};
      x = 150;
      y = 150;
      //SDL_Rect dstrect = { x,y, 64, 64 };
      int start_Time = SDL_GetTicks();
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
           Time = (SDL_GetTicks() - start_Time);
           str_Time = std::to_string(Time);
           char_Time = str_Time.c_str();
           Text = SDL_CreateTextureFromSurface(renderer,TTF_RenderText_Solid(font, char_Time, Color));
           SDL_Rect dstrect = { x,y, 64, 64 };
           SDL_RenderClear(renderer);
           SDL_RenderCopy(renderer, Background, NULL, NULL);
           SDL_RenderCopy(renderer,Text, NULL, NULL);
           SDL_RenderCopy(renderer,Perso,&srcrect, &dstrect);
           SDL_RenderPresent(renderer);
           SDL_DestroyTexture(Text);
         }
     TTF_CloseFont(font);
     TTF_Quit();
     SDL_DestroyTexture(Text);
     SDL_DestroyTexture(Background);
     SDL_DestroyTexture(Perso);
     SDL_DestroyRenderer(renderer);
   }
   SDL_DestroyWindow(window);
   SDL_Quit();
}
