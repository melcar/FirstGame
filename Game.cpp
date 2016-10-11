#include "fct.hpp"


int main(){
    SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Texture * Background = NULL;
  int width = 640, height = 480;
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

      TTF_Init();
      //SDL_Surface *TTF_RenderText_Solid(TTF_Font *font, const char *text, SDL_Color fg);
      TTF_Font *font = TTF_OpenFont("font/BebasNeue.otf", 65);
      SDL_Color Color = {255, 255, 255};

      int start_Time = SDL_GetTicks();
      while (1) {
       SDL_Event event;
       if (SDL_PollEvent(&event)) {
         if (event.type == SDL_QUIT){
           break;
         }
       }
           Time = (SDL_GetTicks() - start_Time);
           str_Time = std::to_string(Time);
           char_Time = str_Time.c_str();
           Text = SDL_CreateTextureFromSurface(renderer,TTF_RenderText_Solid(font, char_Time, Color));
           SDL_RenderClear(renderer);
           SDL_RenderCopy(renderer, Background, NULL, NULL);
           SDL_RenderCopy(renderer,Text, NULL, NULL);
           SDL_RenderPresent(renderer);
           SDL_DestroyTexture(Text);
         }
     TTF_CloseFont(font);
     TTF_Quit();
     SDL_DestroyTexture(Text);
     SDL_DestroyTexture(Background);
     SDL_DestroyRenderer(renderer);
   }
   SDL_DestroyWindow(window);
   SDL_Quit();
}
