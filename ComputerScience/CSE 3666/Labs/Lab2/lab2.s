#       CSE 3666 Lab 2

        .globl  main

        .text
main:   
        
        # read one integer from the console and 
        # print the number in binary 
 
        # use system call 5 to read integer
        addi    a7, x0, 5
        ecall
        addi    s1, a0, 0

        # use system call 35 to print a0 in binary
        # a0 has the integer we want to print
        addi    a7, x0, 35
        ecall
        
        # TODO
        # Add you code here
        #   print newline
        #   print 32 bits in s1, using a looop
        #   print newline
        # add ascii chars
        lui s1, 0x80000
Loop:	# if s0 == 0, End
	beq s0, x0, End # if s0 == 0, Ened
	
	and s2, s0, s1 # and s1 and s0 into s2
	
	bne s2, x0, Else # if s2 is 1 then go to the Else
	
	# if you made it here, you are the critical section
	li a7, 1 	#load service to print integer
	addi a0, x0, 0	# load 0 (desired value) in register a0
	ecall # make the call
	
	beq x0, x0, Endif
	
Else:
	# we need to print 1
	li a7, 1 # load service to print integer
	addi a0, x0, 1 # load 1 into a0
	ecall # make the call
	
Endif:
	# shift s0 to the right
	srli s0, s0, 1
	
	beq x0, x0, Loop # back to the top of the loop agiain
End:
	# add ascii chars
	addi a7, x0, 11
	addi a0, x0, '\n'
	ecall
        
        # exit
exit:   addi    a7, x0, 10      
        ecall
