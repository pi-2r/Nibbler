#ifndef		GRAPH_HH
#define		GRAPH_HH

#include	"../IGraph.hh"
#include	<ncurses.h>

class		graph : public IGraph
{
  WINDOW*	win;
  int		posx;
  int		posy;
  int		width;
  int		height;
  graph();

public:
  graph(const int width, const int height);
  ~graph();
  virtual void		put_snake_frame(const int x, const int y);
  virtual void		del_frame(const int x, const int y);
  virtual void		put_apple_frame(const int x, const int y);
  virtual int		wait_event();
  virtual void		lost();
  virtual void		free_graph();
};

#endif
