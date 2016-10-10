#ifndef FCT_H
#define FCT_H
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

  class Background{
    public:
      Background(SDL_Renderer *Renderer, const  char *file);
      ~Background();
      SDL_Texture * Get_Background();
    private:
      SDL_Texture* _texture;
      };

  class Sprite{
    public:
      Sprite();
      ~Sprite();
      void animation(){};
    private:
      int posX;
      int posY;
};
#endif
