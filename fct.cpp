#include "fct.hpp"

Game::Game(const char *Title){
  Game::_Title = Title;
};
Game::~Game(){};

const char *Game::GetTitle(){
return Game::_Title;
};

Window::Window(int width, int height, const char * title){
  Window::_Width = width;
  Window::_Height = height;
  SDL_Init(SDL_INIT_VIDEO);
  Window::_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);
}
Window::~Window(){
  SDL_DestroyWindow(Window::GetWindow());
}
