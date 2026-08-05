/* 

Name : Arjun Vasavan

Date : 04-08-2025

Description:

Program which generate AP,GP,HP series

Sample execution: -

Test Case 1:

Enter the First Number 'A': 2
Enter the Common Difference / Ratio 'R': 3
Enter the number of terms 'N': 5
AP = 2, 5, 8, 11, 14
GP = 2, 6, 18, 54, 162
HP = 0.500000, 0.200000, 0.125000, 0.090909, 0.071428

Test Case 2:
Enter the First Number 'A': 2
Enter the Common Difference / Ratio 'R': 3
Enter the number of terms 'N': -5
Invalid input




*/
#include <stdio.h>

int main ()
{
    int a, r, n, ap, gp;
    
    printf("Enter the First Number 'A': ");
    scanf("%d",&a);
    
    printf("Enter the Common Difference / Ratio 'R': ");
    scanf("%d",&r);
    
    printf("Enter the number of terms 'N': ");
    scanf("%d",&n);
    
    ap = a;
    
    gp = a;
    
    if ( n < 0 )
    {
        printf("Invalid input");
    }
    
    else
    {
    
        printf("AP =");
    
        for ( int i = 1 ; i<= n ; i++)
        {
            printf(" %d,",ap);
        
            ap+=r;
        }
    
        printf("\n");
    
        printf("GP =");
    
        for( int i = 1; i <= n ; i++)
        {
            printf(" %d,",gp);
            gp *= r;
        }
    
        printf("\n");
    
        ap = a;
    
        printf("HP =");
        for ( int i = 1; i <= n ; i++)
        {
            printf(" %f,",(float)1/ap);
        
            ap+=r;
        }
    
        printf("\n");
    
        }
}
