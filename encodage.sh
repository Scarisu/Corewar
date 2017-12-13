
asm_name="asm"
resources_file="resources/"
file_test="tests/champions/"
result_file="result.txt"

make asm

mkdir -p ${resources_file}
curl -s https://projects.intra.42.fr/uploads/document/document/391/corewar.tar | tar x - -C ${resources_file}

line_champs=$(find ./resources -name "*.s")
all_champs=()
for champ in ${line_champs[@]}; do
	all_champs[${#all_champs[@]}]=${champ}
done
nb_champs=${#all_champs[@]}
nb_done=0

underline="\033[4m"
reset="\033[0m"
grey="\033[38;5;8m"

rm -f $(find ./${resources} -name "*.cor")
rm -f $(find ./${file_test} -name "*.cor")
rm -f ${file_test}${result_file}

mkdir -p ${file_test}cor_mine
mkdir -p ${file_test}cor_real

printf "$(date +%d)/$(date +%m)/$(date +%Y)\n" >> ${file_test}${result_file}
printf "$(date +%H):$(date +%M)\n\n" >> ${file_test}${result_file}

for champ in ${all_champs[@]}; do
	((nb_done++))

	cor="$(echo "${champ}" | sed 's/\.s//').cor"
	printf "[${cor}]\n" >> ${file_test}${result_file}
	printf "\n[${nb_done}/${nb_champs}] "
	printf "${grey}[$(basename ${cor})]${reset}\n"
	read

	printf "[REAL] - "
	./${resources_file}asm ${champ}
	if [ -e ${cor} ]; then
		mv ${cor} ${file_test}cor_real
	else
		printf "[REAL] - $(basename ${cor}) hasn't been created\n" >> ${file_test}${result_file}
	fi

	printf "\n[MINE] - "
	./${asm_name} ${champ}
	if [ -e ${cor} ]; then
		mv ${cor} ${file_test}cor_mine
	else
		printf "[MINE] - $(basename ${cor}) hasn't been created\n" >> ${file_test}${result_file}
	fi

	if [ -e "${file_test}cor_mine/$(basename ${cor})" ] && [ -e "${file_test}cor_real/$(basename ${cor})" ]; then
		bash -c "diff -y <(xxd ${file_test}cor_real/$(basename ${cor})) <(xxd ${file_test}cor_mine/$(basename ${cor}))" >> ${file_test}${result_file}
	fi
	printf "\n" >> ${file_test}${result_file}
done
