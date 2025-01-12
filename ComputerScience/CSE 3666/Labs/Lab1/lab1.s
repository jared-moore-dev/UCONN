#       CSE 3666 Lab 1

        .globl  main

        .text
main:   
        
        # read two positive integers from the console and 
        # save them in s1 and s2 
        # compute the GCD of the two numbers with Euclidean algorithm 
        #     while a != b:
        #         if a > b:
        #             a = a - b
        #         else:
        #             b = b - a
        # print the GCD
        
        # psuedocode
        
        #Loop
          # Break Condition
          #if (a = b) goto Print
          
          #Loop Body
          #if a <= b goto Else
          #a = a - b
          #goto Endif
        #Else:
          #b = b - a
        #Endif:
          #goto Loop
        #Print
          #print a
          
        # end psudocode

        # GCD examples:
        #     gcd(11, 121) = 11
        #     gcd(24, 60) = 12
        #     gcd(192, 270) = 6
        #     gcd(14, 97) = 1

        # use system call 5 to read integers
        addi    a7, x0, 5
        ecall
        addi    s1, a0, 0       # a in s1

        # using pseudoinstructions
        li      a7, 5
        ecall
        mv      s2, a0          # b in s2

        # TODO
        # Add you code here
        # compute GCD(a, b) and print it
        Loop: # runs while s1 != s2
          # Break Condition
          beq s1, s2, Print # Compare s1 and s2, if equal, goto the print statement
          
          ble s1, s2, Else # IF s1 <= s2, go to the else condition (b = b-a)
          
          # Previous statement must not have been true, therefore
          sub s1, s1, s2 # a = a-b
          
          #While True, EndIf
          beq x0, x0, Endif
          
        Else:
          # Branched
          sub s2, s2, s1 # b = b-a
          
        Endif:
          # Loop again
          beq x0, x0, Loop
        
        Print:
          # Print the result
          li a7, 1 # service 1 is a print integer
          addi a0, s1, 0 # set s1 into a0 by placing the result of s1 + 0 in a0
          ecall # execute the print statement
          
          
        

        # sys call to exit
exit:   addi    a7, x0, 10      
        ecall
