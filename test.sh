
grey="\033[38;5;8m"
reset="\033[0m"

#flag
[[ $2 == "-f" ]] && flag="ON" || flag="OFF"

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

printf "[EN COUR]\n"
for champ in ${all_champs[@]}; do
	((nb_done++))
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
