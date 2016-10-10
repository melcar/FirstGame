#ifndef FCT_H
#define FCT_H
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

  class Background{
    public:
      Background();
      ~Background();
    private:
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
