NAME = libftprintf.a
CC = cc -g
CFLAGS = -Wall -Wextra -Werror

SRC = ft_putchar.c \
		ft_putstr.c 

OBJ = $(SRC:%.c=%.o)

all: $(NAME)
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "ft_printf is created"
clean:
	@rm -rf $(OBJ) 
fclean: clean
	@rm -rf $(NAME)
re: fclean all 