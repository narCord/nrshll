CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -std=c23 -g
LDFLAGS :=

TARGET  := programa
SRCS    := main.c exec.c parser.c
OBJS    := $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
