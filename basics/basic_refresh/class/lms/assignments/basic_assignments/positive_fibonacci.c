/*
Name        : Arjun Vasavan

Date        : 24-07-2025

Description : This Code Generates Positive Fibonacci Series till it reaches the input limit entered by user
              
Sample execution:-

Test Case 1 :

input  :- Enter a number: 5

output :-  0 1 1 2 3 5

*/

#include<stdio.h>

int main()
{
    int first = 0 ; 
    int second = 1;
    int n = 0;
    int limit ;
    
    printf("Enter a number: ");
    scanf("%d",&limit);
    
    if (limit >= 0)
    {
        
        while ( n <= limit)
        {
            printf("%d ",n);
            first = second;
            second = n;
            n = first + second;
        
         }
        
    }
    
    else
    {
        printf("Invalid input");
    }
}
