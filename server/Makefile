##
## EPITECH PROJECT, 2021
## qui lit ca meme ?
## File description:
## Makefile ...
##

NAME				=	../myteams_server
TNAME				=	unit_test

SRC					=	server.c					\
						handles.c					\
						commands/help.c				\
						commands/use.c				\
						commands/create.c			\
						commands/login.c			\
						commands/list.c				\
						commands/info.c				\
						commands/send.c				\
						commands/utils_command.c	\
						file_parser/file_parser.c	\
						file_parser/write_file.c	\
						file_parser/read_file.c		\
						file_parser/file_tools.c	\
						str_to_word_array.c			\
						split_by_quote.c

TRC					=	test_basic.c
MAIN				= 	main.c

OBJ					=	$(SRC:.c=.o)
TOBJ				=	$(TRC:.c=.o)
OMAIN				=	$(MAIN:.c=.o)

# LIBS				=	../libnode.a 		\
# 						../libsockets.a		\
# 						../libmessage.a


OBJECTS				=	$(addprefix ./src/, $(OBJ))
TOBJECTS			=	$(addprefix ./tests/, $(TOBJ))
# ABS_LIBS			=	$(addprefix -l../lilbs/, $(LIBS))

CFLAGS				+=	-W -Wall -Wextra -Werror -g

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

tests_run:			CFLAGS += -g --coverage
tests_run:			$(TOBJECTS) $(OBJECTS)
					$(CC) -o $(TNAME) $(TOBJECTS) $(OBJECTS) $(LIBS)\
						-lgcov -lcriterion -luuid

re:					fclean all

.PHONY:				all $(NAME) clean fclean re