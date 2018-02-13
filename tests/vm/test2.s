.name "test"
.comment "just a basic test prog"

live:	live%5
		live%5

ld: ld %-42000000, r2

st: st r2, r3

st: st r2, :live
