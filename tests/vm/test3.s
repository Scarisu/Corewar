.name "test"
.comment "just a basic test prog"

live:	live%1

ld:		ld %4200, r4

sti:	sti r4, %45641, r4
		sti r2, :live, %:live
