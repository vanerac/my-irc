##
## EPITECH PROJECT, 2021
## qui lit ca meme ?
## File description:
## Makefile ...
##

NAME				=	../myteams_server
TNAME				=	unit_test

SRC					=	server.c			\
						handles.c			\
						commands/help.c		\
						commands/use.c		\
						commands/create.c	\
						commands/login.c	\
						str_to_word_array.c

TRC					=	test_basic.c
MAIN				= 	main.c

OBJ					=	$(SRC:.c=.o)
TOBJ				=	$(TRC:.c=.o)
OMAIN				=	$(MAIN:.c=.o)

LIBS				=	../libnode.a 		\
						../libsockets.a		\
						../libmessage.a

OBJECTS				=	$(addprefix ./src/, $(OBJ))
TOBJECTS			=	$(addprefix ./tests/, $(TOBJ))
ABS_LIBS			=	$(addprefix -l../lilbs/, $(LIBS))

CFLAGS				+=	-Iincludes/ -I../includes/ -Wall -Wextra -Werror -g

RM					=	rm -rf


all:				$(NAME)

$(NAME):			$(OMAIN) $(OBJECTS)
					$(CC) -o $(NAME) $(OBJECTS) -ldl $(OMAIN) $(LIBS) -luuid

fclean:				clean
					$(RM) $(NAME) $(TNAME)

clean:
						$(RM) 	$(OBJECTS) 			\
								$(TOBJECTS)			\
								$(OBJECTS:.o=.gcno) \
								$(OBJECTS:.o=.gcda) \
						  		$(TOBJECTS:.o=.gcno)\
								$(TOBJECTS:.o=.gcda)\
								$(OMAIN:.o=.gcda)	\
								$(OMAIN:.o=.gcno)	\
								$(OMAIN)

tests_run:			CFLAGS += -g --coverage
tests_run:			$(TOBJECTS) $(OBJECTS)
					$(CC) -o $(TNAME) $(TOBJECTS) $(OBJECTS) $(LIBS)\
						-lgcov -lcriterion -luuid

re:					fclean all

.PHONY:				all $(NAME) clean fclean re