.name "zoo77777777777oz"
.comment "KlllK"

debut:
    live    %42

init:
	sti     r4,     %:label, %1
	add     r4,     r12,     r4

label:
    sub     r10,    r11,     r10
	zjmp    %:init
	fork    %:debut
	live    %3
    live    %3
