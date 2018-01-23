start=0
end=10

cp ../aaaaaa.s ../aaaaaa${start}.s

for i in $(seq ${start} ${end}); do
./battle.sh -c ../aaaaaa${i}.s
next=$(echo $((${i}+1)))
sed "/live %/ s/${i}/${next}/g" ../aaaaaa${i}.s > ../aaaaaa${i}.tmp

mv ../aaaaaa${i}.tmp ../aaaaaa${next}.s
rm ../aaaaaa${i}.s ../aaaaaa${next}.cor
done
