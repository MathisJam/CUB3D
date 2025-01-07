# Program nameeuheuie
NAME		=	cub3D

# Compilation flags
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-lXext -lX11 -lm

# MiniLibx
MLX_PATH	=	mlx_linux/
MLX_NAME	=	libmlx.a
MLX			=	$(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	=	libft/
LIBFT_NAME	=	libft.a
LIBFT		=	$(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC			=	-I ./libft/\
				-I ./mlx_linux/\
				-I ./inc/

# Sources
SRC_PATH	=	src/
SRC			=	main.c init.c utils.c

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	=	obj/
OBJ			=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))

# Color codes for terminal output
RESET = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SILENT		=	> /dev/null 2>&1

# --------------------------------------------------------------------------------- #

# Default target calling for the executable
all: $(LIBFT) $(MLX) $(NAME)

# Target for cloning and making the MiniLibx library
$(MLX):
	@echo "$(BLUE)Making MiniLibx..."
	@echo "$(BLUE)Cloning 'mlx' from https://github.com/42Paris/minilibx-linux..."
	@git clone git@github.com:42Paris/minilibx-linux.git mlx_linux $(SILENT)
	@echo "$(BLUE)Compiling MiniLibx..."
	@make -sC $(MLX_PATH) $(SILENT)

# Target for making the Libft
$(LIBFT):
	@echo "$(BLUE)Making $(LIBFT)..."
	@make -sC $(LIBFT_PATH)

# Target to build the mandatory part
$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling... \n $(RESET)"
	@echo "$(RED)   ____     _   _     ____    _____     ____"
	@echo "$(YELLOW)U / ___|   | |u| | U | __  u |___ /u   |  _ \   "
	@echo "$(GREEN)\| | u    \| |\| |  \|  _ \/ U_|_ \/  /| | | |"
	@echo "$(CYAN) | |/__    | |_| |   | |_) |  ___) |  U| |_| |\ "
	@echo "$(BLUE)  \____|    \___/    |____/  |____/    |____/ u"
	@echo "$(RED) _// \\       )(      _|| \\\_   _// \\      |||_    "
	@echo "$(MAGENTA)(__)(__)    (__)   (__) (__) (__)(__)   (__)_)   $(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) $(MLXFLAGS)
	@echo "$(YELLOW)\n	\o\ Compilation completed! /o/\n"

# Compiles C source files into object files
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Cleans object files and dependencies
clean:
	@echo "$(GRAY)Removing .o object files..."
	@rm -rf $(OBJ_PATH) $(SILENT)
	@make clean -C $(MLX_PATH) $(SILENT)
	@make clean -C $(LIBFT_PATH) $(SILENT)
	@echo "$(GRAY).o object files removed!"

# Cleans everything generated by the Makefile
fclean:	clean
	@echo "$(GRAY)Removing $(NAME)..."
	@rm -rf $(MLX_PATH)
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)
	@echo "$(YELLOW)\n\o\ All created files have been removed! /o/\n"

# Cleans everything generated by the Makefile and rebuilds all
re: fclean all

# Phony targets
.PHONY: all clean fclean re
