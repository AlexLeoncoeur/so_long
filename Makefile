#---------- BASE ----------#

# FILES 
CFILES =  so_long.c controls.c error.c map.c textures.c\

ORDER_CFILES = 

# DIRECTORIES 
SRC_DIR = src/
ORDER_SRC_DIR = src/order_cmd/
OBJ_DIR = objs/

# OBJECTS
OFILES = $(addprefix $(OBJ_DIR), $(CFILES:.c=.o))
ORDER_OFILES = $(addprefix $(OBJ_DIR)order_cmd/, $(ORDER_CFILES:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)order_cmd/%.o: $(ORDER_SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)/order_cmd/
	$(CC) $(CFLAGS) -c $< -o $@

#---------- BONUS ----------#

# FILES 
BONUS_CFILES = \

BONUS_ORDER_CFILES = 

# DIRECTORIES
BONUS_SRC_DIR = bonus/
BONUS_ORDER_SRC_DIR = bonus/order_cmd/
BONUS_OBJ_DIR = bonus/objs/

# OBJECTS
BONUS_OFILES = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_CFILES:.c=.o))
BONUS_ORDER_OFILES = $(addprefix $(BONUS_OBJ_DIR)order_cmd/, $(BONUS_ORDER_CFILES:.c=.o))

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)order_cmd/%.o: $(BONUS_ORDER_SRC_DIR)%.c
	@mkdir -p $(BONUS_OBJ_DIR)/order_cmd/
	$(CC) $(CFLAGS) -c $< -o $@

#---------- FLAGS & COMPILATION ----------#

CC = clang
NAME = so_long
BONUS_NAME = 
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
MLXFLAGS = include/MLX42/libmlx42.a -ldl -DEBUG=1 -Iinclude -lm -lglfw -L"usr/lib/x86_64-linux-gnu/"

all: libft minilibx $(NAME)
$(NAME): $(OFILES)
	@ $(CC) $(CFLAGS) $(OFILES) $(MLXFLAGS) include/libft/libft.a -o $(NAME)

bonus: all $(BONUS_NAME)
$(BONUS_NAME): $(BONUS_OFILES) $(BONUS_ORDER_OFILES)
	@ $(CC) $(CFLAGS) $(BONUS_OFILES) $(BONUS_ORDER_OFILES) include/libft/libft.a -o $(BONUS_NAME)


#---------- LIBFT & CLEAN ----------#

libft:
	@ make -C  include/libft/ bonus

minilibx:
	@ make -C include/MLX42/

clean:
	@ rm -f $(OFILES) $(ORDER_OFILES) $(BONUS_OFILES) $(BONUS_ORDER_OFILES)
	@ rm -rf $(OBJ_DIR)order_cmd/ $(OBJ_DIR) $(BONUS_OBJ_DIR)order_cmd/ $(BONUS_OBJ_DIR)
	@ make -C include/libft/ clean

fclean: clean
	@ rm -f $(NAME) $(BONUS_NAME)
	@ make -C include/libft/ fclean
	@ make -C include/MLX42/ fclean

re: fclean all
