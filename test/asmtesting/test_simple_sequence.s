.global _start
.align 2

_start:
mov w5, #0

    loop:
    mov w3, #15
    sdiv w6, w5, w3
    mul w6, w6, w3
    sub w6, w5, w6 
    cmp w6, #0
    b.eq _print_fizzbuzz
    
    mov w3, #3
    sdiv w6, w5, w3
    mul w6, w6, w3
    sub w6, w5, w6 
    cmp w6, #0
    b.eq _print_fizz
    
    mov w3, #5
    sdiv w6, w5, w3
    mul w6, w6, w3
    sub w6, w5, w6 
    cmp w6, #0
    b.eq _print_buzz 
    
    b _print_number
    
    comparison:
    cmp w5, #50
    add w5, w5, #1
    b.ne loop
    
    mov x0, #0   //return 0
    mov x16, #1  //terminate
    svc 0x80  //syscall

_print_fizzbuzz:
mov x0, #1
adrp x1, fb@page
add x1, x1, fb@pageoff
mov x2, #9
mov x16, #4
svc 0
b comparison

_print_fizz:
mov x0, #1
adrp x1, fizz@page
add x1, x1, fizz@pageoff
mov x2, #5
mov x16, #4
svc 0
b comparison

_print_buzz:
mov x0, #1
adrp x1, buzz@page
add x1, x1, buzz@pageoff
mov x2, #5
mov x16, #4
svc 0
b comparison

_print_number:
mov x0, #1
adrp x1, num@page
add x1, x1, num@pageoff
mov x2, #4
mov x16, #4
svc 0
b comparison

.data
fb: .asciz "FizzBuzz\n"
fizz: .asciz "Fizz\n"
buzz: .asciz "Buzz\n"
num: .asciz "Num\n"
