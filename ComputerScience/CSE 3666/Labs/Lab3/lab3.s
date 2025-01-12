#       CSE 3666 Lab 3: remove spaces

        .data
        .align 2
        # allocating space for both strings
str:    .space  128
res:    .space  128

        .globl  main

        .text
main:   

        # read a string into str
        # use pseudoinstruction la to load address into register
        la      a0, str
        li      a1, 100
        li      a7, 8
        ecall

        # a0 is the address of str
        la      a1, res

        # TODO
	# remove spaces in str
	# print res
	addi t4, x0, 0 # i = 0
	addi t5, x0, 0 # j = 0
	addi a2, x0, 32 # len till stop
	loop:
		add t1, a0, t4 # go to str[0] + i
		lb t6, 0(t1) # c = str[i] read byte at i in the string
		bne t6, a2, if # if c != 32, goto if
		beq x0, x0, ifexit
		if:
			add t1, a1, t5 # a1 + j
			sb t6, 0(t1) #res[j] = c
			addi t5, t5, 1 # j += 1
		ifexit:
			addi t4, t4, 1 #i += 1
			beq t6, zero, exitloop
			beq x0, x0, loop
	exitloop:
	li a7, 4 # Load print statment
	add a0, a1, zero #stage a0
	ecall  		# make the call
               
exit:   addi    a7, x0, 10
        ecall
