MP				=	../../
include			$(MP)includes/Makefile

DIR_RACINE		=

SRC_INCLUD		=	corewar.h \
					op.h
SRC_RACINE		=	main.c

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

$(NAME_VM): $(LIB_PATH) $(DIR_OBJ) $(PATH_OBJ) $(OBJ) $(LIB_MAKE)
	@printf "[$(PROJECT_VM)] Objs compilation done.      \n"
	@$(CC) -o $(NAME_VM) $(OBJ) $(LIB_PATH) $(FLAGS)
	@printf "[$(PROJECT_VM)] $(notdir $(NAME_VM)) compiled.\n"

$(PATH_OBJ)%.o: %.c $(INC)
	@printf "[$(PROJECT_VM)] Compiling $(notdir $<) to $(notdir $@)              \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(LIB_PATH):
	@make -C $(LIB_MAKE)

$(DIR_OBJ):
	@mkdir $(DIR_OBJ)

$(PATH_OBJ):
	@mkdir $(PATH_OBJ)

clean:
	@rm -rf $(PATH_OBJ)
	@printf "[$(PROJECT_VM)] Obj removed.\n"

fclean: clean
	@rm -f $(NAME_VM)
	@printf "[$(PROJECT_VM)] $(notdir $(NAME_VM)) removed.\n"

re: fclean $(NAME_VM)

.PHONY: all $(notdir $(NAME_VM)) clean fclean re
