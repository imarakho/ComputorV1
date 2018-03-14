NAME = computor
SRC = main.cpp \
	quadric.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@clang++ $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	clang++ -o $@ -c $<

clean:
	rm	-rf $(OBJ)

fclean: clean
	rm	-rf $(NAME)

re: fclean all