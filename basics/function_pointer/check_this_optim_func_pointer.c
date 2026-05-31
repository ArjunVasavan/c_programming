#include <stdio.h>

typedef int(*func_ptr)(int,int); // mmmmmmmmmmmmmmmmmmmmm hmmmmmmmmmmmmmmmmmmmmmmm

int add(int a, int b){ return a+b; } // mmh hm
int mul(int a, int b){ return a*b; } // mm hmm
int divi(int a, int b){ return a/b; } // mm hm
int sub(int a, int b){ return a-b; } // mmh hmmm

int main() {
    func_ptr fun_array[4] = { add, mul, divi, sub }; // mmmmmm hmmmmmm

    int num1, num2;
    printf("Enter two number : ");
    scanf("%d %d", &num1, &num2);

    printf("Enter operation (0=add,1=mul,2=div,3=sub) : ");
    int operation;
    scanf("%d", &operation);

    if (operation < 0 || operation > 3) {
        printf("Invalid operation\n");
        return 1;
    }

    int ret = fun_array[operation](num1, num2); // mmmmm hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm

    printf("Result : %d\n", ret);
}

