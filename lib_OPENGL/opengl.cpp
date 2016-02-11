#include		<GL/gl.h>
#include		<GL/glu.h>
#include		<iostream>
#include		"opengl.hh"

extern "C"
{
  IGraph *	maker(int const x, int const y)
  {
    IGraph *g = new opengl(x, y);

    return (g);
  }
}

opengl::opengl(const int width, const int height)
{
  this->width = width;
  this->height = height;
  xSDL_Init(SDL_INIT_VIDEO);
  xatexit(SDL_Quit);
  SDL_WM_SetCaption("OPENGL Application", NULL);
  xSDL_SetVideoMode(800, 600, 32, SDL_OPENGL);
  glMatrixMode(GL_PROJECTION);
  gluOrtho2D(0, 800, 0, 600);
  glLoadIdentity();
  gluPerspective(70, (double)800/600, 1, 1000);
  glEnable(GL_DEPTH_TEST);
  create_map(0, 0, false);
  put_map(false);
  reset_size();
}

opengl::~opengl()
{
  ;
}

void			opengl::reset_size()
{
  this->size_x_1 = 0.4;
  this->size_y_1 = 0.4;
  this->size_x_2 = 0.8;
  this->size_y_2 = 0.8;  
}

void			opengl::put_snake_frame(const int x, const int y)
{
  double	       	_x;
  double       		_y;

  _x = (x - (static_cast<double>(this->width) / 2)) / 20;
  _y = (y - (static_cast<double>(this->height) / 2)) / 20;
  glClear(GL_DEPTH_BUFFER_BIT);
  glBegin(GL_QUADS);  
  glColor3ub(180, 0, 24);
  glVertex3d(((_x) + this->size_x_1), ((_y) + this->size_y_2), 1);
  glVertex3d(((_x) + this->size_x_1), ((_y) + this->size_y_1), 1);
  glVertex3d(((_x) + this->size_x_2), ((_y) + this->size_y_1), 1);
  glVertex3d(((_x) + this->size_x_2), ((_y) + this->size_y_2), 1);
  glEnd();
  glFlush();
  SDL_GL_SwapBuffers();
  reset_size();
}

void			opengl::del_frame(const int x, const int y)
{
  double       		_x;
  double       		_y;

  _x = (x - (static_cast<double>(this->width) / 2)) / 20;
  _y = (y - (static_cast<double>(this->height) / 2)) / 20;
  glClear(GL_DEPTH_BUFFER_BIT );
  glBegin(GL_QUADS);
    glColor3ub(20, 50, 250);
  glVertex3d(((_x) + this->size_x_1), ((_y) + this->size_y_2), 1);
  glVertex3d(((_x) + this->size_x_1), ((_y) + this->size_y_1), 1);
  glVertex3d(((_x) + this->size_x_2), ((_y) + this->size_y_1), 1);
  glVertex3d(((_x) + this->size_x_2), ((_y) + this->size_y_2), 1);
  glEnd();
  glFlush();
  SDL_GL_SwapBuffers();
  reset_size();
}

void			opengl::lost()
{
  glClear(GL_DEPTH_BUFFER_BIT);
  put_map(true);
  SDL_Delay(1000);
  std::cout << "You lose" << std::endl;
}

int			opengl::wait_event()
{
  SDL_Event		event;

  SDL_Delay(100);
  glFlush();
  SDL_GL_SwapBuffers();
  SDL_PollEvent(&event);
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
  return (0);
}

void			opengl::free_graph()
{
  ;
}

void			opengl::put_apple_frame(const int x, const int y)
{
  double		_x;
  double		_y;

  _x = (x - (static_cast<double>(this->width) / 2)) / 20;
  _y = (y - (static_cast<double>(this->height) / 2)) / 20;
  glClear(GL_DEPTH_BUFFER_BIT );
  glBegin(GL_QUADS);
  glColor3ub(22, 184, 78);
  glVertex3d(((_x) + this->size_x_1), ((_y) + this->size_y_2), 1);
  glVertex3d(((_x) + this->size_x_1), ((_y) + this->size_y_1), 1);
  glVertex3d(((_x) + this->size_x_2), ((_y) + this->size_y_1), 1);
  glVertex3d(((_x) + this->size_x_2), ((_y) + this->size_y_2), 1);
  glEnd();
  glFlush();
  SDL_GL_SwapBuffers();  
  reset_size();
}

void			opengl::create_map(const double & x, const double & y, const bool map)
{
  double			_x;
  double			_y;
  
  _x = (x - (this->width / 2)) / 20;
  _y = (y - (this->height / 2)) / 20;
  if (x == 0 || x == this->width || y == 0 || y == this->height)
    glColor3ub(255, 255, 0);
  else if (map == 1)
    glColor3ub(255, 255, 0);
  else
    glColor3ub(20, 50, 250);
  glBegin(GL_QUADS);
  glVertex3d(((_x) + this->size_x_1), ((_y) + this->size_y_2), 1);
  glVertex3d(((_x) + this->size_x_1), ((_y) + this->size_y_1), 1);
  glVertex3d(((_x) + this->size_x_2), ((_y) + this->size_y_1), 1);
  glVertex3d(((_x) + this->size_x_2), ((_y) + this->size_y_2), 1);
  glEnd();
  reset_size();
}

void			opengl::put_map(const bool map)
{
  double			x;
  double			y;

  if (map == false)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(9, 4.2 * (this->width / 100  + this->height / 100) / 2, 15, 0, 0, 0, 0, 0, 1);
  x = 0;
  y = 0;
  while (x < this->width + 12)
    {
      y = 0;
      while (y < this->height + 12)
	{
	  create_map(x, y, map);
	  y += 12;
	}
      x += 12;
    }
  glFlush();
  SDL_GL_SwapBuffers();
}
