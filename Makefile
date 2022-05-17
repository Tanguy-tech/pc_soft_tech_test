GREY        =   \033[30m
RED         =   \033[31m
GREEN       =   \033[32m
YELLOW      =   \033[33m
BLUE        =   \033[34m
PINK        =   \033[35m
CYAN        =   \033[36m
WHITE       =   \033[37m
BOLD        =   \033[1m
UNDER       =   \033[4m
SUR         =   \033[7m
END         =   \033[0m

NAME = Lexical_analyze

RM	= rm -rf

CC = clang++ -std=c++17

FLAGS = -Wall -Werror -Wextra

SRCS = main.cpp lexical_analyze.cpp 

INCS = lexical_analyze.hpp

OBJS = $(SRCS:.cpp=.o)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			@printf "$(ERASE)$(GREEN)-> Executable Lexical_analyze created! Run ./Lexical_analyze$(END)\n"

all:	$(NAME)

%.o:%.cpp	$(INCS)
			$(CC) $(FLAGS) -c $< -o $@

clean:
		@$(RM) *.o
		@printf "$(ERASE)$(RED)-> All files *.o cleaned$(END)\n"

fclean:	clean
		@$(RM) Lexical_analyze
		@printf "$(ERASE)$(RED)-> Executable cleaned$(END)\n"

re: fclean all