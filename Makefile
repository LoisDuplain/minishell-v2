#	Includes
-include includes.mk
-include sources.mk

#	Names
NAME				=	minishell

#	Colors
BLACK				=	\033[0;30m
RED					=	\033[0;31m
GREEN				=	\033[0;32m
ORANGE				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[0;35m
CYAN				=	\033[0;36m
LIGHT_GRAY			=	\033[0;37m
DARK_GRAY			=	\033[1;30m
LIGHT_RED			=	\033[1;31m
LIGHT_GREEN			=	\033[1;32m
YELLOW				=	\033[1;33m
LIGHT_BLUE			=	\033[1;34m
LIGHT_PURPLE		=	\033[1;35m
LIGHT_CYAN			=	\033[1;36m
WHITE				=	\033[1;37m
NO_COLOR			=	\033[0m

#	Compilation
GCC					=	gcc
FLAGS				=	-Wall -Wextra -Werror -O3 -Ofast -flto -march=native -ffast-math
LIBFT_PATH			=	./libft

BREW_PATH			=	/usr/local/opt
-include brew.mk

INCLUDES_PATH		=	./includes
INCLUDES			+=	$(BREW_PATH)/readline/include/readline

OBJS				=	$(SOURCES:.c=.o)

#	Rules
#	Default rule
all:	$(NAME)

#	How to convert .c in .o
%.o:	%.c $(LIBFT_PATH)/libft.a $(INCLUDES)
	@$(GCC) $(FLAGS) -I $(INCLUDES_PATH) -c $< -o $@
	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(PURPLE)$<$(RESET)"

#	Compile libft.a
$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH)

#	Compile minishell program
$(NAME):	$(LIBFT_PATH)/libft.a $(INCLUDES) $(OBJS)
	@$(GCC) -L $(BREW_PATH)/readline/lib -l readline.8.1 $(LIBFT_PATH)/libft.a $(FLAGS) -I $(INCLUDES_PATH) $(OBJS) -o $(NAME)
	@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUE): $(GREEN)Compiled [√]$(RESET)\n"

#	Clean project
#	Clean
clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS)
	@printf "$(BLUE)$(NAME): $(LIGHT_RED)Cleaning all .o in project.\n$(RESET)"

#	Full clean
fclean:		clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)
	@printf "$(BLUE)$(NAME): $(RED)Cleaning compiled programs $(NAME).\n$(RESET)"

#	Recompile all
re:		fclean all

#	Check norminette
norminette: clean
	@printf "$(BLUE)$(NAME): $(GREEN)norminette -> sources\n$(RESET)"
	@norminette sources
	@echo " "
	@printf "$(BLUE)$(NAME): $(GREEN)norminette -> includes\n$(RESET)"
	@norminette includes

#	Prepare to push project
end:
	@make fclean
	@make gmk
	@make all
	@make norminette
	@make fclean
	@printf "$(BLUE)$(NAME): $(LIGHT_CYAN)Prepared to be pushed.\n$(RESET)"

#	Generate .mk (Makefile includes)
gmk:
	@find $(INCLUDES_PATH) -type f -name '*.h' | sed 's/^/INCLUDES += /' > includes.mk
	@find sources -type f -name '*.c' ! -path "sources/program/*" | sed 's/^/SOURCES += /' > sources.mk