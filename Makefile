
# $< "include one prerequisite"
# $@ "include target"
# $^ "include the full list of prerequisites"

FT_SRCS = subj_main_ft.cpp

FT_OBJS = ${FT_SRCS:.cpp=.o}

STD_SRCS = subj_main_std.cpp

STD_OBJS = ${STD_SRCS:.cpp=.o}


CXX = c++

CXXFLAGS = -Werror -Wall -Wextra -std=c++98 -g3 

FT_NAME = ft_containers_FT

STD_NAME = ft_containers_STD
	
all : $(FT_NAME) $(STD_NAME)

$(FT_NAME): $(FT_OBJS)
	$(CXX) $(FT_OBJS) -o $(FT_NAME)

$(STD_NAME): $(STD_OBJS)
	$(CXX) $(STD_OBJS) -o $(STD_NAME)

clean:
	rm -rf $(FT_OBJS) $(STD_OBJS)
fclean: clean
	rm -rf $(FT_NAME) $(STD_NAME)
	
re:	fclean all

.PHONY:	all clean fclean re
