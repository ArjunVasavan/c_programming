#include <stdio.h>

typedef int(*func_ptr)(int,int);

int add(int a, int b){
    return a+b;
}

int mul(int a, int b){
    return a*b;
}

int divi(int a, int b){
    return a/b;
}

int sub(int a, int b){
    return a-b;
}
int main(int argc, char** argv) {
    
    func_ptr fun_array[4];

    fun_array[0] = add;
    fun_array[1] = mul;
    fun_array[2] = divi;
    fun_array[3] = sub;

    int num1,num2;

    printf("Enter two number : ");
    scanf("%d %d",&num1,&num2);


    printf("Enter which operation : ");
    short int operation;
    scanf("%hd",&operation);

    int ret;
    switch (operation) {
    
        case 0:{

            ret = fun_array[0](num1,num2);

            break;
        }
        case 1:{

            ret = fun_array[1](num1,num2);
            break;
        }
        case 2:{

            ret = fun_array[2](num1,num2);
            break;
        }
        case 3:{

            ret = fun_array[3](num1,num2);
            break;
        }

    }

    printf("Result : %d\n",ret);

}
