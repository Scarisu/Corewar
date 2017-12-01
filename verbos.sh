
asm_name="asm"
file_test="tests/verbos/"
dir_list=("comment" "diverse" "instruction" "name" "champs")

#d = directory
flag_list="d"
all_tests=()
dir_invalid=()
nb_done=0;

underline="\033[4m"
reset="\033[0m"
grey="\033[38;5;8m"

if [[ $1 =~ ^-[${flag_list}]+$ ]]; then
	if [[ $1 =~ [d] ]]; then
		dir_list=( "$@" )
		unset dir_list[0]
		if [[ -z "${dir_list[@]}" ]]; then
			printf "usage: $0 -d [$(ls -m tests/verbos/)]\n"
			exit
		fi
	fi
	else if [ $1 ]; then
		printf "usage: $0 [-${flag_list}] [file ...]\n"
		exit
	fi
fi

for dir in ${dir_list[@]}; do
	valid="dont exist"
	for dir_exist in $(echo "$(ls tests/verbos/)"); do
		if [ ${dir} == ${dir_exist} ]; then
			valid="exist"
		fi
	done
	if [[ ${valid} = "dont exist" ]]; then
		dir_invalid[${#dir_invalid[@]}]=${dir}
	else
		dir_tests=$(ls -R ${file_test}${dir}/*.s)
		for test in ${dir_tests[@]}; do
			all_tests[${#all_tests[@]}]=${test}
		done
	fi
done

if [ -n "${dir_invalid}" ]; then
	for dir in ${dir_invalid[@]}; do
		printf "$0: ${dir}: No such directory\n"
	done
	exit
fi

nb_tests=${#all_tests[@]}

make asm
read

if [ -e ! ${asm} ]; then
	exit
fi

for name in ${all_tests[@]}; do
	((nb_done++))
	printf "\n[${nb_done}/${nb_tests}] "
	printf "${underline}???"
	printf "${reset}: "
	printf "${grey}[$(basename ${name})]${reset}\n"
	./${asm_name} ${name}
	# printf "${asm_name} ${name}"
	read
done
