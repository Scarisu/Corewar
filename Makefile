MP				=
GLOBAL			=	$(MP)includes/Makefile
include			$(GLOBAL)

MAKE_ASM		=	$(DIR_SRC)$(DIR_ASM)
MAKE_VM			=	$(DIR_SRC)$(DIR_VM)

all: $(NAME_ASM) $(NAME_VM)
ifeq ($(NO_TO_BE),OFF)
	@echo > /dev/null
endif

libft:
	@make -C $(LIB_MAKE)

$(NAME_ASM):
	@make -C $(MAKE_ASM) $(NAME_ASM)

$(NAME_VM):
	@make -C $(MAKE_VM) $(NAME_VM)

lldb_libft:
	@make -C $(LIB_MAKE) lldb

lldb_$(NAME_ASM):
	@make -C $(MAKE_ASM) lldb

lldb_$(NAME_VM):
	@make -C $(MAKE_VM) lldb

lldb: lldb_$(NAME_ASM) lldb_$(NAME_VM)

normal_libft:
	@make -C $(LIB_MAKE) normal

normal_$(NAME_ASM):
	@make -C $(MAKE_ASM) normal

normal_$(NAME_VM):
	@make -C $(MAKE_VM) normal

normal: normal_$(NAME_ASM) normal_$(NAME_VM)

flag:
	@make -C $(MAKE_ASM) flag
	@make -C $(MAKE_VM) flag
	@make -C $(LIB_MAKE) flag

clean_libft:
	@make -C $(LIB_MAKE) clean

clean_$(NAME_ASM):
	@make -C $(MAKE_ASM) clean

clean_$(NAME_VM):
	@make -C $(MAKE_VM) clean

clean: clean_lib clean_$(NAME_ASM) clean_$(NAME_VM)

fclean_libft:
	@make -C $(LIB_MAKE) fclean

fclean_$(NAME_ASM):
	@make -C $(MAKE_ASM) fclean

fclean_$(NAME_VM):
	@make -C $(MAKE_VM) fclean

fclean: fclean_libft fclean_$(NAME_ASM) fclean_$(NAME_VM)

re_libft:
	@make -C $(LIB_MAKE) re

re_$(NAME_ASM):
	@make -C $(MAKE_ASM) re

re_$(NAME_VM):
	@make -C $(MAKE_VM) re

re: re_libft re_$(NAME_ASM) re_$(NAME_VM)

.PHONY: all  $(NAME_ASM) $(NAME_VM) libft \
		lldb_libft lldb_$(NAME_ASM) lldb_$(NAME_VM) lldb \
		normal_libft normal_$(NAME_ASM) normal_$(NAME_VM) normal \
		flag \
		clean_$(NAME_ASM) clean_$(NAME_VM) clean_libft clean \
		fclean_$(NAME_ASM) fclean_$(NAME_VM) fclean_libft fclean \
		re_$(NAME_ASM) re_$(NAME_VM) re_libft re \
		clean_lib fclean_lib re_lib
