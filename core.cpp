#include	"snake.hh"

void		core(IGraph *g, const int x, const int y)
{
  snake			s(x, y, g);
  int			i;
  t_point		init;
  
  init.x = 0;
  init.y = 0;
  i = 3;
  s.create_apple(g, init);
  while (i >= 0)
    {
      switch (i = g->wait_event())
	{
	case 1:
	  s.left(g);
	  break;
	case 2:
	  s.right(g);
	  break;
	default:
	  s.move(g);
	}
    }
  g->free_graph();
}
