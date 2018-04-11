NAME = fdf

# compiler
CC = gcc
CFLAGS = -Wall -Werror -Wextra
DEBUG = -g
# FLAGS += $(DEBUG)
ASAN = -fsanitize=address
DEBUG += $(ASAN)

# directories
OBJ_DIR = obj/
SRC_DIR = src/
INC_DIR = includes/
LIBFT_DIR = libft/

# mlx library
MLX		= ./miniLibX/
MLX_LIB	= $(addprefix $(MLX), mlx.a)
MLX_INC	= -I ./miniLibX
MLX_LNK	= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

# files
SRC_FILES = $(notdir $(wildcard $(SRC_DIR)*.c))
OBJ_FILES = $(SRC_FILES:%.c=%.o)

# full path
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
INCLUDES = -I $(LIBFT_DIR)includes -I includes/ $(MLX_INC)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(MLX_LNK) -lm $(LIBFT)
	@echo "[INFO] fdf created"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "[INFO] Objects removed."

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm $(NAME)
	@echo "[INFO] fdf removed"

re: fclean all

.PHONY: all $(NAME) clean fclean re
