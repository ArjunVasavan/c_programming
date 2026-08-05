/*

Name : Arjun Vasavan

Date : 24-07-2025

Description : This Program is to Check if a number is perfect or not.

Sample execution:-

Test Case 1:

Input  :-  Enter a number: 123

Output :-  No, entered number is not a perfect number

Test Case 2:

Input  :- Enter a number : 8128

Output :- Yes, entered number is perfect number

*/
#include <stdio.h>

int main()
{
    int num;
    int sum = 0;
    
    printf("Enter a number: ");
    scanf("%d",&num);
    
    if( num >= 0)
    {
        
        for ( int i = 1 ; i <= ( num / 2 ) ; i++)
        {
            if( num % i == 0)
            {
                sum+=i;
            }
        }
        
        if ( sum == num )
        {
            printf("Yes, entered number is perfect number");
        }
        
        else
        {
            printf("No, entered number is not a perfect number");
        }
        
    }
    
    else
    {
        printf("Error : Invalid Input, Enter only positive number");
    }
    
}

