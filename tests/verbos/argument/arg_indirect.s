.name "arg_indirecte"
.comment "Un simple champion pour tester la recuperation des arguments indirects"

test1:	ldi %:test1,%:test2,r1
		ldi %10,%15,r2
		ldi %16,%19,r3
		ldi %:test2,%:test2,r4
		ldi %449,%10,r6

test2:	ldi %:test2,%:test2,r4
		ldi %-44,%:test1,r4
		ldi %:test1,%10,r4
		ld	%:test1,r2
