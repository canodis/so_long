CC			= gcc
MINILIBX	= minilibx/libmlx.a
FLAGS		= -Wall -Wextra -Werror
LFLAGS		= -framework OpenGL -framework AppKit
NAME		= so_long
BNAME		= so_long_bonus
SRCS 		= src/so_long.c src/convert_xpms.c src/ft_create_map.c src/ft_init_map.c src/ft_split_fs.c src/key_events.c src/so_long_utils.c
BSRCS		= bonus/so_long_b.c bonus/convert_xpms_b.c bonus/ft_create_map_b.c bonus/ft_init_map_b.c bonus/ft_split_fs_b.c bonus/key_events_b.c bonus/so_long_utils_b.c bonus/ft_animator_b.c
OBJS		= $(SRCS:.c=.o)
BOBJS		= $(BSRCS:.c=.o)
all: $(NAME)

$(NAME): $(MINILIBX) $(OBJS)
	$(CC) $(LFLAGS) $(FLAGS) $(OBJS) -o $(NAME) ./ft_printf/libftprintf.a ./libft/libft.a minilibx/libmlx.a

bonus: $(BNAME)

$(BNAME): $(MINILIBX) $(BOBJS)
	$(CC) $(LFLAGS) $(FLAGS) $(BOBJS) -o $(BNAME) ./ft_printf/libftprintf.a ./libft/libft.a minilibx/libmlx.a

$(MINILIBX):
	make -C minilibx
	@echo "MINILIBX compile edildi !"

norm:
	@norminette src/*.c include/*.h
	@norminette bonus/*.c
run: all
	./$(NAME) maps/map_1.ber
re: fclean all
clean:
	rm -rf $(OBJS)
	rm -rf $(BOBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BNAME)
	@make clean -C minilibx
	@make clean -C ft_printf
.PHONY: clean run fclean re all norm
