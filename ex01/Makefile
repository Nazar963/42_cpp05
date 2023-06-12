CC = c++ -Wall -Wextra -Werror -std=c++98
CFILES = main.cpp Bureaucrat.cpp Form.cpp
MAIN = Form

all: $(MAIN)

$(MAIN):
	$(CC) -g $(CFILES) Bureaucrat.hpp Form.hpp -o $(MAIN)

clean:
	rm $(MAIN)

fclean: clean

re: fclean all

.PHONY: all clean flcean re