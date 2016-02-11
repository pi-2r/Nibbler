#ifndef         __POINT_HANDLE_HH__
#define         __POINT_HANDLE_HH__
#include	"snake.hh"
#include	"error.hh"

class		Point
{
private:
  t_point	size;
  Error		*error;
public:
  Point();
  void		setPoint(char **);
  bool		checkPoint();
  t_point	getSize() const;
  virtual	~Point();
};

#endif
