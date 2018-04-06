.name "test"
.comment "just a basic test prog"

live:	live %1

ld:		ld %4200, r1

ldi:	ldi r1, r1, r2

st:		st r2, :live
