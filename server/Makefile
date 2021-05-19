##
## EPITECH PROJECT, 2021
## qui lit ca meme ?
## File description:
## Makefile ...
##

NAME				=	myteams_server
TNAME				=	unit_test

SRC					=	server.c
TRC					=	test_basic.c
MAIN				= 	main.c

OBJ					=	$(SRC:.c=.o)
TOBJ				=	$(TRC:.c=.o)
OMAIN				=	$(MAIN:.c=.o)

OBJECTS				=	$(addprefix ./src/, $(OBJ))
TOBJECTS			=	$(addprefix ./tests/, $(TOBJ))

CFLAGS				+=	-Iincludes/ -I../includes/

RM					=	rm -rf
LD					=	gcc


all:				$(NAME)


$(NAME):			$(OMAIN) $(OBJECTS)
					$(CC) -o $(NAME) $(OBJECTS) $(OMAIN)

clean:
					$(RM) $(OBJECTS) $(TOBJECTS) $(OMAIN)

fclean:				clean
					$(RM) $(NAME) $(TNAME) $(OMAIN)

tests_run:			CFLAGS += -lcriterion -g -lgcov --coverage
tests_run:			$(NAME) $(TOBJECTS)
					$(LD) -o $(TNAME) $(TOBJECTS) $(OBJECTS)
					./$(TNAME)

re:					fclean all

.PHONY:				all $(NAME) clean fclean re