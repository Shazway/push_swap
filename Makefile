CXX = clang

CXXFLAGS = -Wall -Werror -Wextra -fsanitize=address -g -Iincludes

NAME = push_swap

SRCS =	srcs/push_swap.c		\
		srcs/elems.c			\
		srcs/long_stack_utils.c	\
		srcs/operations_a.c		\
		srcs/operations_b.c		\
		srcs/operations_both.c	\
		srcs/scans.c			\
		srcs/utils.c			\
		srcs/utils2.c			\
		srcs/utils3.c			\
		srcs/utils4.c			\
		srcs/errors.c			\
		srcs/errors2.c			\
		srcs/b.c				\
		srcs/a.c				\
		srcs/apply_moves.c		\

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
		$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:	cleannorme
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

norme:				checknorme
					@-grep < norme_trace 'Error' > norme_error ||:
					@echo "\nGreped errors:\033[1;31m"
					@cat norme_error

checknorme:
					-@norminette srcs > norme_trace
					-@norminette includes >> norme_trace
					-@cat norme_trace

cleannorme:
					@-rm -f norme_trace
					@-rm -f norme_error