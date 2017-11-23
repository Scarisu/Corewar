MP				=	../../
GLOBAL			=	$(MP)includes/Makefile
include			$(GLOBAL)

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
					ana_opcode.c \
					ana_label.c \
					ana_argument.c \
					ana_type.c
SRC_VERBOS		=	verbos.c \
					ver_name.c \
					ver_comment.c \
					ver_diverse.c \
					ver_opcode.c \
					ver_label.c \
					ver_argument.c \
					ver_type.c
SRC_RACINE		=	op.c \
					main.c \
					usage.c \
					error.c \
					line.c \
					set.c \
					clear.c

FLAGS			=	$(WFLAGS)
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

$(NAME_ASM): $(LIB_PATH) $(PATH_OBJ) $(OBJ)
	@printf "[$(PROJECT_ASM)] Objs compilation done.                    \n"
	@$(CC) -o $(NAME_ASM) $(OBJ) $(LIB_PATH) $(FLAGS)
	@printf "[$(PROJECT_ASM)] "
ifeq ($(FLAGS),$(DFLAGS))
	@printf "(lldb mode) "
endif
	@printf "$(notdir $(NAME_ASM)) compiled.\n"

$(PATH_OBJ)%.o: %.c $(INC) Makefile
	@printf "[$(PROJECT_ASM)] Compiling $(notdir $<) to $(notdir $@)              \r"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(LIB_PATH):
	@make -C $(LIB_MAKE)

$(PATH_OBJ):
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(PATH_OBJ)
	@mkdir -p $(addprefix $(PATH_OBJ),$(DIR))

lldb:
	@make -C $(LIB_MAKE) lldb
ifeq ($(FLAGS),$(WFLAGS))
	@sed '/^FLAGS/ s/WFLAGS/DFLAGS/g' Makefile > Makefile.tmp
	@mv	Makefile.tmp Makefile
	@printf "[$(PROJECT_ASM)] Swap to lldb mode.\n"
else
	@printf "[$(PROJECT_ASM)] Already in lldb mode.\n"
endif

normal:
	@make -C $(LIB_MAKE) normal
ifeq ($(FLAGS),$(DFLAGS))
	@sed '/^FLAGS/ s/DFLAGS/WFLAGS/g' Makefile > Makefile.tmp
	@mv	Makefile.tmp Makefile
	@printf "[$(PROJECT_ASM)] Swap to normal mode.\n"
else
	@printf "[$(PROJECT_ASM)] Already in normal mode.\n"
endif


flag:
	@printf "[$(PROJECT_ASM)] "
ifeq ($(FLAGS),$(WFLAGS))
	@printf "Normal mode activated {$(FLAGS)}.\n"
else
	@printf "Lldb mode activated {$(FLAGS)}.\n"
endif

clean:
	@[ -e "$(DIR_OBJ)$(DIR_VM)" ] && rm -rf $(PATH_OBJ) || rm -rf $(DIR_OBJ)
	@printf "[$(PROJECT_ASM)] Obj removed.\n"

fclean: clean
	@rm -f $(NAME_ASM)
	@printf "[$(PROJECT_ASM)] $(notdir $(NAME_ASM)) removed.\n"

re: fclean $(NAME_ASM)

.PHONY: all $(notdir $(NAME_ASM)) lldb clean fclean re
