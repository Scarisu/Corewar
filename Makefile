# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/29 18:30:33 by pbernier          #+#    #+#              #
#    Updated: 2017/11/02 14:51:19 by pbernier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJDIR			=	objs/
DIRSRC			=	srcs/

NAMEASM			=	asm
NAMECHAMP		=	LaFalaise.s
NAMEMV			=	corewar

DIRASM			=	$(DIRSRC)asm/
DIRCHAMP		=	$(DIRSRC)champ/
DIRMV			=	$(DIRSRC)mv/

all: asm champ mv

re: fclean all

clean: clean_asm clean_champ clean_mv
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAMEASM)
	@rm -f $(NAMECHAMP)
	@rm -f $(NAMEMV)

asm:
	@make -C $(DIRASM)

re_asm:
	@make -C $(DIRASM) re

clean_asm:
	@make -C $(DIRASM) clean

fclean_asm:
	@make -C $(DIRASM) fclean

champ:
	@make -C $(DIRCHAMP)

re_champ:
	@make -C $(DIRCHAMP) re

clean_champ:
	@make -C $(DIRCHAMP) clean

fclean_champ:
	@make -C $(DIRCHAMP) fclean

mv:
	@make -C $(DIRMV)

re_mv:
	@make -C $(DIRMV) re

clean_mv:
	@make -C $(DIRMV) clean

fclean_mv:
	@make -C $(DIRMV) fclean

.PHONY: all clean fclean re
