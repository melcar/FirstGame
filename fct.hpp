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
};

class Window{
  public:
    Window();
    void CreateWindow(int width, int height, const char * Title);
    ~Window();
    void DeleteWindow();

  private:
    Background *_Backgound;
    Sprite *_Sprite1;
    int _Width; int _Height;
    SDL_Window *_Window;
    SDL_Renderer *_Renderer;
};

class Game{
  public:
    Game();
    ~Game();
    void GameStart();
    void GameQuit();
  private:
    Window _Window;
    int width = 640;
    int height = 480;
    const char * Title = "Ninja Maiden";
  };
#endif
