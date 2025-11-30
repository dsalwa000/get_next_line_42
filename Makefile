NAME = libgnl.a
SRC = get_next_line.c get_next_line_utils.c main.c
OBJ = $(SRC:.c=.o)
PROGRAM = p

MAIN = main.c
BUFFER = -D BUFFER_SIZE=1
LIBRARY = -L. -lgnl

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(GET_NEXT_LINE) $(NAME) $(PROGRAM)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(PROGRAM): $(NAME)
	$(CC) $(CFLAGS) $(BUFFER) $(MAIN) $(LIBRARY) -o $(PROGRAM)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) libft.a

re: fclean all