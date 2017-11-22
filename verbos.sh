
asm_name="./asm"
file_test="tests/verbos/"

#d = directory
flag_list="d"
all_tests=$(ls -R ${file_test}*/*.s)
nb_tests="$(echo "$(ls ${file_test}*/*.s | wc -l)" | tr -d ' ')"
nb_done=0;

underline="\033[4m"
reset="\033[0m"
grey="\033[38;5;8m"

if [[ $1 =~ ^-[${flag_list}]+$ ]]; then
	if [[ $1 =~ [d] ]]; then
		unset ${*}
		for i in ${*}
		do
			printf "ok $i\n"
		done

	fi
else if [ $1 ]; then
	printf "usage: $0 [-${flag_list}] [file ...]\n"
	exit
fi fi



exit
make asm

for name in ${all_tests}
do
	((nb_done++))
	printf "\n[${nb_done}/${nb_tests}] "
	printf "${underline}???"
	printf "${reset}: "
	printf "${grey}[$(basename ${name})]${reset}\n"

	./${asm_name} ${name}
	read
done
