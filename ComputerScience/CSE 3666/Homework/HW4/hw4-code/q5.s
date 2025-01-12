#       CSE 3666 uint2decstr

        .globl  main

	.data
	
str:	.space 100

        .text
main:   
	la	a0, str
        li	a1, -1		# test with different numbers
	jal	ra, uint2decstr

        la      a0, str
        addi    a7, x0, 4
        ecall

exit:   addi    a7, x0, 10      
        ecall

# char * uint2decstr(char *s, unsigned int v) 
# the function converts unsigned value to decimal string
# Here are some examples:
# 0:    "0"
# 2022: "2022"
# -1:   "4294967295"
#char * uint2decstr(char *s, unsigned int v)
#{
#unsigned int r;
#if (v >= 10) {
#s = uint2decstr(s, v / 10);
#}
#r = v % 10;
#// remainder
#s[0] = '0' + r;
#s[1] = 0;
#return &s[1];
#}
#// return the address of s[1]
uint2decstr:
	addi sp, sp, -8 # make space for data on the stack
	sw a1, 0(sp)	# Save the string on the stack
	sw ra, 4(sp) 	# Save the return address on the stack
	addi t0, x0, 10 # store the temp value of 10
	bltu a1, t0, calculate # if basecase is reached, then jump to calculate
	divu a1, a1, t0 # divide by 10 and store the result in a1
	jal ra, uint2decstr # Recourse

calculate:
	lw ra, 4(sp) 	# Restore the return address
	lw a1, 0(sp)	# load a0 with the string stored on the stack
	addi t0, x0, 10 # store the value of 10 to test against
	remu t1, a1, t0	# take the remainder of v/10
	addi t0, t1, '0'	# convert the remainder to a character
	sb t0, 0(a0) 	# store the char in the stack
	addi a0, a0, 1 	# increment the address by 1
	addi sp, sp, 8	# restore the stack pointer to where it was
	jr	ra
