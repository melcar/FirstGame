#include "fct.hpp"

Game::Game(const char *Title){
  //initiate the Game
  Game::_Title = Title;
};
Game::~Game(){};
const char *Game::GetTitle(){
return Game::_Title;
};

void Game::GameStart(){
  //tbd
}
void Game::GameQuit(){
  //tbd
}
Window::Window(int width, int height, const char * title){
  //create and SDL Window
  Window::_Width = width;
  Window::_Height = height;
  SDL_Init(SDL_INIT_VIDEO);
  Window::_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);
  Window::_Renderer =  SDL_CreateRenderer(Window::_Window, -1, SDL_RENDERER_TARGETTEXTURE);
}

Window::~Window(){
}
void Window::DeleteWindow(){
  SDL_DestroyWindow(Window::_Window);
}
