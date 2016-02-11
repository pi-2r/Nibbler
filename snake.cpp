#include	<unistd.h>
#include	<ctime>
#include	<iostream>
#include	<cstdlib>
#include	"snake.hh"

snake::snake(const int x, const int y, IGraph *g)
  :  axis(aup)
{
  int		i;
  t_point	beg;

  size.x = x;
  size.y = y;
  beg.x = x / 2;
  beg.y = y / 2 - (4 * 12);
  i = 0;
  while (i <= 3)
    {
      body.push_front(beg);
      g->put_snake_frame(beg.x, beg.y);
      beg.y += 12;
      i++;
    }
}

void		snake::coord(t_point *save, t_point *move)
{
  save->x = move->x;
  save->y = move->y;
}

void		snake::pos_move(t_point & move, IGraph *g)
{
  t_point	save;
  t_point	save2;
  int		nb;
  std::list<t_point>::iterator it;

  nb = 0;
  it = body.end();
  it--;
  g->del_frame(it->x, it->y);
  for(it = body.begin(); it != body.end(); it++)
    {
      if (nb % 2 == 0)
	{
	  coord(&save, &(*it));
	  if (nb != 0)
	    coord(&(*it), &save2);
	}
      else
	{
	  coord(&save2, &(*it));
	  coord(&(*it), &save);
	}
      if (nb == 0)
	{
	  it->x += move.x;
	  it->y += move.y;
	  lose(it->x, it->y, g);
	  g->put_snake_frame(it->x, it->y);
	  eat_apple(g, it->x, it->y, move);
	}
      nb++;
    }
}

void		snake::right(IGraph* g)
{
  t_point	move;
  
  move.x = 0;
  move.y = 0;
  switch (axis)
    {
    case aup :
      move.x = 12;
      axis = aright;
      break;
    case adown :
      move.x = -12;
      axis = aleft;
      break;
    case aright :
      move.y = -12;
      axis = adown;
      break;
    case aleft :
      move.y = 12;
      axis = aup;
      break;
    }
  pos_move(move, g);
}

void		snake::left(IGraph *g)
{
  t_point	move;

  move.x = 0;
  move.y = 0;
  switch (axis)
    {
    case aup :
      move.x = -12;
      axis = aleft;
      break;
    case adown :
      move.x = 12;
      axis = aright;
      break;
    case aright :
      move.y = 12;
      axis = aup;
      break;
    case aleft :
      move.y = -12;
      axis = adown;
      break;
    }
  pos_move(move, g);
}

void		snake::move(IGraph* g)
{
  t_point	move;

  move.x = 0;
  move.y = 0;
  switch (axis)
    {
    case aup :
      move.y = 12;
      break;
    case adown :
      move.y = -12;
      break;
    case aright :
      move.x = 12;
      break;
    case aleft :
      move.x = -12;
      break;
    }
  pos_move(move, g);
}

void		snake::lose(const int x , const int y, IGraph *g)
{
  bool		lost;
  std::list<t_point>::iterator it;

  lost = false;
  if (x > (size.x - 6) || x < 6 || y > (size.y - 6) || y < 6)
    lost = true;
  it = body.begin();
  it++;
  while (it != body.end())
    {
      if (it->x == x && it->y == y)
	lost = true;
      it++;
    }
  if (lost == true)
    {
      g->lost();
      g->free_graph();
      exit(0);
    }
}

void		snake::create_apple(IGraph* g, const t_point & back)
{
  std::list<t_point>::iterator it;
  bool		pos_ok;
  t_point	center;

  srandom(time(0) * getpid());
  pos_ok = false;
  center.x = (size.x / 2);
  center.y = (size.y / 2);
  while (pos_ok == false)
    {
      pos_ok = true;
      apple.x = center.x + (random() % (center.x / 12)) * 12;
      apple.y = center.y + (random() % (center.y / 12)) * 12;
      if ((random() % 10) < 5)
	apple.x = center.x - (random() % (center.x / 12)) * 12;
      if ((random() % 10) > 5)
	apple.y = center.y - (random() % (center.y / 12)) * 12;
      for (it = body.begin(); it != body.end(); it++)
	{
	  if ((it->y == apple.y && it->x == apple.x) ||
	      ((it->y + back.y) == apple.y &&
	       (it->x + back.x) == apple.x))
	    pos_ok = false;
	}
      if (apple.x <= 6 || apple.x >= (size.x - 6) ||
	  apple.y <= 6 || apple.y >= (size.y - 6))
	pos_ok = false;
    }
  g->put_apple_frame(apple.x, apple.y);
}

void		snake::eat_apple(IGraph* g, const int x, const int y,
				 const t_point & back)
{
  t_point		move;
  t_point		p1;
  std::list<t_point>::iterator it;

  if (apple.x == x && apple.y == y)
    {
      it = body.end();
      it--;
      p1.x = it->x;
      p1.y = it->y;
      it--;
      move.x = p1.x - it->x;
      move.y = p1.y - it->y;
      p1.x = p1.x + move.x;
      p1.y = p1.y + move.y;
      body.push_back(p1);
      g->put_snake_frame(x, y);
      create_apple(g, back);
    }
}

snake::~snake()
{
}
