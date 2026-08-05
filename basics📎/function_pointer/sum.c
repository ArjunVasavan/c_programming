#include <stdio.h>

int sum(int num1,int num2);

int main() {
    
    int (*fun_pointer)(int,int);
    fun_pointer = sum; // or &sum

    int ret = fun_pointer(10,20);

    printf("Returned value : %d\n",ret);

}

int sum( int num1,int num2){

    return num1 + num2;
}
