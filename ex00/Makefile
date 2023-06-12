CC = c++ -Wall -Wextra -Werror -std=c++98
CFILES = main.cpp Bureaucrat.cpp
MAIN = Bureaucrat

all: $(MAIN)

$(MAIN):
	$(CC) -g $(CFILES) Bureaucrat.hpp -o $(MAIN)

clean:
	rm $(MAIN)

fclean: clean

re: fclean all

.PHONY: all clean flcean re