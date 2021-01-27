#include <SDL2/SDL.h>

#define WIDTH 640
#define HEIGHT 480

SDL_Renderer *renderer;
SDL_Window *window;

int main(int argc, char* argv[])
{
  int rendererFlags, windowFlags;

  rendererFlags = SDL_RENDERER_ACCELERATED;
  windowFlags = 0;
  
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      printf("Couldn't initialize SDL: %s\n", SDL_GetError());
      exit(1);
    }

  window = SDL_CreateWindow("Shooter 01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, windowFlags);
  if(!window)
    {
      printf("Failed to open %d x %d window: %s\n", WIDTH, HEIGHT, SDL_GetError());
      exit(1);
    }

  SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

  renderer = SDL_CreateRenderer(window, -1, rendererFlags);
  if (!renderer)
    {
      printf("Failed to create renderer: %s\n", SDL_GetError());
      exit(1);
    }

  SDL_Delay(5000);
  
  exit(0);
}
