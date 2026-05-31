#include <stdio.h>

int mul(int a,int b){

    return a*b;
}
int main(int argc, char** argv) {
    
    int num1 = 10;
    int num2 = 20;

    int(*mul_pointer)(int,int);

    mul_pointer = mul;

    printf("Result : %d",mul_pointer(num1,num2));

}
