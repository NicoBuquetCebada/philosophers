NAME = philo

SRCS =	$(shell find ./src -iname "*.c")
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -pthread -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re