MP				=
include			$(MP)includes/Makefile

MAKE_ASM		=	$(DIR_SRC)$(DIR_ASM)
MAKE_VM			=	$(DIR_SRC)$(DIR_VM)

all: $(LIB_PATH) $(NAME_ASM) $(NAME_VM)
ifeq ($(NO_TO_BE),OFF)
	@echo > /dev/null
endif

$(LIB_PATH):
	@make -C $(LIB_MAKE)

$(NAME_ASM):
	@make -C $(MAKE_ASM) $(NAME_ASM)

$(NAME_VM):
	@make -C $(MAKE_VM) $(NAME_VM)

clean_lib:
	@make -C $(LIB_MAKE) clean

clean_$(NAME_ASM):
	@make -C $(MAKE_ASM) clean

clean_$(NAME_VM):
	@make -C $(MAKE_VM) clean

clean: clean_lib clean_$(NAME_ASM) clean_$(NAME_VM)
	@rm -rf $(DIR_OBJ)

fclean_$(NAME_ASM):
	@make -C $(MAKE_ASM) fclean

fclean_$(NAME_VM):
	@make -C $(MAKE_VM) fclean

fclean_lib:
	@make -C $(LIB_MAKE) fclean

fclean: fclean_lib fclean_$(NAME_ASM) fclean_$(NAME_VM)

re_lib:
	@make -C $(LIB_MAKE) re

re_$(NAME_ASM):
	@make -C $(MAKE_ASM) re

re_$(NAME_VM):
	@make -C $(MAKE_VM) re

re: re_lib re_$(NAME_ASM) re_$(NAME_VM)

.PHONY: all $(LIB_PATH) $(NAME_ASM) $(NAME_VM) \
		clean_$(NAME_ASM) clean_$(NAME_VM) clean \
		fclean_$(NAME_ASM) fclean_$(NAME_VM) fclean \
		re_$(NAME_ASM) re_$(NAME_VM) re \
		clean_lib fclean_lib re_lib
