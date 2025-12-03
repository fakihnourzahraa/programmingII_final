
MAKEFLAGS += -s

NAME      := final
CC        := cc
CFLAGS    := -Wall -Wextra -Werror

MLX_DIR   := minilibx-linux
MLX_LIB   := $(MLX_DIR)/libmlx.a
MLX_FLAGS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC       := \
	system_functions/ft_strchr.c \
	system_functions/ft_strdup.c \
	system_functions/ft_strjoin.c \
	system_functions/ft_strlen.c \
	system_functions/ft_substr.c \
	system_functions/get_next_line.c \
	system_functions/ft_printf_utils0.c \
	system_functions/ft_printf_utils1.c \
	system_functions/ft_printf.c \
	SRC/Free_memory.c \
	system_functions/ft_itoa.c \
	SRC/extra_functions.c \
	SRC/map_fill_load.c \
	SRC/map_loop_exits.c \
	SRC/map_mlx.c \
	SRC/map_moving.c \
	SRC/map_parsing_2.c \
	SRC/map_parsing.c \
	SRC/map_parsing3.c \
	SRC/main.c

OBJS      := $(SRC:.c=.o)
INCLUDES  := -I. -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS)
	@echo "→ Building target $(NAME)… 🐢"
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) > /dev/null 2>&1
	@echo "✔  $(NAME) built successfully 🐢."

$(MLX_LIB):
	@echo "→ Building MiniLibX… 📚"
		@if $(MAKE) -C $(MLX_DIR) > /dev/null 2>&1; then \
		echo "✔  MiniLibX built successfully 📖."; \
	else \
		echo "❌ MiniLibX build failed. Trying without redirection..."; \
		$(MAKE) -C $(MLX_DIR); \
	fi

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

clean:
	@echo "→ Cleaning object files… 🗑️"
	@rm -f $(OBJS)
	@echo "→ Cleaning MiniLibX… 🗑️"
	@$(MAKE) -s -C $(MLX_DIR) clean > /dev/null 2>&1

fclean: clean
	@echo "→ Removing executable… 🗑️"
	@rm -f $(NAME)
	@echo "→ Cleaning full MiniLibX… 🗑️"
	@$(MAKE) -s -C $(MLX_DIR) clean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re
