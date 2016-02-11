#include	"snake.hh"
#include	"error.hh"
#include	"point_handle.hh"

int			main(int ac, char **av)
{
  char			*dlerr;
  void			*dlhandle;
  IGraph		*(*maker)(int const x, int const y);
  IGraph		*g;
  Error			error;
  Point			point;

  if ((dlhandle = error.Verif(ac, av)) == NULL)
    return (0);
  maker = reinterpret_cast<IGraph* (*)(int const x, int const y)>(dlsym(dlhandle, "maker"));
  if ((dlerr = dlerror()))
    {
      std::cerr << dlerr << std::endl;
      return (0);
    }
  point.setPoint(av);
  if (point.checkPoint() == false)
    return (0);
  g = maker((point.getSize()).x, (point.getSize()).y);
  core(g, (point.getSize()).x, (point.getSize()).y);
  return (0);
}
