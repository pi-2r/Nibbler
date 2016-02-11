#include		"../IGraph.hh"

#ifndef			__GRAPH_HH__
#define			__GRAPH_HH__
extern "C"
{
#include		<SDL/SDL.h>
#include		<SDL/SDL_image.h>
}
#include		<list>

class				graph : public IGraph
{
  SDL_Surface			*ecran;
  int				posx;
  int				posy;
  int				width;
  int				height;
  std::list<SDL_Surface*>	lsurface;
  std::list<SDL_Surface*>	delsurface;
  graph();

public:
  graph(const int width, const int height);
  ~graph();
  SDL_Rect		rev(const int width, const int height) const;

  virtual void		put_snake_frame(const int x, const int y);
  SDL_Surface*		getEcran() const;
  virtual int		wait_event();
  
  virtual void		del_frame(const int x, const int y);
  virtual void		put_apple_frame(const int x, const int y);
  virtual void		free_graph();
  virtual void		lost();
};

int			xSDL_Flip(SDL_Surface *screen);
SDL_Surface	*xSDL_CreateRGBSurface(Uint32 flags, int width, int height,
				       int depth, Uint32 Rmask, Uint32 Gmask,
				       Uint32 Bmask, Uint32 Amask);
int		xSDL_BlitSurface(SDL_Surface *src,  SDL_Rect  *srcrect, 
				 SDL_Surface*dst, SDL_Rect *dstrect);
int		xSDL_FillRect(SDL_Surface *dst,
			      SDL_Rect *dstrect, Uint32 color);


#endif
