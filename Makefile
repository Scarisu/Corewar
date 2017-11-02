# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/29 18:30:33 by pbernier          #+#    #+#              #
#    Updated: 2017/11/02 15:30:20 by pbernier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECTASM		= 	ASSEMBLEUR
PROJECTCHAMP	= 	CHAMPION
PROJECTMV		= 	MACHINE VIRTUEL

DIROBJ			=	objs/
DIRSRC			=	srcs/

DIRASM			= 	asm/
DIRCHAMP		=	champ/
DIRMV			=	mv/

NAMEASM			=	asm
NAMECHAMP		=	LaFalaise.s
NAMEMV			=	corewar

SRCASM			=	main.c
SRCCHAMP		=	main.c
SRCMV			=	main.c

LIB				=	libft.a
LIBPATH			=	lib/libft/

CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra -Ofast
DFLAGS			=	-fsanitize=address -g
INCLUDES		=	-I includes/ -I lib/libft/includes/

PATHSRCASM		=	$(addprefix $(DIRSRC),$(DIRASM))
PATHSRCCHAMP	=	$(addprefix $(DIRSRC),$(DIRCHAMP))
PATHSRCMV		=	$(addprefix $(DIRSRC),$(DIRMV))

OBJASM			=	$(addprefix $(DIROBJ)$($DIRASM),$(SRCASM:.c=.o))
OBJCHAMP		=	$(addprefix $(DIROBJ)$($DIRCHAMP),$(SRCCHAMP:.c=.o))
OBJMV			=	$(addprefix $(DIROBJ)$($DIRMV),$(SRCMV:.c=.o))

all: asm

asm: $(DIROBJ) $(DIROBJ)$(DIRASM) $(OBJASM)
	@make -C $(LIBPATH)
	@printf "[$(PROJECTASM)] Objs compilation done.                                            \n"
	@$(CC) -o $(NAMEASM) $(OBJASM) $(LIBPATH)$(LIB) $(FLAGS)
	@printf "[$(PROJECTASM)] $(NAMEASM) compiled.                                              \n"

$(OBJASM)%.o: $(PATHASM)%.c
	@printf "[$(PROJECTASM)] Compiling $< to $@                                                \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(DIROBJ)$(DIRASM):
	mkdir $(DIROBJ)$(DIRASM)

$(DIROBJ):
	mkdir $(DIROBJ)
