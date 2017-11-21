
test_file=tests
asm_name=asm

all_tests=$(ls ${test_file})
nb_tests="$(echo "$(ls ${test_file} | wc -l)" | tr -d ' ')"
nb_done=0;

underline="\033[4m"
reset="\033[0m"
grey="\033[38;5;8m"

make asm

for name in $all_tests
do
	((nb_done++))
	printf "\n[${nb_done}/${nb_tests}] "
	printf "${underline}???"
	printf "${reset}: "
	printf "${grey}[${name}]${reset}\n"
	./${asm_name} ${test_file}/${name}
	read
done
