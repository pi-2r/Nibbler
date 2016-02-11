#ifndef		__IGRAPH_HH__
# define       	__IGRAPH_HH__

class		IGraph
{  
public :
  virtual void	put_snake_frame(const int x, const int y) = 0;
  virtual void	del_frame(const int x, const int y) = 0;
  virtual int	wait_event() = 0;
  virtual void	free_graph() = 0;


  virtual void	put_apple_frame(const int x, const int y) = 0;
  virtual void	lost() = 0;

  virtual ~IGraph() {};  
};

#endif
