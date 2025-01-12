#       Merge Sort

        .data                   #data segment
        .align 2
buffer: .space 4096             #allocate space for 1K words

        .text                   # Code segment
        .globl  main            # declare main to be global
main: 
        # specify the size of the array, must be less than 1024
        la      s0, buffer      # address of the buffer in s0
        li      s1, 1024        # number of elements in s1

        # call init_array() to initialize the array with random values
        mv      a0, s0          # use pseudoinstructions
        mv      a1, s1
        jal     ra, init_array 

        # call merge_sort function with proper arguments
        mv      a0, s0          # use pseudoinstructions
        mv      a1, s1
        jal     ra, merge_sort

        # set a breakpoint here and examine the memory
Exit:   li      a7, 10         # System call, type 10, standard exit
        ecall                  # ...and call the OS

####START_OF_MERGE_SORT
# void merge_sort(int p[], int n)
# TODO
merge_sort:

        jr      ra

####END_OF_MERGE_SORT

##### No need to change anything below
# void init_array(int *p, int n), or
# void init_array(int p[], int n) 
# use pseudorandom system calls
init_array:

        addi    t0, a0, 0
        slli    t1, a1, 2
        add     t1, t1, t0

        # set the seed
        li      a0, 0
        li      a1, 3666
        li      a7, 40
        ecall

        # syscall for rand()
        # 41 on randon integer
        # 42 for bounded values. upper bound is in a1
        li	a1, 10000
        li      a7, 42

        beq     zero, zero, llinit_test

llinit_loop:
        li      a0, 0 
        ecall
        sw      a0, (t0)                # save the random value
        addi    t0, t0, 4               # move to the next word
llinit_test:
        bltu    t0, t1, llinit_loop 

        jr      ra
