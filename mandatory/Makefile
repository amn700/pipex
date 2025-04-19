CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = helper_functions0.c  helper_functions1.c helper_functions2.c helper_functions3.c main.c pipex.c  split_pipex.c
OBJS = $(SRCS:.c=.o)
NAME = pipex
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re