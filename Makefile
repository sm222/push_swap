RED		=	"\x1B[31m"
GRN		=	"\x1B[32m"
YEL		=	"\x1B[33m"
BLU		=	"\x1B[34m"
MAG		=	"\x1B[35m"
CYN		=	"\x1B[36m"
WHT		=	"\x1B[37m"
RESET	=	"\x1B[0m"
CLE 	=	\e[1;1H\e[2J

NAME	=	push_swap
LIBFT	=	libft.a
LDIR	=	lib_ft/

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM	=	rm	-f

#-Wall -Werror -Wextra -FD_CLOEXEC
#-fsanitize=address
#--recurse-submodules
# Sources are all .c files
SRCS	=	pp.c\
			ss.c\
			rr.c\
			utilse.c\
			tools.c\
			rrr.c\
			node.c\
			algo.c\
			algo_small.c\
			main.c

OBJS	=	$(SRCS:.c=.o)

USER = $(shell whoami)

all: libft $(NAME) 
	@echo $(shell reset)$(GRN)
	@echo "				push_swap made by anboisve\n " $(RESET)
#	@cat logo.txt
	@echo $(CYN) "\n\n			correction is made by $(USER)\n\n " $(RESET)
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDIR)$(LIBFT) -o $(NAME)

libft:
	@$(MAKE) -C $(LDIR)

# Generates output file
# Removes objects
clean:
	$(RM) $(OBJS)
	$(RM) $(LDIR)*.o
	@echo $(shell clear) $(GRN) clean *.o$(RESET)

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LDIR)$(LIBFT)
	@echo $(shell clear) $(GRN) clean all$(RESET)

run:
	leaks --atExit -- ./push_swap 4 2 1 5 0

vis: all
	./push_swap_visualizer/build/bin/visualizer
# Removes objects and executables and remakes
re: fclean all

test:
	@echo "10 tests/ 0 - 500"
	@./push_swap `ruby -e "puts (0..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..500).to_a.shuffle.join(' ')"` | wc -l
	@./push_swap `ruby -e "puts (0..500).to_a.shuffle.join(' ')"` | wc -l
	@echo "/	/	/	/	/"

.PHONY: all libft