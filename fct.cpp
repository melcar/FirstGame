#include "fct.hpp"

Background::Background(SDL_Renderer *Renderer, const  char *file){
  Background::_texture = SDL_CreateTextureFromSurface(Renderer, SDL_LoadBMP(file));
}
Background::~Background(){}
SDL_Texture *Background::Get_Background(){
  return Background::_texture;
}
Sprite::Sprite(){}
Sprite::~Sprite(){}
