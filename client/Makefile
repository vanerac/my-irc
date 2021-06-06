##
## EPITECH PROJECT, 2021
## qui lit ca meme ?
## File description:
## Makefile ...
##

NAME				=	../myteams_cli
TNAME				=	unit_test

SRC					=	manager.c						\
						tools.c							\
						str_to_word_array.c				\
						function_pointer.c				\
						split_by_quote.c				\
						error.c							\
						commands/client_create.c		\
						commands/client_help.c			\
						commands/client_info.c			\
						commands/client_invalid.c		\
						commands/client_list.c			\
						commands/client_login.c			\
						commands/client_logout.c		\
						commands/client_messages.c		\
						commands/client_send.c			\
						commands/client_subscribe.c		\
						commands/client_subscribed.c	\
						commands/client_unsubscribe.c	\
						commands/client_user.c			\
						commands/client_users.c

TRC					=
MAIN				= 	main.c

OBJ					=	$(SRC:.c=.o)
TOBJ				=	$(TRC:.c=.o)
OMAIN				=	$(MAIN:.c=.o)

OBJECTS				=	$(addprefix ./src/, $(OBJ))
TOBJECTS			=	$(addprefix ./tests/, $(TOBJ))

CFLAGS				+=	-W -Wall -Wextra -g

CPPFLAGS			+=	-Iincludes/ -I../includes/ -I../libs/myteams/

LDFLAGS				+=	-L../libs/myteams/ -L../

LDLIBS				+=	-luuid -lmyteams -lnode -lsockets -lmessage

RM					=	rm -rf

all:				$(NAME)

$(NAME):			$(OMAIN) $(OBJECTS)
					$(CC) -o $(NAME) $(OBJECTS) $(OMAIN) $(LDLIBS) $(LDFLAGS)

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