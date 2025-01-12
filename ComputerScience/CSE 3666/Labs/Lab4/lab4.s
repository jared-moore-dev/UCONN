#       CSE 3666 Lab 4: Remove spaces

        .data

        # allocating space for str
str:    .space  128

        .globl  main

        .text
main:   
        # read a string into str
        # use pseudoinstruction la to load address into register
        la      a0, str

main_loop:
        # read a string
        addi    a1, x0, 100
        addi    a7, x0, 8
        ecall

        # check if the line is empty (has only the newline) 
        lb      t0, 0(a0)
        addi    t1, x0, '\n'
        beq     t0, t1, exit

	# a0 is already set. does not change during ecall
	jal	ra, print_ns

        # the address of str should be in a0 
        beq     x0, x0, main_loop
 
exit:   addi    a7, x0, 10
        ecall

# DO NOT change code above this line

# function 
print_ns:
        # TODO
        # allocate a byte array of 128 bytes on stack to save result  
        # call remove_spaces
        # print the result string
        # identify the registers that need to be preserved, but changed
        # save/restore registers
        
        # Make stack
        	# addi sp, sp, -4 # Drop the stack pointer down by 4
        	# sw a0, 0(sp) 	# Save a0 via sp
        	addi sp, sp, -128 #Shift pointer sp down by 128
        	add a1, zero, sp # Save a1 in sp
        	
        	addi sp, sp, -4 # Drop the stack pointer down by 4
        	sw ra, 0(sp) 	# save ra via sp
        	
        # Call Function
        	# Extend stack for chars for into
        	jal ra, remove_spaces # jump to remove_spaces
        	
	#print a1
		li a7, 4	  # Service 4 is print string
		add a0, a1, zero  # Load desired value into a0 for the call
		ecall 		  # Make the Call

	#retrieve the old return address
		lw ra, 0(sp)
	
	#put the stack pointer back
		addi sp, sp, 132

	#return
	jr      ra

# function remove_spaces
remove_spaces:
        # TODO
	# copy your code from lab 3 here
        # it should work if it uses only temporary and argument registers
	# make necessary changes if needed
	
	addi t4, x0, 0 # i = 0
	addi t5, x0, 0 # j = 0
	addi a2, x0, 32 # len till stop
	loop:
		add t1, a0, t4 # go to str[0] + i
		lb t6, 0(t1) # c = str[i] read byte at i in the string
		bne t6, a2, if # if c != 32, goto if
		beq x0, x0, ifexit # Else, Exitif
		if:
			add t1, a1, t5 # a1 + j
			sb t6, 0(t1) #res[j] = c
			addi t5, t5, 1 # j += 1
		ifexit:
			addi t4, t4, 1 #i += 1
			beq t6, zero, exitloop # if str[i] = 0, exit
			beq x0, x0, loop # Else, go to the loop again
	exitloop:
	#li a7, 4 # Load print statment
	#add a0, a1, zero #stage a0
	#ecall  		# make the call
	
	jr      ra
