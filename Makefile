NAME		=	nibbler
NAME_LIB1	=	lib_nibbler_SDL.so
NAME_LIB2	=	lib_nibbler_OPENGL.so
NAME_LIB3	=	lib_nibbler_NCURSES.so

SRCS		=	main.cpp		\
		 	snake.cpp		\
			error.cpp		\
			point_handle.cpp	\
			core.cpp

SRCS_LIB1	=	lib_SDL/graph.cpp	\
			lib_SDL/xfunc_sdl.cpp

SRCS_LIB2	=	lib_OPENGL/opengl.cpp	\
			lib_OPENGL/xfunctions.cpp

SRCS_LIB3	=	lib_NCURSES/graph.cpp

OBJS		=	$(SRCS:.cpp=.o)
OBJS_LIB1	=	$(SRCS_LIB1:.cpp=.o)
OBJS_LIB2	=	$(SRCS_LIB2:.cpp=.o)
OBJS_LIB3	=	$(SRCS_LIB3:.cpp=.o)
CC		=	g++
RM		=	rm -rf
CXXFLAGS	=	-W -Wall	\
		 	-fPIC		\
		 	-ldl		\
			-lcurses

LDLIBS		=	-lXext -lX11 -lXmu -lXi -lGL -lGLU -lm -lSDL -lSDL_mixer

LDFLAGS		=	-I/usr/local/include/SDL	\
		 	-I/usr/local/include 		\
		 	-D_GNU_SOURCE=1 		\
		 	-D_REENTRANT 			\
		 	-I. -L/usr/local/lib 		\
		 	-Wl,-rpath,/usr/local/lib 	\
		 	-lSDL -pthread	 		\
		 	-lSDL_image 			\
		 	-lSDL_ttf			\
			-L/usr/X11R6/lib		\
			-L/usr/lib			\
			-L/lib


ECHO		=	echo -e

$(NAME)		: 	$(OBJS_LIB1)  $(OBJS_LIB2) $(OBJS_LIB3) $(OBJS)
	  		@$(ECHO) '\033[0;32m>> Object files Created\033[0m'
			$(CC) -shared -o $(NAME_LIB1) $(OBJS_LIB1) $(LDFLAGS) $(CXXFLAGS)
	  		@$(ECHO) '\033[0;32m>> Lib SDL Created\033[0m'
			$(CC) -shared -o $(NAME_LIB2) $(OBJS_LIB2) $(LDLIBS) $(LDFLAGS) $(CXXFLAGS)
	  		@$(ECHO) '\033[0;32m>> Lib OPENGL Created\033[0m'
			$(CC) -shared -o $(NAME_LIB3) $(OBJS_LIB3) $(LDFLAGS) $(CXXFLAGS)
	  		@$(ECHO) '\033[0;32m>> Lib NCURSES Created\033[0m'
			$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(CXXFLAGS)
			@$(ECHO) '\033[0;32m>> Nibbler Created\033[0m'

all		:	$(NAME)

clean		: 
			$(RM) $(OBJS) $(OBJS_LIB1) $(OBJS_LIB2) $(OBJS_LIB3)
			@$(ECHO) '\033[0;32m>> Object files deleted\033[0m'

fclean		: 	clean
			$(RM) $(NAME) $(NAME_LIB1) $(NAME_LIB2) $(NAME_LIB3)
			@$(ECHO) '\033[0;32m>> Binary file and Lib deleted\033[0m'
			$(RM) *~
			@$(ECHO) '\033[0;32m>> Binary file and Lib deleted\033[0m'
re		: fclean all
