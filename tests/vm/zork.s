.name "zork"
.comment "just a basic living prog"

l2:		sti r1,%:live,%4
		and r3,%4,r1

live:	live %1
		zjmp %:live
		zjmp %:live
		zjmp %:live
		zjmp %:live
		zjmp %:live
