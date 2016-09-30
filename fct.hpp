#ifndef FCT_H
#define FCT_H
#include <SDL2/SDL.h>
#include <iostream>
#include <string>

class Game{
  public:
    Game(const char *Title);
    ~Game();
    void GameStart();
    void GameQuit();
    const char *GetTitle();
  private:
    const char *_Title;
  };

  class Window{
    public:
      Window(int width, int height, const char * Title);
      ~Window();
      void DeleteWindow();

    private:
      int _Width; int _Height;
      SDL_Window *_Window;
      SDL_Renderer *_Renderer;
  };

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
};
#endif
