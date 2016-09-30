#include "fct.hpp"

Game::Game(const char *Title){
  //initiate the Game
  Game::_Title = Title;
};
Game::~Game(){};

void Game::GameStart(){
}

void Game::GameQuit(){
}

Window::Window(){
}

void Window::CreateWindow(int width, int height, const char * Title){
  //create and SDL Window
  Window::_Width = width;
  Window::_Height = height;
  SDL_Init(SDL_INIT_VIDEO);
  Window::_Window = SDL_CreateWindow(Title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);
  Window::_Renderer =  SDL_CreateRenderer(Window::_Window, -1, SDL_RENDERER_TARGETTEXTURE);
}

Window::~Window(){
}
void Window::DeleteWindow(){
  SDL_DestroyWindow(Window::_Window);
}
