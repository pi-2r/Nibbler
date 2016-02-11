#include		<iostream>
#include		<string>
#include		"graph.hh"

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

graph::graph(const int width, const int height)
{
  SDL_Surface		*bg;
  SDL_Rect		pos;
  
  this->width= width;
  this->height= height;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      std::cerr << "Error SDL_INIT_VIDEO" << std::endl;
      exit(EXIT_FAILURE);
    }
  this->ecran = SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE);
  if (this->ecran == NULL)
    {
      std::cerr << "Error SDL_SetVideoMode" << std::endl;
      exit(EXIT_FAILURE);
    }
  SDL_WM_SetCaption("Nibbler", NULL);
  this->posx = 0;
  this->posy = 0;
  pos.x = 0;
  pos.y = 0;
  bg = xSDL_CreateRGBSurface(SDL_HWSURFACE, 
			    this->width, this->height, 32, 0, 0, 0, 0);
  SDL_FillRect(bg, NULL, SDL_MapRGB(this->ecran->format, 
				       0, 0, 255));
  xSDL_BlitSurface(bg, NULL, this->ecran, &pos);
  xSDL_Flip(this->ecran);
}

int			graph::wait_event()
{
  SDL_Event		event;
  
  SDL_Delay(100);
  while (SDL_PollEvent(&event))
    {
      switch (event.type)
	{
	case SDL_KEYDOWN :
	  if (event.key.keysym.sym == SDLK_LEFT)
	    return(1);
	  else if (event.key.keysym.sym == SDLK_RIGHT)
	    return(2);
	  else if (event.key.keysym.sym == SDLK_ESCAPE)
	    return (-1);
	  break;
	case SDL_QUIT :
	  return(-1);
	  break;
	default :
	  return (0);
	  break;
	}
    }
  return (0);
}


SDL_Rect		graph::rev(const int x, const int y) const
{
  SDL_Rect		pos;

  pos.y = this->height - y - 5;
  pos.x = x - 5;
  return (pos);
}

void			graph::put_snake_frame(const int x, const int y)
{
  SDL_Surface		*_case;
  SDL_Rect		pos;

  pos = rev(x, y);
  _case = xSDL_CreateRGBSurface(SDL_HWSURFACE, 
			       10, 10, 32, 0, 0, 0, 0);
  xSDL_FillRect(_case, NULL, SDL_MapRGB(this->ecran->format, 
				       255, 0, 0));
  xSDL_BlitSurface(_case, NULL, this->ecran, &pos);
  this->lsurface.push_front(_case);
  xSDL_Flip(this->ecran);
}

void			graph::put_apple_frame(const int x, const int y)
{
  SDL_Surface		*_case;
  SDL_Rect		pos;

  pos = rev(x, y);
  _case = xSDL_CreateRGBSurface(SDL_HWSURFACE, 
			       10, 10, 32, 0, 0, 0, 0);
  xSDL_FillRect(_case, NULL, SDL_MapRGB(this->ecran->format, 
				       0, 255, 0));
  xSDL_BlitSurface(_case, NULL, this->ecran, &pos);
  this->lsurface.push_front(_case);
  xSDL_Flip(this->ecran);
}

void			graph::del_frame(const int x, const int y)
{
  SDL_Surface		*_case;
  SDL_Rect		pos;
  std::list<SDL_Surface*>::iterator it;

  pos = rev(x, y);
  _case = xSDL_CreateRGBSurface(SDL_HWSURFACE, 
			       10, 10, 32, 0, 0, 0, 0);
  xSDL_FillRect(_case, NULL, SDL_MapRGB(this->ecran->format, 
				       0, 0, 255));
  xSDL_BlitSurface(_case, NULL, this->ecran, &pos);
  xSDL_Flip(this->ecran);
}

void			graph::free_graph()
{
  std::list<SDL_Surface*>::iterator it;
  std::list<SDL_Surface*>::iterator it2;
  
  for (it = this->delsurface.begin(); it != this->delsurface.end(); it++)
    SDL_FreeSurface(*it);
  for (it2 = this->lsurface.begin(); it2 != this->lsurface.end(); it2++)
    SDL_FreeSurface(*it2);
  SDL_FreeSurface(this->ecran);
}

void			graph::lost()
{
  int			x;
  int			y;

  y = 0;
  while (y <= (this->height + 1))
    {
      x = 0;
      while (x < (this->width + 1))
	{
	  graph::put_apple_frame(x, y);
	  x += 12;
	  SDL_Delay(10);
	}
      y += 12;
    }
}

SDL_Surface*		graph::getEcran() const
{
  return (this->ecran);
}

graph::~graph()
{
}
