.name "arg_direct"
.comment "Un simple champion pour tester la recuperation des arguments directs"

test1:	ldi %:test1	,  %:test2	,  r1
		ldi %10		,  %15		,  r2
		ldi %1s6	,  %0		,  r3
		ldi %:test2	,  %:test2	,  r4
		ldi %559	,  %10		,  r6

test2:	ldi %:test2	,  %:test4	,  r4
		ldi %-44	,  %:test5	,  r4
		ldi %:test1	,  %-3		,  r4
		ld	%:test1	,  r2

test4:
test45:
tegh:
