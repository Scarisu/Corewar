.name		"label_arg_inadequate"
.comment 	"Test de la reaction du verbos lorsque qu'un label est initalisé deux fois"

live1:	live	%1
		live	%1
		live	%1
		live	%1
		live	%1

		sti 	r1,%:live1,%1
		live	%1
		live	%1
		sti 	r1,%:live4888,%1
		live	%1

live2:	live	%1
		live	%1
		sti 	r1,%:live66,%1
		live	%1
		live	%1

		live	%1
live2:	live	%1
		live	%1
		sti 	r1,%:live2,%1
		live	%1
