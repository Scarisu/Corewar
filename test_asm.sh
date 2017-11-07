make asm

printf "\n\033[1;34m-----------------------------------------\033[0;m\n"
printf "\033[1;34m			Assembleur\033[0;m\n"
printf "\033[1;34m-----------------------------------------\033[0;m\n"

	printf "\n[1] \033[4mMultiple .name\033[0m: \033[38;5;8m[01multiple_name.s]\033[0m\n"
	./asm ./tests/01multiple_name.s
	read
	printf "\n[2] \033[4mBad Syntax .name (1)\033[0m: \033[38;5;8m[02bad_syntax_name1.s]\033[0m\n"
	./asm ./tests/02bad_syntax_name1.s
	read
	printf "\n[3] \033[4mBad Syntax .name (2)\033[0m: \033[38;5;8m[03bad_syntax_name2.s]\033[0m\n"
	./asm ./tests/03bad_syntax_name2.s
	read
	printf "\n[4] \033[4mBad Syntax .name (3)\033[0m: \033[38;5;8m[04bad_syntax_name3.s]\033[0m\n"
	./asm ./tests/04bad_syntax_name3.s
	read
	printf "\n[5] \033[4mBad Syntax .name (4)\033[0m: \033[38;5;8m[05bad_syntax_name4.s]\033[0m\n"
	./asm ./tests/05bad_syntax_name4.s
	read
	printf "\n[6] \033[4mEmpty .name\033[0m: \033[38;5;8m[06empty_name.s]\033[0m\n"
	./asm ./tests/06empty_name.s
	read
	printf "\n[7] \033[4mForbidden char .name\033[0m: \033[38;5;8m[07forbidden_char_name.s]\033[0m\n"
	./asm ./tests/07forbidden_char_name.s
	read
	printf "\n[8] \033[4mDiff file .name\033[0m: \033[38;5;8m[08diff_file_name.s]\033[0m\n"
	./asm ./tests/08diff_file_name.s
	read
	printf "\n[9] \033[4mComment .name (1)\033[0m: \033[38;5;8m[09comment_name1.s]\033[0m\n"
	./asm ./tests/09comment_name1.s
	read
	printf "\n[10] \033[4mComment .name (2)\033[0m: \033[38;5;8m[10comment_name2.s]\033[0m\n"
	./asm ./tests/10comment_name2.s
	read
	printf "\n[11] \033[4mComment .name (3)\033[0m: \033[38;5;8m[11comment_name3.s]\033[0m\n"
	./asm ./tests/11comment_name3.s
	read
