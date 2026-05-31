#include <stdio.h>

int add(int a,int b){

    return a+b;
}

int mul(int a,int b){

    return a*b;
}

int operate(int a,int b, int (*function_pointer)(int,int))
{
    return function_pointer(a,b);
}
int main(int argc, char** argv) {


    printf("Addition : %d\n",operate(10,20,add));
    printf("Multiplication  : %d\n",operate(10,20,mul));
    
}
