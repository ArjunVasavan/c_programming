/* 

Name        : Arjun Vasavan

Start Date  : 21-07-2025

End Date    : 21-07-2025

Description : Suppose, in a week let us assume first day is 'Sunday',
then second day will be 'Monday' and so on. If first day is 'Monday' then
the second day will be 'Tuesday' and so on.

Pre-requisites : Arithmetic Operators, Switch Case

Sample Input and Output :

Test Case 1 :

Enter the value of 'n' : 6
Choose First Day :
1. Sunday
2. Monday
3. Tuesday
4. Wednesday
5. Thursday
6. Friday
7. Saturday
Enter the option to set the first day : 3
The day is Sunday

Test Case 2 :

Enter the value of 'n' : 1
Choose First Day :
1. Sunday
2. Monday
3. Tuesday
4. Wednesday
5. Thursday
6. Friday
7. Saturday
Enter the option to set the first day : 7
The day is Saturday

Test Case 3 :

Enter the value of 'n' : 9
Choose First Day :
1. Sunday
2. Monday
3. Tuesday
4. Wednesday
5. Thursday
6. Friday
7. Saturday
Enter the option to set the first day : 8
Error : Invalid Input, first day should  be > 0 and <= 7

Test Case 4 :

Enter the value of 'n' : 0
Error: Invalid Input, n value should be > 0 and <= 365

Test Case 5 :

Enter the value of 'n' : 370
Error: Invalid Input, n value should be > 0 and <= 365

*/
#include <stdio.h>

int main()
{
    int start_day , n , result ;
    
    printf("Enter the value of 'n' : ");
    
    scanf("%d",&n);
    
    printf("Choose First Day : \n 1. Sunday \n 2. Monday \n 3. Tuesday \n 4. Wednesday \n 5. Thursday \n 6.  Friday \n 7. Saturday \n");
    
    printf("Enter the option to set the first day : ");
    scanf("%d",&start_day);
    
    if (n > 0 && n <= 365)
    {
        if (start_day > 0 && start_day <= 7)
        {
            result = ( ( start_day + ( n - 1 ) ) % 7 );
        
            switch ( result )
            {
                case 0 :
                    
                        printf("The day is Saturday");
                        break;
            
                case 1 :
                    
                        printf("The day is Sunday");
                        break;
            
                case 2 :
                    
                        printf("The day is Monday");
                        break;
            
                case 3 :
                    
                        printf("The day is Tuesday");
                        break;
                    
                case 4 :
            
                        printf("The day is Wednesday");
                        break;
                    
                case 5 :
            
                        printf("The day is Thursday");
                        break;
                    
                case 6 :
            
                        printf("The day is Friday");
                        break;
    
            }
            
        }
        
        else
        {
            printf("Error: Invalid input, first day should be > 0 and <= 7");
        }
    }
    
    else
    {
        printf("Error: Invalid Input, n value should be > 0 and <= 365 ");
        return 0;
        
    }
}
