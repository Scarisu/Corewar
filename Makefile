# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/29 18:30:33 by pbernier          #+#    #+#              #
#    Updated: 2017/11/14 00:06:54 by pbernier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECTASM		= 	ASSEMBLEUR
PROJECTCHAMP	= 	CHAMPION
PROJECTVM		= 	MACHINE VIRTUEL

DIROBJ			=	objs/
DIRSRC			=	srcs/

DIRASM			= 	asm/
DIRCHAMP		=	champ/
DIRVM			=	vm/

NAMEASM			=	asm
NAMECHAMP		=	LaFalaise.s
NAMEVM			=	corewar

SRCASM			=	op.c \
					main.c \
					usage.c \
					error.c \
					line.c \
					set.c \
					clear.c \
					analysis/ana_name.c \
					analysis/ana_comment.c \
					analysis/ana_diverse.c \
					analysis/ana_instruction.c \
					verbos/verbos.c \
					verbos/ver_name.c \
					verbos/ver_comment.c \
					verbos/ver_diverse.c \
					verbos/ver_instruction.c
SRCCHAMP		=	main.c
SRCVM			=	main.c

LIB				=	libft.a
LIBPATH			=	lib/libft/

CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra
DFLAGS			=	-fsanitize=address -g
INCLUDES		=	-I includes/ -I lib/libft/includes/

PATHOBJASM		=	$(addprefix $(DIROBJ),$(DIRASM))
PATHOBJCHAMP	=	$(addprefix $(DIROBJ),$(DIRCHAMP))
PATHOBJVM		=	$(addprefix $(DIROBJ),$(DIRVM))

PATHSRCASM		=	$(addprefix $(DIRSRC),$(DIRASM))
PATHSRCCHAMP	=	$(addprefix $(DIRSRC),$(DIRCHAMP))
PATHSRCVM		=	$(addprefix $(DIRSRC),$(DIRVM))

OBJASM			=	$(addprefix $(PATHOBJASM),$(SRCASM:.c=.o))
OBJCHAMP		=	$(addprefix $(PATHOBJCHAMP),$(SRCCHAMP:.c=.o))
OBJVM			=	$(addprefix $(PATHOBJVM),$(SRCVM:.c=.o))

all: $(LIBPATH)$(LIB) $(NAMEASM) $(NAMECHAMP) $(NAMEVM)

clean: asm_clean champ_clean vm_clean
	@rm -rf $(DIROBJ)
	@make -C $(LIBPATH) clean

fclean: asm_fclean champ_fclean vm_fclean
	@rm -rf $(DIROBJ)
	@make -C $(LIBPATH) fclean

re: fclean all

$(LIBPATH)$(LIB):
	@make -C $(LIBPATH)

$(NAMEASM): $(LIBPATH)$(LIB) $(DIROBJ) $(PATHOBJASM) $(OBJASM)
	@printf "[$(PROJECTASM)] Objs compilation done.                                            \n"
	@$(CC) -o $(NAMEASM) $(OBJASM) $(LIBPATH)$(LIB) $(FLAGS)
	@printf "[$(PROJECTASM)] $(NAMEASM) compiled.                                              \n"

$(PATHOBJASM)%.o: $(PATHSRCASM)%.c
	@printf "[$(PROJECTASM)] Compiling $< to $@                                                \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(PATHOBJASM):
	@mkdir $(PATHOBJASM)
	@mkdir $(PATHOBJASM)verbos
	@mkdir $(PATHOBJASM)analysis

asm_clean:
	@rm -f $(OBJASM)
	@rm -rf $(PATHOBJASM)
	@printf "[$(PROJECTASM)] Obj removed.														\n"

asm_fclean: asm_clean
	@rm -f $(NAMEASM)
	@printf "[$(PROJECTASM)] $(NAMEASM) removed.												 \n"

asm_re: asm_fclean asm

$(NAMECHAMP): $(LIBPATH)$(LIB) $(DIROBJ) $(PATHOBJCHAMP) $(OBJCHAMP)
	@printf "[$(PROJECTCHAMP)] Objs compilation done.                                            \n"
	@$(CC) -o $(NAMECHAMP) $(OBJCHAMP) $(LIBPATH)$(LIB) $(FLAGS)
	@printf "[$(PROJECTCHAMP)] $(NAMECHAMP) compiled.                                            \n"

$(PATHOBJCHAMP)%.o: $(PATHSRCCHAMP)%.c
	@printf "[$(PROJECTCHAMP)] Compiling $< to $@                                                \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(PATHOBJCHAMP):
	@mkdir $(PATHOBJCHAMP)

champ_clean:
	@rm -f $(OBJCHAMP)
	@rm -rf $(PATHOBJCHAMP)
	@printf "[$(PROJECTCHAMP)] Obj removed.														\n"

champ_fclean: champ_clean
	@rm -f $(NAMECHAMP)
	@printf "[$(PROJECTCHAMP)] $(NAMECHAMP) removed.											\n"

champ_re: champ_fclean champ

$(NAMEVM): $(LIBPATH)$(LIB) $(DIROBJ) $(PATHOBJVM) $(OBJVM)
	@printf "[$(PROJECTVM)] Objs compilation done.                                            	\n"
	@$(CC) -o $(NAMEVM) $(OBJVM) $(LIBPATH)$(LIB) $(FLAGS)
	@printf "[$(PROJECTVM)] $(NAMEASM) compiled.          	                                    \n"

$(PATHOBJVM)%.o: $(PATHSRCVM)%.c
	@printf "[$(PROJECTVM)] Compiling $< to $@              	                                  \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(PATHOBJVM):
	@mkdir $(PATHOBJVM)

vm_clean:
	@rm -f $(OBJVM)
	@rm -rf $(PATHOBJVM)
	@printf "[$(PROJECTVM)] Obj removed.													\n"

vm_fclean: vm_clean
	@rm -f $(NAMEVM)
	@printf "[$(PROJECTVM)] $(NAMEVM) removed.												\n"

vm_re: vm_fclean vm

$(DIROBJ):
	@mkdir $(DIROBJ)
