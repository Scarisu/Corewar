#Attention aux noms donnés aux dossiers !
asm_name="asm"
vm_name="corewar"
champ_name="aaaaaa.s"
resources_file="vm_champs"
file_test="tests/battle"
result_file="result.txt"
output_file="battle.txt"

list_long=("mandragore.s" "gedeon.s" "youforkmytralala.s" "Car.s" "_honeybadger.s")
list_inva=("42.s" "barriere.s" "Backward.s" "Death.s" "bee_gees.s" "lde.s"
"leeloo.s" "mat.s" "new.s" "sebc.s" "Survivor.s" "tdc2.s" "tdc3.s" "tdc4.s"
"Torpille.s" "Rainbow_dash.s" "ultimate-surrender.s" "Misaka_Mikoto.s"
"champ.s" "Explosive_Kitty.s" "Kittystrophic.s" "ultima.s"
"mise_a_jour_windows95.s" "run_Kitty_RUN.s")

resources_adress="https://projects.intra.42.fr/uploads/document/document/391/vm_champs.tar"

champs_exem=()
champs_ship=()
champs_long=()

flag_exem="ON"
flag_ship="ON"
flag_long="ON"

dir_champ="champions"
dir_exem="exemples"
dir_ship="championships"
dir_long="longs"

grey="\033[38;5;8m"
reset="\033[0m"

clean(){
	rm -rf ${file_test}
	printf "\"${grey}${file_test}${reset}\" has been removed\n"
	exit
}

usage(){
	printf "usage: $0 [-eslc] [clean] [champion]\n"
	exit

}

#Gestion des flags
#-e only exemple champs
#-s only championships champs
#-l only long champs
if [ $1 ]; then
	[[ ${3} ]] && usage
	([[ ${1} == clean ]] && [[ ! ${2} ]]) && clean
	[[ ! ${1} =~ ^-[eslc]+$ ]] && usage
	if [[ ${1} =~ ^-[esl]*[c]+[esl]* ]]; then
		[[ ${2} ]] && champ_name="$(echo "${2}" | sed 's/\\n//')" || usage
	elif [[ ${2} ]]; then
		usage
	fi
	if ([[ ${1} =~ ^-[eslc]+$ ]] && [[ ! ${1} =~ ^-[c]+$ ]]); then
		[[ ${1} =~ [e] ]] && flag_exem="ON" || flag_exem="OFF"
		[[ ${1} =~ [s] ]] && flag_ship="ON" || flag_ship="OFF"
		[[ ${1} =~ [l] ]] && flag_long="ON" || flag_long="OFF"
	fi
fi

clear


#Ressource
printf " ${grey}[DOWLOADING RESOURCES]  ${reset}\r"
mkdir -p ${resources_file}
curl -s ${resources_adress} | tar x - -C ${resources_file}
rm -f $(find ./${resources_file} -name "*.cor")
resources_vm=$(find ./${resources_file} -name "${vm_name}")
chmod 744 ${resources_vm}

#Check champ list
printf " ${grey}[CHEAKING CHAMPION LIST]${reset}\r"
if [ ${flag_long} == "ON" ]; then
	for champ in ${list_long[@]}; do
		find=$(find ./${resources_file} -name "${champ}")
		if [[ ${find} == "" ]]; then
			list_long=${list_long[@]/${champ}}
			printf "Champion \"${grey}${champ}${reset}\", doesn't exist. Removed from \"${grey}list_long${reset}\"\n"
		fi
	done
fi
for champ in ${list_inva[@]}; do
	find=$(find ./${resources_file} -name "${champ}")
	if [[ ${find} == "" ]]; then
		list_inva=${list_inva[@]/${champ}}
		printf "Champion \"${grey}${champ}${reset}\", doesn't exist. Removed from \"${grey}list_inva${reset}\"\n"
	fi
done

#Test directory
printf " ${grey}[CREATING DIRECTORY]    ${reset}\r"
all_dir=""
for dir in $(echo ${file_test} | tr "/" "\n"); do
	all_dir="${all_dir}${dir}/"
	mkdir -p ${all_dir}
done
rm -rf ${file_test}/${dir_champ}
[ ${flag_exem} == "ON" ] && mkdir -p ${file_test}/${dir_champ}/${dir_exem}
[ ${flag_ship} == "ON" ] && mkdir -p ${file_test}/${dir_champ}/${dir_ship}
[ ${flag_long} == "ON" ] && mkdir -p ${file_test}/${dir_champ}/${dir_long}
rm -f ${file_test}/${output_file}

