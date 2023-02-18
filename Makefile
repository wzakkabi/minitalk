NAME = minitalk.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

SOURCES = client.c server.c ft_putnbr_fd.c ft_atoi.c

OBJ = $(SOURCES:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $<

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	$(CC) $(FLAGS) client.c -o client minitalk.a
	$(CC) $(FLAGS) server.c -o server minitalk.a 

fclean : clean
	rm -rf $(NAME) server client

clean :
	rm -rf $(OBJ)

re : fclean all
