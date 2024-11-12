/*Pointers*/

#include<stdio.h>
int pointer1()
{
    //the assignment ptr = &a; occurs after ptr is declared.
    int a=4;
    int *ptr;
    ptr=&a;
    //a=4, *ptr=4, ptr=6421988 6421984
    printf("a=%d\n*ptr=%d\nptr=%d\n&ptr=%d\n&a=%d\n",a,*ptr,ptr,&ptr,&a);
    return 0;
}
int pointer2()
{
    //the assignment ptr = &a; happens at the time of declaration.
    int a=4;
    int *ptr=&a;
    //a=4, *ptr=4, ptr=6421988 6421984
    printf("a=%d\n*ptr=%d\nptr=%d\n&ptr=%d\n&a=%d\n",a,*ptr,ptr,&ptr,&a);
    return 0;

}
int main()
{
    //both have the same function
    pointer1();
    pointer2();
}


/*Increment Operator*/
#include<stdio.h>

int main()
{
    int i = 5;

    // Example with pre-increment
    printf("Initial value of i: %d\n", i);
    printf("Value with pre-increment (++i): %d\n", ++i); // i is incremented before it is used
    printf("Value after pre-increment: %d\n", i);

    // Resetting i for post-increment example
    i = 5;

    // Example with post-increment
    printf("\nInitial value of i: %d\n", i);
    printf("Value with post-increment (i++): %d\n", i++); // i is used, then incremented
    printf("Value after post-increment: %d\n", i);

    return 0;
}
/*Using Function*/

#include<stdio.h>
int a=1;
int Add(int a)//formal parameters
{
    int b=9;
    b+=a;
    return b;
}

int main()
{
    int result=Add(4.78);//actual parameters or arguments
    printf("result=%d",result);
    return 0;
}
/*Using Format Specifiers*/

#include <stdio.h>

int main() {
    int num1 = -255;
    printf("num1=%d\n",num1);
    printf("num1 in :\np(pointer address)= %p\nu(unsigned int)=%u\nd(signed int)=%d\nx(hexadecimal)=%x\n",num1 ,num1,num1,num1); // Output: ff
    return 0;
}
