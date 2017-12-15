MP				=	../../
GLOBAL			=	$(MP)includes/Makefile
include			$(GLOBAL)

DIR_RACINE		=

SRC_INCLUD		=	corewar.h \
					op.h
SRC_RACINE		=	main.c \
					battle.c \
					get.c \
					error.c

FLAGS			=	$(WFLAGS)
INC				=	$(addprefix $(MP)$(DIR_INC),$(SRC_INCLUD))
PATH_OBJ		=	$(DIR_OBJ)$(DIR_VM)
DIR				=	$(DIR_RACINE)
SRC				=	$(addprefix $(DIR_RACINE),$(SRC_RACINE))
OBJ				=	$(addprefix $(PATH_OBJ),$(SRC:.c=.o))

all: $(NAME_VM)
ifeq ($(NO_TO_BE),OFF)
	@echo > /dev/null
endif

$(notdir $(NAME_VM)): all

$(NAME_VM): $(LIB_PATH) $(PATH_OBJ) $(OBJ)
	@printf "[$(PROJECT_VM)] Objs compilation done.      \n"
	@$(CC) -o $(NAME_VM) $(OBJ) $(LIB_PATH) $(FLAGS)
	@printf "[$(PROJECT_VM)] "
ifeq ($(FLAGS),$(DFLAGS))
	@printf "(lldb mode) "
endif
	@printf "$(notdir $(NAME_VM)) compiled.\n"

$(PATH_OBJ)%.o: %.c $(INC) Makefile
	@printf "[$(PROJECT_VM)] Compiling $(notdir $<) to $(notdir $@)              \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(LIB_PATH):
	@make -C $(LIB_MAKE)

$(PATH_OBJ):
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(PATH_OBJ)

lldb:
	@make -C $(LIB_MAKE) lldb
ifeq ($(FLAGS),$(WFLAGS))
	@sed '/^FLAGS/ s/WFLAGS/DFLAGS/g' Makefile > Makefile.tmp
	@mv	Makefile.tmp Makefile
	@printf "[$(PROJECT_VM)] Swap to lldb mode.\n"
	@make
else
	@printf "[$(PROJECT_VM)] Already in lldb mode.\n"
endif

normal:
	@make -C $(LIB_MAKE) normal
ifeq ($(FLAGS),$(DFLAGS))
	@sed '/^FLAGS/ s/DFLAGS/WFLAGS/g' Makefile > Makefile.tmp
	@mv	Makefile.tmp Makefile
	@printf "[$(PROJECT_VM)] Swap to normal mode.\n"
	@make
else
	@printf "[$(PROJECT_VM)] Already in normal mode.\n"
endif

flag:
	@printf "[$(PROJECT_VM)] "
ifeq ($(FLAGS),$(WFLAGS))
	@printf "Normal mode activated {$(FLAGS)}.\n"
else
	@printf "Lldb mode activated {$(FLAGS)}.\n"
endif

clean:
	@[ -e "$(DIR_OBJ)$(DIR_ASM)" ] && rm -rf $(PATH_OBJ) || rm -rf $(DIR_OBJ)
	@printf "[$(PROJECT_VM)] Obj removed.\n"

fclean: clean
	@rm -f $(NAME_VM)
	@printf "[$(PROJECT_VM)] $(notdir $(NAME_VM)) removed.\n"

re: fclean $(NAME_VM)

.PHONY: all $(notdir $(NAME_VM)) clean fclean re
