#include <stdlib.h>
#include <stdio.h>


void print_val(char* p, int x){
    printf("p is %s and x is %d\n",p, x);
}

int main(){

    //1. Write a “Hello, World!” program in C, compile it, and run it.

    printf("Hello, World!\n");

    //2. Define two variables holding “Hello” and “World!” respectively;
    //concatenate them with a space in between; and output them as Hello World!.

    char* hello = "Hello";
    char* world = "World!";
    printf("%s %s\n", hello, world);

    //3. Define a C function that takes a char* parameter p and an int parameter x
    //and print out their values in this format: p is"foo" and x is 7. Call it with a few argument pairs.

    print_val("Apple", 10);
    print_val("Banana", 20);
    print_val("Orange", 30);

    return 0;
}