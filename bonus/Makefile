CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = helper_functions0_bonus.c  here_doc_bonus.c  pipex_bonus.c helper_functions1_bonus.c  main_bonus.c  helper_functions2_bonus.c  split_pipex_bonus.c helper_functions3_bonus.c
OBJS = $(SRCS:.c=.o)
NAME = pipex_bonus
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
GNL_DIR = ../get_next_line
GNL = $(GNL_DIR)/gnl.a

all: $(LIBFT) $(NAME) $(GNL)

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(GNL) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

%.o: %.c pipex_bonus.h
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