# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/23 14:01:22 by kdavis            #+#    #+#              #
#    Updated: 2017/02/20 21:31:05 by kdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=push_swap

BINARY1		=checker

MAKE		=make

PUSH_SWAP	= main.c execute_command.c calculate_rotations.c max_min.c
PUSH_SWAP	+= modified_insertion.c rotate_stacks.c

CHECKER		=main.c checker.c process_instructions.c print_stacks.c

FILENAMES	=initialize_commands.c swap_commands.c push_commands.c cleanup.c
FILENAMES	+=rotate_commands.c reverse_rotate_commands.c load_stack.c
FILENAMES	+=check_stack.c

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

all: $(LIB)/$(LIB).a $(BINARY1) $(NAME)

$(NAME): $(PSRC)
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(PSRC) -o $@

$(BINARY1): $(CSRC)
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) $(CSRC) -o $@

$(LIB)/$(LIB).a:
	$(MAKE) -C $(LIB)

clean:
	$(MAKE) -C $(LIB) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BINARY1)
	$(MAKE) -C $(LIB) fclean

re: fclean all
