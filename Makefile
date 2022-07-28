
# $< "include one prerequisite"
# $@ "include target"
# $^ "include the full list of prerequisites"

SRCS = subj_main_ft.cpp

OBJS = ${SRCS:.cpp=.o}

CXX = c++

CXXFLAGS = -Werror -Wall -Wextra -std=c++98 -g3 

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
