#include<stdio.h> 

int main() 
{   int n = 4; 
    for ( int i = 1 ; i <= n ; i++ ) 
    { 
        for ( int j = 1 ; j <= n ; j++ ) 
        {
            if (i + j >= n +1 )  
            {
                printf("*");
            } 
            else
            { 
                printf(" "); 
            }
        } 
        if ( i != 1 ) 
            { 
                for ( int j = 1 ; j<= n - 1 ; j++) 
                {
                    if ( i - 1 >= j ) 
                    { 
                        printf("*"); 
                    }  
                    else
                    {  printf(" ");  
                    }  
                }  
            } 
        printf("\n");
    }

}
