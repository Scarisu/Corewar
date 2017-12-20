
asm_name="asm"
file_test="tests/verbos/"
dir_list=("name" "comment" "instruction" "diverse" "argument")

#d = directory

all_tests=()
dir_invalid=()
champ_invalid=()
nb_done=0;

underline="\033[4m"
reset="\033[0m"
grey="\033[38;5;8m"

usage()
{
	printf "usage: $0 [-${flag_list}] [dir ...]\n"
	exit
}

#Gestion des flags
flag_list="dcs";
if [ $1 ]; then
	if [[ $1 =~ ^-[${flag_list}]+$ ]]; then
		if [[ $1 =~ [d] ]]; then
			dir_list=( "$@" )
			unset dir_list[0]
			if [[ -z "${dir_list[@]}" ]]; then
				printf "usage: $0 -d [$(ls -m ${file_test})]\n"
				exit
			fi
		elif [ $2 ]; then
			usage
		fi
		[[ $1 =~ [c] ]] && details="ON";
		[[ $1 =~ [s] ]] && warning="-s";
	else
		usage
	fi
fi

#Regroupement de tout les tests dans all_tests
for dir in ${dir_list[@]}; do
	valid="dont exist"
	for dir_exist in $(echo "$(ls ${file_test})"); do
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
nb_tests=${#all_tests[@]}

#error si un dossier dans dir_list n'existe pas
if [ -n "${dir_invalid}" ]; then
	for dir in ${dir_invalid[@]}; do
		printf "$0: ${dir}: No such directory\n"
	done
	exit
fi

make asm
read
[ -e ! ${asm} ] && exit


for name in ${all_tests[@]}; do
	((nb_done++))
	[[ ${details} == "ON" ]] && clear
	printf "\n[${nb_done}/${nb_tests}] "
	printf "${grey}[$(basename ${name})]${reset}\n"
	if [[ ${details} == "ON" ]]; then
		printf "\n"
		cat -ns ${name}
		printf "\n"
	fi
	./${asm_name} ${name} ${warning}
	rm -f $(find ./${file_test} -name "*.cor")
	read
done
