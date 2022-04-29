# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 17:26:27 by cjulienn          #+#    #+#              #
#    Updated: 2022/04/29 17:30:59 by cjulienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= readline_lab

SRCS= ./main.c
	  
OBJS = $(SRCS:.c=.o)

RDL_PATH = -L/usr/local/opt/readline/lib/
RDL_HISTORY_PATH = -L/usr/local/opt/readline/lib/

RDL = -lreadline.8.1 $(RDL_PATH)
RDL_HISTORY = -lhistory.8.1 $(RDL_HISTORY_PATH)

CC= gcc
CFLAGS= -Wall -Wextra -Werror -I.

RM= rm -f

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(RDL) $(RDL_HISTORY) -o $(NAME)
	cp /usr/local/opt/readline/lib/libreadline.8.1.dylib .
	cp /usr/local/opt/readline/lib/libhistory.8.1.dylib .
	@echo $(NAME) successfully made !!!

all: $(NAME)

clean:
	$(RM) $(OBJS)
	rm ./libreadline.8.1.dylib
	rm ./libhistory.8.1.dylib
	
fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
