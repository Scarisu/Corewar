MP				=	../../
include			$(MP)includes/Makefile

DIR_ANALYS		=	analysis/
DIR_VERBOS		=	verbos/
DIR_RACINE		=

SRC_INCLUD		=	corewar.h \
					op.h \
					asm.h \
					verbos.h
SRC_ANALYS		=	ana_name.c \
					ana_comment.c \
					ana_diverse.c \
					ana_instruction.c \
					ana_argument.c \
					ana_type.c
SRC_VERBOS		=	verbos.c \
					ver_name.c \
					ver_comment.c \
					ver_diverse.c \
					ver_instruction.c \
					ver_argument.c \
					ver_type.c
SRC_RACINE		=	op.c \
					main.c \
					usage.c \
					error.c \
					line.c \
					set.c \
					clear.c

INC				=	$(addprefix $(MP)$(DIR_INC),$(SRC_INCLUD))
PATH_OBJ		=	$(DIR_OBJ)$(DIR_ASM)
DIR				=	$(DIR_ANALYS) $(DIR_VERBOS) $(DIR_RACINE)
SRC				=	$(addprefix $(DIR_ANALYS),$(SRC_ANALYS)) \
					$(addprefix $(DIR_VERBOS),$(SRC_VERBOS)) \
					$(addprefix $(DIR_RACINE),$(SRC_RACINE))
OBJ				=	$(addprefix $(PATH_OBJ),$(SRC:.c=.o))

all: $(NAME_ASM)
ifeq ($(NO_TO_BE),OFF)
	@echo > /dev/null
endif

$(notdir $(NAME_ASM)): all

$(NAME_ASM): $(LIB_PATH) $(DIR_OBJ) $(PATH_OBJ) $(OBJ)
	@printf "[$(PROJECT_ASM)] Objs compilation done.      \n"
	@$(CC) -o $(NAME_ASM) $(OBJ) $(LIB_PATH) $(FLAGS)
	@printf "[$(PROJECT_ASM)] $(notdir $(NAME_ASM)) compiled.\n"

$(PATH_OBJ)%.o: %.c $(INC)
	@printf "[$(PROJECT_ASM)] Compiling $(notdir $<) to $(notdir $@)              \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(LIB_PATH):
	@make -C $(LIB_MAKE)

$(DIR_OBJ):
	@mkdir $(DIR_OBJ)

$(PATH_OBJ):
	@mkdir $(PATH_OBJ)
	@mkdir $(addprefix $(PATH_OBJ),$(DIR))

clean:
	@rm -rf $(PATH_OBJ)
	@printf "[$(PROJECT_ASM)] Obj removed.\n"

fclean: clean
	@rm -f $(NAME_ASM)
	@printf "[$(PROJECT_ASM)] $(notdir $(NAME_ASM)) removed.\n"

re: fclean $(NAME_ASM)

.PHONY: all $(notdir $(NAME_ASM)) clean fclean re
