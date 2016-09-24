#ifndef FCT_H
#define FCT_H
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class Game{
  public:
    Game(const char *Title);
    ~Game();
    const char *GetTitle();
  private:
    const char *_Title;
  };

  class Window{
    public:
      Window(int width, int height, const char * Title);
      ~Window();
      SDL_Window *GetWindow();
    private:
      int _Width; int _Height;
      SDL_Window *_Window;
  };

  class Background{
    public:
      Background();
      ~Background();
    private:
  };
  class Character{
    public:
      Character();
      ~Character();
    private:
};
#endif
