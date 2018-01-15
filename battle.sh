#Attention aux noms donnés aux dossiers !
asm_name="asm"
vm_name="corewar"
resources_file="vm_champs"
file_test="tests/battle"
result_file="result.txt"

list_long=("mandragore.s" "gedeon.s" "youforkmytralala.s" "Car.s" "_honeybadger.s")
list_inva=("42.s" "barriere.s" "Backward.s" "Death.s" "bee_gees.s" "lde.s"
"leeloo.s" "mat.s" "new.s" "sebc.s" "Survivor.s" "tdc2.s" "tdc3.s" "tdc4.s"
"Torpille.s" "Rainbow_dash.s" "ultimate-surrender.s" "Misaka_Mikoto.s"
"champ.s" "Explosive_Kitty.s" "Kittystrophic.s" "ultima.s"
"mise_a_jour_windows95.s") #"run_Kitty_RUN.s")

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
	printf "All .cor from \"${grey}${file_test}${reset}\" removed\n"
	exit
}

usage(){
	printf "usage: $0 [-esl] [clean]\n"
	exit
}

#Gestion des flags
#-e only exemple champs
#-s only championships champs
#-l only long champs
if [ $1 ]; then
	[[ $2 ]] && usage
	[[ $1 == clean ]] && clean
	if [[ $1 =~ ^-[esl]+$ ]]; then
		[[ $1 =~ [e] ]] && flag_exem="ON" || flag_exem="OFF"
		[[ $1 =~ [s] ]] && flag_ship="ON" || flag_ship="OFF"
		[[ $1 =~ [l] ]] && flag_long="ON" || flag_long="OFF"
	else
		usage
	fi
fi

clear

#Ressource
printf " ${grey}[DOWLOADING RESOURCES]  ${reset}\r"
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

#Compiling Champions
max_len=0
[[ "${#dir_exem}" -gt "${max_len}" ]] && max_len=${#dir_exem}
[[ "${#dir_ship}" -gt "${max_len}" ]] && max_len=${#dir_ship}
[[ "${#dir_long}" -gt "${max_len}" ]] && max_len=${#dir_long}
nb_done_type=0
nb_done_total=0
nb_champs=$(echo $((${#champs_exem[@]}+${#champs_ship[@]}+${#champs_long[@]})))
compile_len=$(echo $((${max_len}+40)))

compile_champ(){
	((nb_done_total++))
	local space=$(echo $((${max_len}-${#2})))
	([[ "${last}" == "${3}" ]] || [ -e ${last} ]) && nb_done_type=$(echo $((${nb_done_type}+1))) || nb_done_type=1
	last=$3
	printf " ${grey}[COMPILING CHAMPIONS] [${2}: "
	for i in $(seq 0 $space); do
		printf " ";
	done
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
		# printf "\"${grey}$(basename ${cor})${reset}\" hasn't been created\n"
		# local error_len="\"$(basename ${cor})\" hasn't been created\n"
		# local error_len=${#error_len}
		# local space=$(echo $((${compile_len}-${error_len})))
		# printf "${space}\n\n"
		# if [[ "${space}" -gt "0" ]]; then
		# 	for i in $(seq 0 $space); do
		# 		printf " ";
		# 	done
		# fi
	fi
}

if [[ ${flag_exem} == "ON" ]]; then
	for champ in ${champs_exem[@]}; do
		compile_champ ${champ} ${dir_exem} ${#champs_exem[@]}
	done
fi
if [[ ${flag_ship} == "ON" ]]; then
	for champ in ${champs_ship[@]}; do
		compile_champ ${champ} ${dir_ship} ${#champs_ship[@]}
	done
fi
if [[ ${flag_long} == "ON" ]]; then
	for champ in ${champs_long[@]}; do
		compile_champ ${champ} ${dir_long} ${#champs_long[@]}
	done
fi
read
exit










#Setup data
line_champs=$(find ./tests/champions/cor_mine -name "*.cor")
all_champs=()
for champ in ${line_champs[@]}; do
	if ([ ${flag} == "OFF" ] || ([ ${flag} == "ON" ] &&
		[[ $(basename ${champ}) != "mandragore.cor" ]] &&
		[[ $(basename ${champ}) != "gedeon.cor" ]] &&
		[[ $(basename ${champ}) != "youforkmytralala.cor" ]] &&
		[[ $(basename ${champ}) != "Car.cor" ]] &&
		[[ $(basename ${champ}) != "_honeybadger.cor" ]]) &&
		[[ $(basename ${champ}) != "42.cor" ]] &&
		[[ $(basename ${champ}) != "barriere.cor" ]]); then
		all_champs[${#all_champs[@]}]=${champ}
	fi

done
nb_champs=${#all_champs[@]}
nb_done=0

make asm > /dev/null
./asm -s aaaaaa.s > /dev/null
rm $1

for champ in ${all_champs[@]}; do
	((nb_done++))
	printf "[EN COUR] -"
	printf "\n[${nb_done}/${nb_champs}] [${champ}]\n" >> $1
	printf " [${nb_done}/${nb_champs}] [ ${grey}aaaaaa.cor${reset} VS $(basename ${champ})]            \r"
    ./.resources/corewar aaaaaa.cor ${champ} >> $1
    printf "\n" >> $1
	printf " [${nb_done}/${nb_champs}] [ $(basename ${champ}) VS ${grey}aaaaaa.cor${reset}]            \r"
    ./.resources/corewar ${champ} aaaaaa.cor >> $1
    printf "\n" >> $1
done

nb_done=$(grep -c "Contestant" $1)
nb_win=$(grep -c '"aaaaaa", has won !' $1)
percentage=$(echo $(((10000 / (${nb_done})) * (${nb_win}))))
nbr=$(echo $((${percentage} / 100)),)
dec=$(echo $((${percentage} % 100)))

printf "\"aaaaaa\", has won [${nb_win}/${nb_done}] ${nbr}${dec}%%\n" >> $1
printf "\"aaaaaa\", has won [${nb_win}/${nb_done}] ${nbr}${dec}%%  \n"
