# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 14:01:22 by kdavis            #+#    #+#              #
#    Updated: 2017/01/23 16:31:28 by kdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=push_swap

BINARY1		=checker

MAKE		=make

PUSH_SWAP	=

CHECKER		=

FILENAMES	=

SRCDIR		= src/
IDIR		= includes/

SRC			=$(addprefix $(SRCDIR), $(FILENAMES))
PSRC		=$(SRC) $(addprefix $(SRCDIR)$(NAME)/, $(PUSH_SWAP))
CSRC		=$(SRC) $(addprefix $(SRCDIR)$(BINARY1)/, $(CHECKER))
LIB			=libft

IFLAGS		=-I $(IDIR) -I $(LIB)/$(IDIR)
CFLAGS		=-Wall -Werror -Wextra
LFLAGS		=-L $(LIB) -lft

CC			=gcc

.PHONY:	all clean fclean re

all: $(NAME) $(BINARY1)

$(NAME): $(LIB).a $(PSRC)
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(PSRC) -o $@

$(BINARY1): $(LIB).a $(CSRC)
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(CSRC) -o $@

$(LIB).a:
	$(MAKE) -C $(LIB)

clean:
	$(MAKE) -C $(LIB) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BINARY1)
	$(MAKE) -C $(LIB) fclean

re: fclean all
