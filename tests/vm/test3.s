.name "test"
.comment "just a basic test prog"

live:	live%1

ld:		ld :live, r4

st:		st r1, :sti

sti:	sti r4, %45641, r4
		sti r2, :live, %:live
