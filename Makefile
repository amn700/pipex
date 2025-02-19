CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = helper_functions1.c  here_doc.c  main.c  helper_functions0.c  pipex.c
SRCSB = helper_functions0_bonus.c helper_functions1_bonus.c here_doc_bonus.c main_bonus.c pipex_bonus.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
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

bonus : $(LIBFT) $(OBJSB) $(GNL)
	$(CC) $(CFLAGS) $(OBJSB) $(LIBFT) $(GNL) -o $(NAME)

clean:
	rm -rf $(OBJS) $(OBJSB)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re