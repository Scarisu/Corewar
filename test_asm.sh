clear
make asm_clean
make asm

printf "\n\033[1;34m-----------------------------------------\033[0;m\n"
printf "\033[1;34m              Assembleur\033[0;m\n"
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
	#name x 2
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
	printf "\n[12] \033[4mError > 30 before\033[0m: \033[38;5;8m[12error_30_before.s]\033[0m\n"
	./asm ./tests/12error_30_before.s
	read
	printf "\n[13] \033[4mError > 30 char after (1)\033[0m: \033[38;5;8m[13error_30_after1.s]\033[0m\n"
	./asm ./tests/13error_30_after1.s
	read
	printf "\n[14] \033[4mError > 30 char after (2)\033[0m: \033[38;5;8m[14error_30_after2.s]\033[0m\n"
	./asm ./tests/14error_30_after2.s
	read
	printf "\n[15] \033[4mError > 61 char\033[0m: \033[38;5;8m[15error_61.s]\033[0m\n"
	./asm ./tests/15error_61.s
	read
	printf "\n[16] \033[4mDouble description\033[0m: \033[38;5;8m[16double_description.s]\033[0m\n"
	./asm ./tests/16double_description.s
	read
	printf "\n[17] \033[4mBad Syntax .comment (1)\033[0m: \033[38;5;8m[17bad_syntax_comment1.s]\033[0m\n"
	./asm ./tests/17bad_syntax_comment1.s
	read
	printf "\n[18] \033[4mBad Syntax .comment (2)\033[0m: \033[38;5;8m[18bad_syntax_comment2.s]\033[0m\n"
	./asm ./tests/18bad_syntax_comment2.s
	read
	printf "\n[19] \033[4mBad Syntax .comment (3)\033[0m: \033[38;5;8m[19bad_syntax_comment3.s]\033[0m\n"
	./asm ./tests/19bad_syntax_comment3.s
	read
	printf "\n[20] \033[4mBad Syntax .comment (4)\033[0m: \033[38;5;8m[20bad_syntax_comment4.s]\033[0m\n"
	./asm ./tests/20bad_syntax_comment4.s
	read
	printf "\n[21] \033[4mComment .comment (1)\033[0m: \033[38;5;8m[21comment_name1.s]\033[0m\n"
	./asm ./tests/21comment_name1.s
	read
	printf "\n[22] \033[4mComment .comment (2)\033[0m: \033[38;5;8m[22comment_name2.s]\033[0m\n"
	./asm ./tests/22comment_name2.s
	read
	printf "\n[23] \033[4mComment .comment (3)\033[0m: \033[38;5;8m[23comment_name3.s]\033[0m\n"
	./asm ./tests/23comment_name3.s
	read
