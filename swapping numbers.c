/*Swapping variables using temporary variable*/
#include<stdio.h>
int main()
{
    //Using temp
    int a=1;
    int b=2;
    int temp=NULL;
    printf("Before:a=%d b=%d temp=%d\n",a,b,temp);
    temp=a;
    a=b;
    b=temp;
    printf("AFTER:a=%d b=%d temp=%d",a,b,temp);

    //Using arithmetic operations
    int a = 1;
    int b = 2;

    printf("Before swap: a = %d, b = %d\n", a, b);

    // Swap using arithmetic operations
    a = a + b; // a becomes 3
    b = a - b; // b becomes 1 (original value of a)
    a = a - b; // a becomes 2 (original value of b)

    printf("After swap: a = %d, b = %d\n", a, b);

    //using XOR
    int a = 1;
    int b = 2;

    printf("Before swap: a = %d, b = %d\n", a, b);

    // Swap using bitwise XOR
    a = a ^ b; // a becomes a ^ b
    b = a ^ b; // b becomes (a ^ b) ^ b = a
    a = a ^ b; // a becomes (a ^ b) ^ a = b

    printf("After swap: a = %d, b = %d\n", a, b);

}
