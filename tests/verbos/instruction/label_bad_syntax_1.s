.name "label_bad_syntax_1"
.comment "Test sur la syntax du label"

prut:	live %1
		ld %3,r2
		st r2,r4

:		live %1

l'image: live %1
	ld %3,r2
oui:ld %3,r2

voila : live %1
