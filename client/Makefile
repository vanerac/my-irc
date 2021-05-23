##
## EPITECH PROJECT, 2021
## qui lit ca meme ?
## File description:
## Makefile ...
##

NAME				=	../myteams_client
TNAME				=	unit_test

SRC					=	manager.c				\
						tools.c					\
						str_to_word_array.c		\
						command_lib.c			\

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

CFLAGS				+=	-Iincludes/ -I../includes/ -Wall

#-Wextra    // a décommenter plus tard, flemme du warning "unused variables" la

RM					=	rm -rf

all:				$(NAME)

$(NAME):			$(OMAIN) $(OBJECTS)
					$(CC) -o $(NAME) $(OBJECTS) -ldl $(OMAIN) $(LIBS)

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

tests_run:			CFLAGS += -g
tests_run:			$(TOBJECTS) $(OBJECTS)
					$(CC) -o $(TNAME) $(TOBJECTS) $(OBJECTS) $(LIBS)\
 						-lgcov -lcriterion
					./$(TNAME)

re:					fclean all

.PHONY:				all $(NAME) clean fclean re