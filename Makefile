# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/29 18:30:33 by pbernier          #+#    #+#              #
#    Updated: 2017/11/01 20:18:30 by pbernier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECTASM		=	ASSEMBLEUR
PROJECTCHAMP	=	LA FALAISE
PROJECTMV		=	COREWAR

NAMEASM			=	asm
NAMECHAMP		=	lafalaise
NAMEMV			=	corewar

DIROBJ			=	objs/
DIRSRC			=	srcs/

DIRASM			=	asm/
DIRCHAMP		=	champ/
DIRMV			=	mv/

SRCASM			=	main.c
SRCCHAMP		=	main.c
SRCMV			=	main.c

OBJASM			=	$(addprefix $(DIROBJ)$(DIRASM),$(SRCASM:.c=.o))
OBJCHAMP		=	$(addprefix $(DIROBJ)$(DIRCHAMP),$(SRCCHAMP:.c=.o))
OBJMV			=	$(addprefix $(DIROBJ)$(DIRMV),$(SRCMV:.c=.o))

LIB				=	lib/libft/libft.a
CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra -Ofast
DFLAGS			=	-fsanitize=address -g
INCLUDES		=	-I includes/ -I lib/libft/includes/

all : $(NAMEASM)

$(NAMEASM): oui $(OBJASM)
	@make -C ./lib/libft
	@printf "[$(PROJECTASM)] Objs compilation done.                                            \n"
	@$(CC) -o $(NAMEASM) $(OBJASM) $(LIB) $(FLAGS)
	@printf "[$(PROJECTASM)] $(NAMEASM) compiled.                                              \n"

$(DIROBJ)$(OBJASM)%.o: $(DIRSRC)$(DIRASM)%.c
	@printf "[$(PROJECTASM)] Compiling $< to $@                                                   \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

oui:
	@mkdir $(DIROBJ)
	@mkdir $(DIROBJ)$(DIRASM)



clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)
	@make -C ./lib/libft clean
	@printf "[$(PROJECT)] Obj removed.                                                           \n"

fclean: clean
	@rm -f $(LIB)
	@rm -rf $(NAME)
	@printf "[$(PROJECT)] $(NAME) removed.                                                       \n"

re: fclean all

.PHONY: all clean fclean re
