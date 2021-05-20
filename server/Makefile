##
## EPITECH PROJECT, 2021
## qui lit ca meme ?
## File description:
## Makefile ...
##

NAME				=	../myteams_server
TNAME				=	unit_test

SRC					=	server.c
TRC					=	test_basic.c
MAIN				= 	main.c

OBJ					=	$(SRC:.c=.o)
TOBJ				=	$(TRC:.c=.o)
OMAIN				=	$(MAIN:.c=.o)

LIBS				=	../libnode.a 		\
						../libsockets.a

OBJECTS				=	$(addprefix ./src/, $(OBJ))
TOBJECTS			=	$(addprefix ./tests/, $(TOBJ))
ABS_LIBS			=	$(addprefix -l../lilbs/, $(LIBS))

CFLAGS				+=	-Iincludes/ -I../includes/ -Wall -Wextra -Werror

RM					=	rm -rf


all:				$(NAME)

$(NAME):			$(OMAIN) $(OBJECTS)
					$(CC) -o $(NAME) $(OBJECTS) $(OMAIN) $(LIBS)

clean:
					$(RM) $(OBJECTS) $(TOBJECTS) $(OMAIN)

fclean:				clean
					$(RM) $(NAME) $(TNAME) $(OMAIN)

tests_run:			CFLAGS += -lcriterion -g --coverage
tests_run:			$(TOBJECTS) $(OBJECTS)
					$(CC) -o $(TNAME) $(TOBJECTS) $(OBJECTS) $(ABS_LIBS)
					./$(TNAME)

re:					fclean all

.PHONY:				all $(NAME) clean fclean re