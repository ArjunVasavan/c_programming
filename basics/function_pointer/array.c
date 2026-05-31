#include <stdio.h>
#include <string.h>


int add(int a, int b){
    return a+b;
}

int mul(int a, int b){
    return a*b;
}

int divi(int a, int b){ /* hello world */
    return a/b;
}

int sub(int a, int b){
    return a-b;
}
int main(int argc, char** argv) { /* hellow */
    
    int(* fun_array[4])(int,int);
 /* hi */
    fun_array[0] = add;
    fun_array[1] = mul;
    fun_array[2] = divi;
    fun_array[3] = sub;

    int num1,num2;

    printf("Enter two number : ");
    scanf("%d %d",&num1,&num2);
 /* oh hell na */

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
