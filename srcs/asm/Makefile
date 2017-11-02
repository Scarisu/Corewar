# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/29 18:30:33 by pbernier          #+#    #+#              #
#    Updated: 2017/11/02 14:48:44 by pbernier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT			=	ASSEMBLEUR
NAME			=	asm
OBJDIR			=	../../objs/
ASMDIR			=	$(OBJDIR)asm/
SRCDIR			=	./
SRC				=	main.c
OBJ				=	$(addprefix $(ASMDIR),$(SRC:.c=.o))
LIB				=	../../lib/libft/libft.a
CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra -Ofast
DFLAGS			=	-fsanitize=address -g
INCLUDES		=	-I ../../includes/ -I ../../lib/libft/includes/

all: $(NAME)

$(NAME): $(ASMDIR) $(OBJ)
	@make -C ../../lib/libft
	@printf "[$(PROJECT)] Objs compilation done.                                               \n"
	@$(CC) -o ../../$(NAME) $(OBJ) $(LIB) $(FLAGS)
	@printf "[$(PROJECT)] $(NAME) compiled.                                                    \n"


$(ASMDIR)%.o: $(SRCDIR)%.c
	@printf "[$(PROJECT)] Compiling $< to $@                                                   \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(ASMDIR): $(OBJDIR)
	@mkdir $(ASMDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@rm -f $(OBJ)
	@rm -rf $(ASMDIR)
	@make -C ../../lib/libft clean
	@printf "[$(PROJECT)] Obj removed.                                                           \n"

fclean: clean
	@rm -f $(LIB)
	@rm -rf ../../$(NAME)
	@printf "[$(PROJECT)] $(NAME) removed.                                                       \n"

re: fclean all

.PHONY: all clean fclean re
