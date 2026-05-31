/*
-------------------------------------------------------------------------------

Name         : Arjun Vasavan

Date         : 01 - 10 - 2025

Description  : Program to define a macro swap (t, x, y) that swaps 2 arguments 
               of type t.



Sample execution :

1. Int
2. char
3. short
4. float
5. double
6. string
Enter you choice : 1

Enter the num1 : 10
Enter the num2 : 20
After Swapping :
num1 : 20
num2 : 10

-------------------------------------------------------------------------------
*/

#include<stdio.h>
#include <stdlib.h> // for malloc function

#define SWAP(t,x,y) \
{                   \
t temp = x;         \
x = y;              \
y = temp;           \
}

int main()
{
  printf("1.int\n");
  printf("2.char\n");
  printf("3.short\n");
  printf("4.float \n");
  printf("5.double \n");
  printf("6.string  \n");
  printf("Enter you choice: \n");
  int choice;
  scanf("%d",&choice);

  switch (choice)
  {
    case 1:
      {
        int n1,n2;
        printf("Enter the num1 : ");
        scanf("%d",&n1);
        printf("Enter the num2 : ");
        scanf("%d",&n2);
        SWAP(int,n1,n2);  //integer is passed as 't'
        printf("After Swapping : \n");
        printf("num1 : %d\n",n1);
        printf("num2 : %d\n",n2);
        break;
      }
    case 2:
      {
        char char1,char2;
        printf("Enter the char1 : ");
        getchar();
        scanf("%c",&char1);
        printf("Enter the char2 : ");
        getchar();
        scanf("%c",&char2);
        SWAP(char,char1,char2); //character is passed as 't'
        printf("After Swapping : \n");
        printf("char1 : %c\n",char1);
        printf("char2 : %c\n",char2);
        break;
      }
    case 3:
      {
        short int n1,n2;
        printf("Enter the num1 : ");
        scanf("%hd",&n1);
        printf("Enter the num2 : ");
        scanf("%hd",&n2);
        SWAP(short int,n1,n2); // short is passed here as 't'
        printf("After Swapping : \n");
        printf("num1 : %hd\n",n1);
        printf("num2 : %hd\n",n2);
        break;
      }
    case 4:
      {
        float n1,n2;
        printf("Enter the num1 : ");
        scanf("%f",&n1);
        printf("Enter the num2 : ");
        scanf("%f",&n2);
        SWAP(float,n1,n2);
        printf("After Swapping : \n");
        printf("num1 : %f\n",n1);
        printf("num2 : %f\n",n2);
        break;
      }
    case 5:
      {
        double n1,n2;
        printf("Enter the num1 : ");
        scanf("%lf",&n1);
        printf("Enter the num2 : ");
        scanf("%lf",&n2);
        SWAP(double,n1,n2); // integer is passed here as 't' 
        printf("After Swapping : \n");
        printf("num1 : %lf\n",n1);
        printf("num2 : %lf\n",n2);
        break;
      }
    case 6:
      {
        char*str1 = malloc(50); //malloc is used to store dynamically
        char*str2 = malloc(50);
        getchar(); // for removing spaces
        printf("Enter string1 : ");
        scanf("%[^\n]",str1);
        getchar(); // for removing spaces
        printf("Enter string2 : ");
        scanf("%[^\n]",str2);
        SWAP(char*,str1,str2); // character pointer is passed here as 't'
        printf("After Swapping : \n");
        printf("string1 : %s\n",str1);
        printf("string2 : %s\n",str2);
        break;
      }
  }
}
