CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

NAME = client
NAMESR = server

SRCCL = src/client.c
SRCSR = src/server.c

OBJCL = $(SRCCL:.c=.o)
OBJSR = $(SRCSR:.c=.o)

all: $(NAME) $(NAMESR)

$(NAME): $(OBJCL) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJCL) -L libft/ -lft -o $(NAME)

$(NAMESR): $(OBJSR) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJSR) -L libft/ -lft -o $(NAMESR)

%.o	 : %.c
		@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		make -C libft/


clean:
		make clean -s -C libft
		rm -rf $(OBJCL) $(OBJSR)

fclean: clean
		rm -rf $(NAME) $(NAMESR)
		make fclean -s -C libft

re: fclean all

.PHONY: all clean fclean re