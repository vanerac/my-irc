##
## EPITECH PROJECT, 2021
## qui lit ca meme ?
## File description:
## Makefile ...
##

NAME				=	../../libsockets.a
TNAME				=	unit_test

SRC					=	socket_client.c	\
						socket_server.c	\
						sockets.c		\
						binary_encoder.c\
						io_functions.c

TRC					=

OBJ					=	$(SRC:.c=.o)
TOBJ				=	$(TRC:.c=.o)

OBJECTS				=	$(addprefix ./src/, $(OBJ))
TOBJECTS			=	$(addprefix ./tests/, $(TOBJ))
CFLAGS				+=	-Iincludes/ #-Wall -Wextra -Werror

RM					=	rm -rf

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
					$(CC) -o $(TNAME) $(TOBJECTS) $(OBJECTS) \
						-lcriterion -lgcov --coverage
					./$(TNAME)

re:					fclean all

.PHONY:				all $(NAME) clean fclean re