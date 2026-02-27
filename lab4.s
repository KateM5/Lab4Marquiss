.section .text
.global sum_array

sum_array:
    movl $0, %eax           # Set total sum = 0
    movl $0, %ecx           # Use %ecx as our loop index (i = 0)

    loop_start:
        cmpq %rsi, %rcx         # Compare index (i) with count (n)
        jge loop_end            # If i >= n, we are done!

        addl (%rdi, %rcx, 4), %eax 

        incq %rcx               # i++
        jmp loop_start          # Repeat
    loop_end:
        ret                     # Return to the C program
        .section .note.GNU-stack,"",@progbits
        