#include                <GL/gl.h>
#include                <GL/glu.h>
#include                <iostream>
#include                "opengl.hh"

int			xSDL_Init(Uint32 flags)
{
  if (SDL_Init(flags) == -1)
    {
      std::cout << "Erreur SDL_Init" << std::endl;
      exit(EXIT_FAILURE);
    }
  return (0);
}

int			xatexit(void (*fonction)(void))
{
  if (atexit((*fonction)) == -1)
    {
      std::cout << "Erreur atexit" << std::endl;
      exit(EXIT_FAILURE);
    }
  return (0);
}

SDL_Surface		*xSDL_SetVideoMode(int width, int height,
					   int bpp, Uint32 flags)
{
  SDL_Surface		*retour;

  retour = SDL_SetVideoMode(width, height, bpp, flags);
  if (retour == NULL)
    {
      std::cout << "Erreur SDL_SetVideoMode" << std::endl;
      exit(EXIT_FAILURE);
    }
  return (retour);
}
