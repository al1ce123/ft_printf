CC = gcc
AR = ar
CFLAGS = -Wall -Werror -g
SANITIZE_FLAGS = -fsanitize=address
NAME = ft_printf
LIBRARY = libmyprintf.a
SRCS_DIR = srcs
SRCS = $(SRCS_DIR)/ft_printf.c \
       $(SRCS_DIR)/parser.c \
       $(SRCS_DIR)/print_char.c \
       $(SRCS_DIR)/print_hex.c \
       $(SRCS_DIR)/print_nbr.c \
       $(SRCS_DIR)/print_percent.c \
       $(SRCS_DIR)/print_ptr.c \
       $(SRCS_DIR)/print_str.c \
       $(SRCS_DIR)/print_u.c \
       $(SRCS_DIR)/utils.c \
       $(SRCS_DIR)/warnings.c \
       main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME) $(LIBRARY)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBRARY): $(OBJS)
	$(AR) rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

debug: CFLAGS += $(SANITIZE_FLAGS)
debug: clean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(LIBRARY)

re: fclean all
