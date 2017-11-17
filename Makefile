# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/29 18:30:33 by pbernier          #+#    #+#              #
#    Updated: 2017/11/17 16:30:05 by pbernier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECTASM		= 	ASSEMBLEUR
PROJECTVM		= 	MACHINE VIRTUEL

DIROBJ			=	objs/
DIRSRC			=	srcs/

DIRASM			= 	asm/
 SDIRASMANA		=	analysis/
 SDIRASMVER		=	verbos/
DIRVM			=	vm/

NAMEASM			=	asm
NAMEVM			=	corewar

SRCASMRAC		=	op.c main.c usage.c error.c \
					line.c set.c clear.c
SRCASMANA		=	ana_name.c ana_comment.c ana_diverse.c \
					ana_instruction.c ana_argument.c ana_type.c
SRCASMVER		=	verbos.c ver_name.c ver_comment.c \
					ver_diverse.c ver_instruction.c \
					ver_argument.c ver_type.c

SRCVMRAC		=	main.c

LIB				=	libft.a
LIBPATH			=	lib/libft/

CC				=	gcc
FLAGS			=	-Wall -Werror -Wextra
DFLAGS			=	-fsanitize=address -g
INCLUDES		=	-I includes/ -I lib/libft/includes/

SRCASM			=	$(SRCASMRAC) \
					$(addprefix $(SDIRASMANA),$(SRCASMANA)) \
					$(addprefix $(SDIRASMVER),$(SRCASMVER))
SRCVM			=	$(SRCVMRAC)

PATHOBJASM		=	$(addprefix $(DIROBJ),$(DIRASM))
PATHOBJVM		=	$(addprefix $(DIROBJ),$(DIRVM))

PATHSRCASM		=	$(addprefix $(DIRSRC),$(DIRASM))
PATHSRCVM		=	$(addprefix $(DIRSRC),$(DIRVM))

OBJASM			=	$(addprefix $(PATHOBJASM),$(SRCASM:.c=.o))
OBJVM			=	$(addprefix $(PATHOBJVM),$(SRCVM:.c=.o))

all: $(LIBPATH)$(LIB) $(NAMEASM) $(NAMEVM)

clean:
	@rm -rf $(DIROBJ)
	@printf "[$(PROJECTASM)] Obj removed.\n"
	@printf "[$(PROJECTVM)] Obj removed.\n"
	@make -C $(LIBPATH) clean

fclean: clean
	@rm -f $(NAMEASM)
	@printf "[$(PROJECTASM)] $(NAMEASM) removed.\n"
	@rm -f $(NAMEVM)
	@printf "[$(PROJECTVM)] $(NAMEVM) removed.\n"
	@rm -rf $(LIBPATH)$(LIB)
	@printf "[??] $(NAMEVM) removed.\n"

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
	@mkdir $(PATHOBJASM)$(SDIRASMANA)
	@mkdir $(PATHOBJASM)$(SDIRASMVER)

asm_clean:
	@rm -f $(OBJASM)
	@rm -rf $(PATHOBJASM)
	@printf "[$(PROJECTASM)] Obj removed.														\n"

asm_fclean: asm_clean
	@rm -f $(NAMEASM)
	@printf "[$(PROJECTASM)] $(NAMEASM) removed.												 \n"

asm_re: asm_fclean asm

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
