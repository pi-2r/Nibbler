#ifndef			__SNAKE_H__
# define		__SNAKE_H__

#include		"IGraph.hh"
#include		<list>
#include		<string>
#include		<cstdlib>
#include		<iostream>
#include		<sstream>
#include		<dlfcn.h>

typedef struct		s_point
{
  int			x;
  int			y;
}			t_point;

enum			e_axis
  {
    aup,
    aright,
    aleft,
    adown
  };

class			snake
{
  std::list<t_point>	body;
  e_axis	      	axis; 
  t_point		size;
  t_point		apple;
  snake();

public:
  snake(const int x, const int y, IGraph* g);
  virtual ~snake();
  void			lose(const int x, const int y, IGraph* g);

  void			pos_move(t_point & move, IGraph *g);
  void			coord(t_point *save, t_point *move);
  void			right(IGraph* g);
  void			left(IGraph* g);
  void			move(IGraph* g);
  void			create_apple(IGraph* g, const t_point & back);
  void			eat_apple(IGraph* g, const int x, const int y, 
				  const t_point & back);
};

void			core(IGraph* g, const int x, const int y);

#endif
