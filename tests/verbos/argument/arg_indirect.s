.name "arg_indirect"
.comment "Un simple champion pour tester la recuperation des arguments indirects"

test1:	or :test1	,  :test1	,  r1
		or 10		,  -15		,  r2
		or 16		,  0		,  r3
		or :test1	,  :test1	,  r4
		or 1		,  10		,  r6

test2:	or :test1	,  :test1	,  r4
		or -44		,  :test1	,  r4
		or :test1	,  -8999	,  r4
		ld :test1	,  r2
