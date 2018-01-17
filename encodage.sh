#Attention aux noms donnés aux dossiers !
asm_name="asm"
resources_file="vm_champs"
file_test="tests/champions/"
result_file="result.txt"
diff_file="diff.txt"

resources_adress="https://projects.intra.42.fr/uploads/document/document/391/vm_champs.tar"

underline="\033[4m"
reset="\033[0m"
grey="\033[38;5;8m"

clean(){
	rm -rf ${file_test}
	printf "All .cor from \"${grey}${file_test}${reset}\" removed\n"
	exit
}

usage(){
	printf "usage: $0 [-cs] [clean]\n"
	exit
}

#Gestion des flags
if [ $1 ]; then
	[[ $2 ]] && usage
	[[ $1 == clean ]] && clean
	if [[ $1 =~ ^-[cs]+$ ]]; then
		[[ $1 =~ [c] ]] && details="ON";
		[[ $1 =~ [s] ]] && warning="-s";
	else
		usage
	fi
fi

clear
make asm
if [ ! -e ${asm_name} ]; then
	printf "\"${grey}${asm_name}${reset}\" hasen't been found\n"
	exit
fi

#Ressource
curl -s ${resources_adress} | tar x - -C ${resources_file}
rm -f $(find ./${resources_file} -name "*.cor")
resources_asm=$(find ./${resources_file} -name "${asm_name}")
chmod 744 ${resources_asm}

all_dir=""
for dir in $(echo ${file_test} | tr "/" "\n"); do
	all_dir="${all_dir}${dir}/"
	mkdir -p ${all_dir}
done
rm -f $(find ./${file_test} -name "*.cor")
rm -f ${file_test}${result_file}
rm -f ${file_test}${diff_file}
mkdir -p ${file_test}cor_mine
mkdir -p ${file_test}cor_real

#Setup data
line_champs=$(find ./${resources_file} -name "*.s")
all_champs=()
for champ in ${line_champs[@]}; do
	all_champs[${#all_champs[@]}]=${champ}
done
nb_champs=${#all_champs[@]}
nb_done=0

#Print date on .txt
day="$(date +%d)/$(date +%m)/$(date +%Y)\n"
hour="$(date +%H):$(date +%M)\n"
printf "${day}${hour}\n" >> ${file_test}${result_file}
printf "${day}${hour}\n" >> ${file_test}${diff_file}

for champ in ${all_champs[@]}; do
	((nb_done++))
	cor="$(echo "${champ}" | sed 's/\.s//').cor"
	[[ ${details} == "ON" ]] && clear
	printf "\n[${nb_done}/${nb_champs}] "
	printf "[${nb_done}/${nb_champs}] [${cor}]\n" >> ${file_test}${result_file}
	printf "${grey}[$(basename ${cor})]${reset}\n"
	if [[ ${details} == "ON" ]]; then
		printf "\n"
		cat -ns ${name}
		printf "\n"
	fi
	read
	printf "\n[REAL]\n"
	${resources_asm} ${champ}
	[[ -e ${cor} ]] && mv ${cor} ${file_test}cor_real || printf "[REAL] - $(basename ${cor}) hasn't been created\n" >> ${file_test}${result_file}
	printf "\n[MINE]\n"
	./${asm_name} ${warning} ${champ}
	[[ -e ${cor} ]] && mv ${cor} ${file_test}cor_mine || printf "[MINE] - $(basename ${cor}) hasn't been created\n" >> ${file_test}${result_file}
	if [ -e "${file_test}cor_mine/$(basename ${cor})" ] && [ -e "${file_test}cor_real/$(basename ${cor})" ]; then
		printf "[${nb_done}/${nb_champs}] [${cor}]\n" >> ${file_test}${diff_file}
		dir=$(diff ${file_test}cor_real/$(basename ${cor}) ${file_test}cor_mine/$(basename ${cor}))
		[[ -z ${dir} ]] && diff="[DIFF] - SAME" || diff="[DIFF] - DIFFERENT"
		printf "${diff}\n" >> ${file_test}${result_file}
		printf "${diff}\n" >> ${file_test}${diff_file}
		bash -c "diff -y <(xxd ${file_test}cor_real/$(basename ${cor})) <(xxd ${file_test}cor_mine/$(basename ${cor}))" >> ${file_test}${diff_file}
	fi
	printf "\n" >> ${file_test}${result_file}
	printf "\n" >> ${file_test}${diff_file}
done
