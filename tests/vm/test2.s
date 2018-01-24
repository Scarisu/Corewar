.name "test"
.comment "just a basic test prog"

live:	live%5
		live%5

ld:		ld :live, r1
		ld :live, r2

add:	add r1, r2, r3

st:		st r3, :live
		add r3, r3, r3
		st r3, :live
		add r3, r3, r3
		st r3, :live
		add r3, r3, r3
		st r3, :live
		add r3, r3, r3
		st r3, :live
		add r3, r3, r3
		st r3, :live
		add r3, r3, r3
		st r3, :live
		add r3, r3, r3
		st r3, :live
		add r3, r3, r3
		st r3, :live
		add r3, r3, r3
		st r3, :live
		add r3, r3, r3
		st r3, :live
		add r3, r3, r3
		st r3, :live
		add r3, r3, r3
		st r3, :live
		add r3, r3, r3
		st r3, :live
		add r3, r3, r3
		st r3, :live
		add r3, r3, r3
		st r3, :live
		add r3, r3, r3
		st r3, :live
