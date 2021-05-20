##
## EPITECH PROJECT, 2021
## qui lit ca meme ?
## File description:
## Makefile ...
##

all:
		make -C ./libs
		make -C ./client
		make -C ./server

clean:
		make -C ./libs clean
		make -C ./client clean
		make -C ./server clean

fclean:
		make -C ./libs fclean
		make -C ./client fclean
		make -C ./server fclean

tests_run:
		make -C ./libs tests_run
		make -C ./client tests_run
		make -C ./server tests_run

re:
		make -C ./libs re
		make -C ./client re
		make -C ./server re

.PHONY:	all clean fclean re