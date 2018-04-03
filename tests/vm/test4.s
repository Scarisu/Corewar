.name "test"
.comment "just a basic test prog"

live:	live %1

ld:		ld %4200, r2
		ld %4000, r3

sti:	sti r2, :live, %450
