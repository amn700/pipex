CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = helper_functions1.c  here_doc.c  main.c  helper_functions0.c  pipex.c
OBJS = $(SRCS:.c=.o)
NAME = pipex
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
GNL_DIR = ./get_next_line
GNL = $(GNL_DIR)/gnl.a

all: $(LIBFT)  $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(GNL) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re