#include	<iostream>
#include	"graph.hh"

int		xSDL_Flip(SDL_Surface *screen)
{
  int		error;

  error = 0;
  error = SDL_Flip(screen);
  if (error == -1)
    {
      std::cerr << "Error SDL_Flip" << std::endl;
      exit(EXIT_FAILURE);
    }
  return (error);
}


SDL_Surface	*xSDL_CreateRGBSurface(Uint32 flags, int width, int height,
				    int depth, Uint32 Rmask, Uint32 Gmask,
				    Uint32 Bmask, Uint32 Amask)
{
  SDL_Surface		*error;

  error = SDL_CreateRGBSurface(flags, width, height, depth, Rmask, Gmask,
				Bmask, Amask);
  if (error == NULL)
    {
      std::cerr << "Error SDL_CreateRGBSurface" << std::endl;
      exit(EXIT_FAILURE);
    }
  return (error);
}

int		xSDL_BlitSurface(SDL_Surface *src,  SDL_Rect  *srcrect, 
		    SDL_Surface*dst, SDL_Rect *dstrect)
{
  int			error;

  error = 0;
  error = SDL_BlitSurface(src, srcrect, dst, dstrect);
  if (error == -1)
    {
      std::cerr << "Error SDL_BlitSurface" << std::endl;
      exit(EXIT_FAILURE);
    }
  return (error);
}

int		xSDL_FillRect(SDL_Surface *dst,
			      SDL_Rect *dstrect, Uint32 color)
{
  int			error;

  error = 0;
  error = SDL_FillRect(dst, dstrect, color);
  if (error == -1)
    {
      std::cerr << "Error SDL_FillRect" << std::endl;
      exit(EXIT_FAILURE);
    }
  return (error);
}
