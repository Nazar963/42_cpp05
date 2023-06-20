CC = c++ -Wall -Wextra -Werror -std=c++98
CFILES = main.cpp Bureaucrat.cpp Form.cpp
NAME = Form

all: $(NAME)

$(NAME):
	$(CC) -g $(CFILES) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean flcean re