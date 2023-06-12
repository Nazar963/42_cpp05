CC = c++ -Wall -Wextra -Werror -std=c++98
CFILES = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp
MAIN = Form

all: $(MAIN)

$(MAIN):
	$(CC) -g $(CFILES) Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp -o $(MAIN)

clean:
	rm $(MAIN)

fclean: clean

re: fclean all

.PHONY: all clean flcean re