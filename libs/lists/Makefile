##
## EPITECH PROJECT, 2021
## qui lit ca meme ?
## File description:
## Makefile ...
##

NAME				=	../../libnode.a
TNAME				=	unit_test

SRC					=	list.c			\
						list_delete.c	\
						list_find.c

TRC					=	test_create.c	\
						test_delete.c	\
						test_find.c

OBJ					=	$(SRC:.c=.o)
TOBJ				=	$(TRC:.c=.o)

OBJECTS				=	$(addprefix ./src/, $(OBJ))
TOBJECTS			=	$(addprefix ./tests/, $(TOBJ))
CFLAGS				+=	-Iincludes/ -Wall -Wextra -Werror

RM					=	rm -rf
LD					=	gcc



all:				$(NAME)


$(NAME):			$(OBJECTS)
					ar rc $(NAME) $(OBJECTS)

clean:
					$(RM) $(OBJECTS) $(TOBJECTS)

fclean:				clean
					$(RM) $(NAME) $(TNAME)

tests_run:			CFLAGS += -lcriterion -g --coverage
tests_run:			$(TOBJECTS) $(OBJECTS)
					$(LD) -o $(TNAME) $(TOBJECTS) $(OBJECTS)
					./$(TNAME)

re:					fclean all

.PHONY:				all $(NAME) clean fclean re