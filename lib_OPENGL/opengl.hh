#include		"../IGraph.hh"

#ifndef			__OPENGL_HH__
# define		__OPENGL_HH__

#include                <SDL/SDL.h>

class			opengl : public IGraph
{
  double		size_x_1;
  double		size_y_1;
  double		size_x_2;
  double		size_y_2;
  
  unsigned int		width;
  unsigned int		height;
  opengl();

public:
  opengl(const int width, const int height);
  ~opengl();

  virtual void		del_frame(const int x, const int y);
  virtual int		wait_event();
  virtual void		put_snake_frame(const int x, const int y);
  virtual void		free_graph();
  virtual void		put_apple_frame(const int x, const int y);
  virtual void		lost();
  void			reset_size();

  void			create_map(const double & x, const double & y, const bool map);
  void			put_map(const bool map);
};

int			xSDL_Init(Uint32 flags);
int			xatexit(void (*fonction)(void));
SDL_Surface		*xSDL_SetVideoMode(int width, int height,
					   int bpp, Uint32 flags);

#endif
