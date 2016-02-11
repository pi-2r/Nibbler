#include	"graph.hh"
#include	<unistd.h>

extern "C"
{
  IGraph *	maker(int const x, int const y)
  {
    IGraph *	g = new graph(x, y);

    return (g);
  }
}

graph::graph()
{
}

graph::~graph()
{
}

graph::graph(const int width, const int height)
{
  int x = width / 12;
  int y = height / 12;

  initscr();
  this->win = newwin(x + 1, y + 1, 0, 0);
  start_color();
  init_pair(1, COLOR_RED, COLOR_RED);
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  init_pair(3, COLOR_BLACK, COLOR_BLACK);
  curs_set(0);
  raw();
  wtimeout(this->win, 100);
  noecho();
  keypad(this->win, TRUE);
  box(this->win, 0, 0);
  wrefresh(this->win);
}

int		graph::wait_event()
{
  int		ch;

  ch = wgetch(this->win);
  switch (ch)
    {
      case KEY_LEFT :
	return (1);
      case KEY_RIGHT :
	return (2);
      case 27 :
	return (-1);
      default :
	return (0);
    }
}

void		graph::put_snake_frame(const int x1, const int y1)
{
  int x = x1 / 12;
  int y = y1 / 12;

  wattron(this->win, COLOR_PAIR(1));
  mvwprintw(this->win, x, y, "#");
  wrefresh(this->win);
  wattroff(this->win, COLOR_PAIR(1));
}

void		graph::put_apple_frame(const int x1, const int y1)
{
  int x = x1 / 12;
  int y = y1 / 12;

  wattron(this->win, COLOR_PAIR(2));
  mvwprintw(this->win, x, y, "o");
  wrefresh(this->win);
  wattroff(this->win, COLOR_PAIR(2));
}

void		graph::del_frame(const int x1, const int y1)
{
  int x = x1 / 12;
  int y = y1 / 12;
  
  wattron(this->win, COLOR_PAIR(3));
  mvwprintw(this->win, x, y, " ");
  wrefresh(this->win);
  wattroff(this->win, COLOR_PAIR(3));
}

void		graph::free_graph()
{
  delwin(this->win);
  endwin();
}

void		graph::lost()
{
  wclear(this->win);
  wrefresh(this->win);
  mvwprintw(this->win, 1, 2, "You Lose\n");
  wrefresh(this->win);
  sleep(1);
}

