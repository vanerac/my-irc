##
## EPITECH PROJECT, 2021
## qui lit ca meme ?
## File description:
## Makefile ...
##

NAME				=	../../libsockets.a
TNAME				=	unit_test

SRC					=	socket_client.c	\
						socket_server.c	\
						sockets.c

TRC					=

OBJ					=	$(SRC:.c=.o)
TOBJ				=	$(TRC:.c=.o)

OBJECTS				=	$(addprefix ./src/, $(OBJ))
TOBJECTS			=	$(addprefix ./tests/, $(TOBJ))
CFLAGS				+=	-Iincludes/ -Wall -Wextra -Werror

RM					=	rm -rf

all:				$(NAME)


$(NAME):			$(OBJECTS)
					ar rc $(NAME) $(OBJECTS)

clean:
					$(RM) $(OBJECTS) $(TOBJECTS)

fclean:				clean
					$(RM) $(NAME) $(TNAME)

tests_run:			CFLAGS += -lcriterion -l ./$(NAME) -g -lgcov --coverage
tests_run:			$(TOBJECTS) $(OBJECTS)
					$(LD) -o $(TNAME) $(TOBJECTS) $(OBJECTS)
					./$(TNAME)

re:					fclean all

.PHONY:				all $(NAME) clean fclean re