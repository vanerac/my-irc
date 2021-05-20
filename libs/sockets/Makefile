##
## EPITECH PROJECT, 2021
## qui lit ca meme ?
## File description:
## Makefile ...
##

NAME				=	lib_sockets.a
TNAME				=	unit_test

SRC					=	socket_client.c	\
						socket_server.c	\
						sockets.c

TRC					=

OBJ					=	$(SRC:.c=.o)
TOBJ				=	$(TRC:.c=.o)

OBJECTS				=	$(addprefix ./src/, $(OBJ))
TOBJECTS			=	$(addprefix ./tests/, $(TOBJ))
CFLAGS				+=	-Iincludes/

RM					=	rm -rf
LD					=	gcc


all:				$(NAME)


$(NAME):			$(OBJECTS)
					ar rc $(NAME) $(OBJECTS)

clean:
					$(RM) $(OBJECTS) $(TOBJECTS)

fclean:				clean
					$(RM) $(NAME) $(TNAME)

tests_run:			CFLAGS += -lcriterion -l ./$(NAME) -g -lgcov --coverage
tests_run:			$(NAME) $(TOBJECTS)
					$(LD) -o $(TNAME) $(TOBJECTS)
					./$(TNAME)

re:					fclean all

.PHONY:				all $(NAME) clean fclean re