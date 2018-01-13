make asm
./asm -s aaaaaa.s
enemey="aaaaaa"
#enemey="Octobre_Rouge_V4.2"

# enemey="Gagnant"
# enemey="Gagnant"
#./asm -s vm_champs/VM/champs/${enemey}.s
./asm -s ${enemey}.s
#./.resources/corewar -n aaaaaa.cor vm_champs/VM/champs/${enemey}.cor
./.resources/corewar -n aaaaaa.cor ${enemey}.cor
