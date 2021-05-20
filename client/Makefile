##
## EPITECH PROJECT, 2021
## qui lit ca meme ?
## File description:
## Makefile ...
##

NAME				=	../myteams_client
TNAME				=	unit_test

SRC					=
TRC					=
MAIN				= 	main.c

OBJ					=	$(SRC:.c=.o)
TOBJ				=	$(TRC:.c=.o)
OMAIN				=	$(MAIN:.c=.o)

LIBS				=	../libnode.a 		\
						../libsockets.a

OBJECTS				=	$(addprefix ./src/, $(OBJ))
TOBJECTS			=	$(addprefix ./tests/, $(TOBJ))
ABS_LIBS			=	$(addprefix -l../lilbs/, $(LIBS))

CFLAGS				+=	-Iincludes/ -I../includes/ -Wall -Wextra

RM					=	rm -rf
LD					=	gcc

all:				$(NAME)

$(NAME):			$(OMAIN) $(OBJECTS)
					$(CC) -o $(NAME) $(OBJECTS) $(OMAIN) $(LIBS)

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