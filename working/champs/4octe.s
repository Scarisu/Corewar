.name "zoo77777777777oz"
.comment "KlllK"

prout:
    #ld          %:test,        r4
   #(1)(2)      (3.4.5)(6)     (7)
    #ld          %:test,        r4
   #(8)(9)      (10.11.12)(13) (14)

test:
    #live        %45
   #(15)        (16.17.18)(19)
    #zjmp        %55

	#st		r1, 6
#    st		r1, 6
#    st		r1, 6

#sti		r1,		%:test,		%1
#ld		%75,	r13
#aff		r13
#fork	%:test
#live	%1337


    #ld          %:test,         r4
   #(13)(14)    (15.16.17)(18)  (19)



#ld      %45, r4
#and     %45, %45, r4
#or      %45, %45, r4
#xor     %45, %45, r4
#lld     %45, r4
