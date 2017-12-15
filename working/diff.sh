clear

champ="$1"
cor="${champ%%.*}.cor"

mkdir -p mine
mkdir -p real
mkdir -p diff
rm -f ./real/$(basename ${cor})
rm -f ./mine/$(basename ${cor})

make -C ../ asm
gcc main.c ../lib/libft/libft.a -I ../includes

./../.resources/asm ${champ}
mv ${cor} ./real

printf "[Press enter]\n"
./../asm ${champ}
mv ${cor} ./mine

rm -f diff/diff_$(basename ${champ%%.*}).txt
# ./a.out ./real/$(basename ${cor}) ./mine/$(basename ${cor}) | more

bash -c "diff -y <(xxd real/$(basename ${cor})) <(xxd mine/$(basename ${cor}))" >> diff/diff_$(basename ${champ%%.*}).txt
