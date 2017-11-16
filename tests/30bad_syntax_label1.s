.name "30bad_syntax_label1"
.comment "test syntax label"

prut:	live %1
		ld %3,r-2
		st r2444,r+4
		add r2,r3,r4
		sub r3,r5,r3
		and :prut,:prut,r5
		or	:%45,:prut,r2
			xor
#		zjmp
	#	ldi
	#	sti
	#	fork
	#	lld
	#	lldi
	#	lfork
	#	aff

#khjv
#6645t:
#prt: liv1 %4
#prt: live %5
#prto: live %6
