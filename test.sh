
#Setup data
line_champs=$(find ./tests/champions/cor_mine -name "*.cor")
all_champs=()
for champ in ${line_champs[@]}; do
	all_champs[${#all_champs[@]}]=${champ}
done
nb_champs=${#all_champs[@]}
nb_done=0

clear
make asm
./asm -s aaaaaa.s
rm tmp

for champ in ${all_champs[@]}; do
	((nb_done++))
	printf "\n[${nb_done}/${nb_champs}] [${champ}]\n" >> tmp
    ./.resources/corewar aaaaaa.cor ${champ} >> tmp
    printf "\n" >> tmp
    ./.resources/corewar ${champ} aaaaaa.cor >> tmp
    printf "\n" >> tmp
done

nb_done=$(grep -c "Contestant" tmp)
nb_win=$(grep -c '"aaaaaa", has won !' tmp)

printf "\"aaaaaa\", has won [${nb_win}/${nb_done}]" >> tmp
