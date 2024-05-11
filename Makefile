CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

NAMECL = client
NAMESR = server
NAMECL_BONUS = client_bonus
NAMESR_BONUS = server_bonus

SRCCL = src/client.c src/parsing.c
SRCSR = src/server.c
SRCCL_BONUS = src/client_bonus.c src/parsing.c
SRCSR_BONUS = src/server_bonus.c

OBJCL = $(SRCCL:.c=.o)
OBJSR = $(SRCSR:.c=.o)
OBJCL_BONUS = $(SRCCL_BONUS:.c=.o)
OBJSR_BONUS = $(SRCSR_BONUS:.c=.o)

all: $(NAMECL) $(NAMESR)

$(NAMECL): $(OBJCL) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJCL) -L libft/ -lft -o $(NAMECL)

$(NAMESR): $(OBJSR) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJSR) -L libft/ -lft -o $(NAMESR)

$(NAMECL_BONUS): $(OBJCL_BONUS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJCL_BONUS) -L libft/ -lft -o $(NAMECL_BONUS)

$(NAMESR_BONUS): $(OBJSR_BONUS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJSR_BONUS) -L libft/ -lft -o $(NAMESR_BONUS)

%.o	 : %.c
		@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		make -C libft/


clean:
		make clean -s -C libft
		rm -rf $(OBJCL) $(OBJSR) $(OBJCL_BONUS) $(OBJSR_BONUS)

bonus: $(NAMECL_BONUS) $(NAMESR_BONUS)

fclean: clean
		rm -rf $(NAMECL) $(NAMESR) $(NAMECL_BONUS) $(NAMESR_BONUS)
		make fclean -s -C libft

re: fclean all

.PHONY: all clean fclean re bonus
