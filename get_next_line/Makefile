CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = get_next_line.c get_next_line_utils.c
SRCS_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = gnl.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean