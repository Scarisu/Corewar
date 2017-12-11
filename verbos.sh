
asm_name="asm"
file_test="tests/verbos/"
dir_list=("name" "comment" "instruction" "diverse" "argument")

#d = directory
flag_list="ds"
all_tests=()
dir_invalid=()
champ_invalid=()
nb_done=0;

underline="\033[4m"
reset="\033[0m"
grey="\033[38;5;8m"

if [[ $1 =~ ^-[${flag_list}]+$ ]]; then
	if [[ $1 =~ [d] ]] && [[ $1 =~ [s] ]]; then
		printf "$0: no compatible option -- d/s\n";
		exit
	fi
	# if [[ $1 =~ [s] ]]; then
	# 	unset dir_list
	# 	all_tests=( "$@" )
	# 	unset all_tests[0]
	# 	if [[ -z "${all_tests[@]}" ]]; then
	# 		printf "usage: $0 -s [file ...]\n"
	# 		exit
	# 	fi
	# 	for name in ${all_tests[@]}; do
	# 		if [ ! -d "${name}" ]; then
	# 			champ_invalid[${#champ_invalid[@]}]=${name}
	# 		fi
	# 	done
	# 	if [ -n "${champ_invalid}" ]; then
	# 		for champ in ${champ_invalid[@]}; do
	# 			printf "$0: ${champ}: No such file\n"
	# 		done
	# 		exit
	# 	fi
	# fi
	if [[ $1 =~ [d] ]]; then
		dir_list=( "$@" )
		unset dir_list[0]
		if [[ -z "${dir_list[@]}" ]]; then
			printf "usage: $0 -d [$(ls -m tests/verbos/)]\n"
			exit
		fi
	fi
	else if [ $1 ]; then
		printf "usage: $0 [-${flag_list}] [file ...] [dir ...]\n"
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

#description=$(grep -A1 $(basename name_forbidden_char.s) ${file_test}description.txt)

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
	rm -f $(find ./${file_test} -name "*.cor")
	read
done
