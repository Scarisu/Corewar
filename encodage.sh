
asm_name="asm"
asm_resources="asm"
file_test="tests/champions/"

all_champ=$(echo "$(ls tests/champions/asm/*.s)")

underline="\033[4m"
reset="\033[0m"
grey="\033[38;5;8m"

make asm
rm -f *.cor
rm -f ${file_test}/asm/*.cor
rm -f ${file_test}result.txt
mkdir -p ${file_test}cor_mine
mkdir -p ${file_test}cor_real

mkdir -p .tmp
mkdir -p .tmp/real
mkdir -p .tmp/mine

cp ${asm_name} .tmp/mine
cp resources/${asm_resources} .tmp/real

for champ in ${all_champ[@]}; do
	printf "./.tmp/mine/${asm_name} ${champ}\n"
	touch ./.tmp/mine/test.cor

	cor_mine=$(ls -t .tmp/mine/*.cor)
	if [[ -n "${cor_mine}" ]]; then
		mv ${cor_mine} ${file_test}cor_mine/
	else
		printf "\"${grey}./${asm_name}${reset}\""
		printf " couldn't compile ${grey}$(basename ${champ})${reset}\n"
	fi

	printf "./.tmp/real/${asm_resources} ${champ}\n"
	touch ./.tmp/real/test.cor

	cor_real=$(ls -t ${file_test}/asm/*.cor)


	read
done
