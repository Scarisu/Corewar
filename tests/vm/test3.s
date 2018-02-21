.name "test"
.comment "just a basic test prog"

live:	live%1

sub:	add r1, r1, r4
		sub r1, r4, r4
		sub r1, r4, r4
		sub r1, r4, r4
		sub r1, r4, r4

ldi:	ldi r4, %:live, r3

st:		st r3, :live
