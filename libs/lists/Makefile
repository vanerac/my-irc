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

TRC					=	tests_create.c	\
						tests_delete.c	\
						tests_find.c		\
						tests_add.c		\
						tests_utils.c

OBJ					=	$(SRC:.c=.o)
TOBJ				=	$(TRC:.c=.o)

OBJECTS				=	$(addprefix ./src/, $(OBJ))
TOBJECTS			=	$(addprefix ./tests/, $(TOBJ))
CFLAGS				+=	-Iincludes/ -Wall -Wextra -Werror

RM					=	rm -rf
#LD					=	gcc



all:				$(NAME)


$(NAME):			$(OBJECTS)
					ar rc $(NAME) $(OBJECTS)

clean:
					$(RM) 	$(OBJECTS) 			\
							$(TOBJECTS)			\
							$(OBJECTS:.o=.gcno) \
						  	$(OBJECTS:.o=.gcda) \
						  	$(TOBJECTS:.o=.gcno)\
							$(TOBJECTS:.o=.gcda)

fclean:				clean
					$(RM) $(NAME) $(TNAME)

tests_run:			CFLAGS += -g
tests_run:			$(NAME) $(TOBJECTS) $(OBJECTS)
					$(CC) -o $(TNAME) $(TOBJECTS) $(OBJECTS)  \
						-lcriterion -lgcov --coverage
					./$(TNAME)

re:					fclean all

.PHONY:				all $(NAME) clean fclean re