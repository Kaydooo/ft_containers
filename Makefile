
# $< "include one prerequisite"
# $@ "include target"
# $^ "include the full list of prerequisites"

SRCS = main.cpp

OBJS = ${SRCS:.cpp=.o}

CXX = c++

CXXFLAGS = -Werror -Wall -Wextra -g3 

NAME = ft_containers
	
all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
	
re:	fclean all

.PHONY:	all clean fclean re