#Setup data
printf " ${grey}[SORTING CHAMPIONS]     ${reset}\r"
champs_all=$(find ./${resources_file} -name "*.s")
for champ in ${champs_all[@]}; do
	sort="NO"
	for inva in ${list_inva[@]}; do
		[ $(basename ${champ}) == ${inva} ] && sort="YES"
	done
	if ([ ${sort} == "NO" ]); then
		for long in ${list_long[@]}; do
			if ([ $(basename ${champ}) == ${long} ] && [ ${sort} == "NO" ]); then
				[ ${flag_long} == "ON" ] && champs_long[${#champs_long[@]}]=${champ}
				sort="YES"
			fi
		done
	fi
	if ([ ${sort} == "NO" ]); then
		for dir in $(echo ${champ} | tr "/" "\n"); do
			if ([ ${dir} == "championships" ] && [ ${sort} == "NO" ]); then
				[ ${flag_ship} == "ON" ] && champs_ship[${#champs_ship[@]}]=${champ}
				sort="YES"
			fi
		done
	fi
	if ([ ${sort} == "NO" ]); then
		[ ${flag_exem} == "ON" ] && champs_exem[${#champs_exem[@]}]=${champ}
		sort="YES"
	fi
done

#Make asm
make ${asm_name} > /dev/null
if [ ! -e ${asm_name} ]; then
	printf "\"${grey}${asm_name}${reset}\" hasen't been found\n"
	exit
fi

#Compiling principal Champion
./${asm_name} -s ${champ_name} > /dev/null 2> /dev/null
cor="$(echo "${champ_name}" | sed 's/\.s//').cor"
if [[ ! -e ${cor} ]]; then
	printf " Champion \"${grey}$(basename ${cor})${reset}\" does not compile\n"
	exit
fi

#Compiling Champions
max_len=0
[[ "${#dir_exem}" -gt "${max_len}" ]] && max_len=${#dir_exem}
[[ "${#dir_ship}" -gt "${max_len}" ]] && max_len=${#dir_ship}
[[ "${#dir_long}" -gt "${max_len}" ]] && max_len=${#dir_long}
nb_done_type=0
nb_done_total=0
nb_champs=$(echo $((${#champs_exem[@]}+${#champs_ship[@]}+${#champs_long[@]})))
compile_len=$(echo $((${max_len}+41)))

compile_champ(){
	((nb_done_total++))
	([[ "${last}" == "${3}" ]] || [ -e ${last} ]) && nb_done_type=$(echo $((${nb_done_type}+1))) || nb_done_type=1
	last=${3}
	printf " ${grey}[COMPILING CHAMPIONS] [${2}: "
	for i in $(seq 0 $(echo $((${max_len}-${#2})))); do printf " "; done
	[ "${nb_done_type}" -le "9" ] && printf "0"
	printf "${nb_done_type}/"
	[ "${3}" -le "9" ] && printf "0"
	printf "${3}] ["
	[ "${nb_done_total}" -le "9" ] && printf "0"
	printf "${nb_done_total}/"
	[ "${nb_champs}" -le "9" ] && printf "0"
	printf "${nb_champs}] ${reset}\r"
	./${asm_name} -s ${1} > /dev/null 2> /dev/null
	local cor="$(echo "${1}" | sed 's/\.s//').cor"
 	if [[ -e ${cor} ]]; then
		mv ${cor} ${file_test}/${dir_champ}/${2}
	else
		printf "\"${grey}$(basename ${cor})${reset}\" hasn't been created"
		local error_len="\"$(basename ${cor})\" hasn't been created"
		for i in $(seq 0 $(echo $((${compile_len}-${#error_len})))); do printf " "; done
		printf "\n"
	fi
}

for champ in ${champs_exem[@]}; do
	compile_champ ${champ} ${dir_exem} ${#champs_exem[@]}
done
for champ in ${champs_ship[@]}; do
	compile_champ ${champ} ${dir_ship} ${#champs_ship[@]}
done
for champ in ${champs_long[@]}; do
	compile_champ ${champ} ${dir_long} ${#champs_long[@]}
done

#Champions fighting
printf " ${grey}[CHAMPIONS FIGHTING]${reset}"
for i in $(seq 0 $(echo $((${compile_len}-21)))); do printf " "; done
printf "\n"
[ ${flag_exem} == "ON" ] && cor_exem=$(find ./${file_test}/${dir_champ}/${dir_exem} -name "*.cor")
[ ${flag_ship} == "ON" ] && cor_ship=$(find ./${file_test}/${dir_champ}/${dir_ship} -name "*.cor")
[ ${flag_long} == "ON" ] && cor_long=$(find ./${file_test}/${dir_champ}/${dir_long} -name "*.cor")

nb_done_total=0
nb_win_total=0
fight_len=0
nb_champs=$(echo $((${#champs_exem[@]}+${#champs_ship[@]}+${#champs_long[@]})))

hour="$(date +%H):$(date +%M):$(date +%S)"
regex="\"$(echo "${champ_name}" | sed 's/\.s//')\", has won !$"

print_column(){
	#Voir arrondir selon impair ou pair
	space=${1}
	pos=$(echo $(((16/2)-((${#2}+2)/2))))
	[[ "${pos}" -ge "$(echo $((${space}*(-1))))" ]] && space=$(echo $((${space}+${pos}))) || space=0
	for i in $(seq 1 ${space}); do printf " " >> ${file_test}/${result_file}; done
	printf "[${2}]" >> ${file_test}/${result_file}
}

if [ ! -e ${file_test}/${result_file} ]; then
	print_column "10" ${dir_exem}
	print_column $(echo $((${space}-6))) ${dir_ship}
	print_column $(echo $((${space}-4))) ${dir_long}
	print_column $(echo $((${space}-4))) "TOTAL"
	printf "\n" >> ${file_test}/${result_file}

fi
printf "${hour}: " >> ${file_test}/${result_file}

champ_name="$(echo "${champ_name}" | sed 's/\.s//').cor"
[ ${flag_exem} == "ON" ] && printf "[${dir_exem}]\n" >> ${file_test}/${output_file}
[ ${flag_ship} == "ON" ] && printf "[${dir_ship}]\n" >> ${file_test}/${output_file}
[ ${flag_long} == "ON" ] && printf "[${dir_long}]\n" >> ${file_test}/${output_file}
printf "\n" >> ${file_test}/${output_file}

fighting(){
	hour="$(date +%H):$(date +%M):$(date +%S)"
	no_path_champ=$(basename ${champ})
	((nb_done_total++))
	printf " [${hour}] (1) [${nb_done_total}/${nb_champs}] [ ${grey}${champ_name}${reset} VS ${no_path_champ}]"
	space=$(echo $((${fight_len}-29+${#no_path_champ}+${#champ_name})))
	[[ "${space}" -gt "0" ]] && for i in $(seq 0 ${space}); do printf " "; done
	printf "\r"

	printf " [${hour}] (1) [${nb_done_total}/${nb_champs}] [ ${champ_name} VS ${no_path_champ}]\n" >> ${file_test}/${output_file}
	local output=$(./${resources_vm} ${champ_name} ${champ})
	printf "${output}\n\n" >> ${file_test}/${output_file}
	if [[ ${output} =~ ${regex} ]]; then
		((nb_win_total++))
		((nb_win_type++))
	fi
	printf " [${hour}] (2) [${nb_done_total}/${nb_champs}] [ ${no_path_champ} VS ${grey}${champ_name}${reset}]\r"
	printf " [${hour}] (2) [${nb_done_total}/${nb_champs}] [ ${no_path_champ} VS ${champ_name}]\n" >> ${file_test}/${output_file}
	local output=$(./${resources_vm} ${champ_name} ${champ})
	printf "${output}\n\n" >> ${file_test}/${output_file}
	if [[ ${output} =~ ${regex} ]]; then
		((nb_win_total++))
		((nb_win_type++))
	fi
	fight_len=$(echo $((29+${#no_path_champ}+${#champ_name})))
}

print_result(){
	printf "[" >> ${file_test}/${result_file}
	[ "${2}" -le "9" ] && printf "0" >> ${file_test}/${result_file}
	printf "${2}/" >> ${file_test}/${result_file}
	[ "${1}" -le "9" ] && printf "0" >> ${file_test}/${result_file}
	printf "${1}] (" >> ${file_test}/${result_file}
	[[ "${1}" != "0" ]] && percent=$(echo $(((10000 / (${1})) * (${2})))) || percent=0
	nbr=$(echo $((${percent} / 100)))
	[ "${nbr}" -le "9" ] && printf "0" >> ${file_test}/${result_file}
	printf "${nbr}," >> ${file_test}/${result_file}
	dec=$(echo $((${percent} % 100)))
	[ "${dec}" -le "9" ] && printf "0" >> ${file_test}/${result_file}
	printf "${dec}%%)${3}" >> ${file_test}/${result_file}
}

if [ ${flag_exem} == "ON" ]; then
	nb_win_type=0
	for champ in ${cor_exem[@]}; do fighting ${champ}; done
	nb_cor=0
	for i in ${cor_exem[@]}; do nb_cor=$(echo $((${nb_cor}+2))); done
	nb_cor_total=$(echo $((${nb_cor_total}+${nb_cor})))
	print_result ${nb_cor} ${nb_win_type} "    "
else
	printf "[--/--] (--,--%%)    " >> ${file_test}/${result_file}
fi
if [ ${flag_ship} == "ON" ]; then
	nb_win_type=0
	for champ in ${cor_ship[@]}; do fighting ${champ}; done
	nb_cor=0
	for i in ${cor_ship[@]}; do nb_cor=$(echo $((${nb_cor}+2))); done
	nb_cor_total=$(echo $((${nb_cor_total}+${nb_cor})))
	print_result ${nb_cor} ${nb_win_type} "    "
else
	printf "[--/--] (--,--%%)    " >> ${file_test}/${result_file}
fi
if [ ${flag_long} == "ON" ]; then
	nb_win_type=0
	for champ in ${cor_long[@]}; do fighting ${champ}; done
	nb_cor=0
	for i in ${cor_long[@]}; do nb_cor=$(echo $((${nb_cor}+2))); done
	nb_cor_total=$(echo $((${nb_cor_total}+${nb_cor})))
	print_result ${nb_cor} ${nb_win_type} "    "
else
	printf "[--/--] (--,--%%)    " >> ${file_test}/${result_file}
fi
print_result ${nb_cor_total} ${nb_win_total} "   $(basename ${champ_name})\n"
rm ${champ_name}
