#include "fct.hpp"

Game::Game(const char *Title){
  Game::_Title = Title;
};
Game::~Game(){};

const char *Game::GetTitle(){
return Game::_Title;
};

Game::Window::Window(int width, int height, const char * title){
  Game::Window::_Width = width;
  Game::Window::_Height = height;
  SDL_Init(SDL_INIT_VIDEO);
  Game::Window::_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);
}
Game::Window::~Window(){
  SDL_DestroyWindow(Game::Window::GetWindow());
}
