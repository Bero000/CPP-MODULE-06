NAME = Identify

CC = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -rf

SRC = main.cpp Base.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	@$(CC) $(CCXFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

s: 
	@make r
	@./Identify
	@make f

r:re
c:clean
f:fclean