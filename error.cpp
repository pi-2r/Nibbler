#include	"error.hh"

Error::Error()
{
}

void	Error::Speak(const std::string msg)
{
  std::cerr << msg << std::endl;
}

void	*Error::Verif(int ac, char **av)
{
  if (ac < 4)
    {
      Speak("Usage : ./nibbler <width> <height> <./lib>");
      return NULL;
    }
  _dlhandle = dlopen(av[3], RTLD_LAZY);
  if ((_dlerr = dlerror()))
    {
     Speak(_dlerr);
      if (av[3][0] != '.' || av[3][1] != '/')
        Speak("Don't forget to put ./mylib");
      return NULL;
    }
  return (_dlhandle);
}

Error::~Error()
{
}
