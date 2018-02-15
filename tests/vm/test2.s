.name "test"
.comment "just a basic test prog"

live:	live%5
		live%5

ld: ld %-42000000, r2

st: st r2, r3

st: st r3, :live

add: add r2, r3, r1

st2: st r1, :live

sub: sub r1, r2, r3

st3: st r3, :live

and: and %25, %20, r2

st4: st r2, :live

ld: ld %-42000000, r2

zjmp: zjmp %2
