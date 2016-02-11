#ifndef	_ERROR_HH_
#define	_ERROR_HH_

#include	<iostream>
#include	"snake.hh"

class	Error
{
private:
  char	*_dlerr;
  void	*_dlhandle;

public:
  Error();
  virtual ~Error();

  void	Speak(const std::string);
  void	*Verif(int, char**);
};

#endif
