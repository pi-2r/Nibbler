#include	"point_handle.hh"

Point::Point()
{
  size.x = 0;
  size.y = 0;
}

void	Point::setPoint(char **av)
{
  std::istringstream iss(av[1]);
  std::istringstream iss2(av[2]);

  iss >> size.x;
  iss2 >> size.y;
}

bool	Point::checkPoint()
{
  if (size.x < 15 || size.x > 50 || size.y < 15 || size.y > 50)
    {
      error->Speak("please respect the following values :");
      error->Speak("14 > witdh < 50 and 15 > height < 50");
      return (false);
    }
  if (size.x % 2 != 0)
    size.x++;
  if (size.y % 2 != 0)
    size.y++;
  size.x *= 12;
  size.y *= 12;
  return (true);
}

t_point	Point::getSize() const
{
  return size;
}

Point::~Point()
{

}
