#include <stdio.h>
#include <string.h>

struct employee
{
    int id;
    char name[15];
    char email[30];
    float salary;
};

/* read function */

void read(struct employee* str , int n )
{
    printf("Enter the employee details👇🏻\n");
    printf("\n");
    for ( int i = 0 ; i < n ; i++ )
    {
        printf("No.%d",i+1);
        printf("\n");
        printf("Enter employee ID     🔰: ");
        scanf("%d",&str[i].id);
        printf("Enter employee name 👨🏻: ");
        scanf("%s",str[i].name);
        printf("Enter employee email  📩: ");
        scanf(" %[^\n]",str[i].email);
        printf("Enter employee salary 💰: ");
        scanf("%f",&str[i].salary);
        printf("\n");
    }
}

/* write function */

void write(struct employee* str, int n)
{
    printf("-----------------------------------------\n");

    for ( int i = 0 ; i < n ; i++ )
    {
        printf("EMPLOYEE ID    🔰 : %d\n",str[i].id);
        printf("EMPLOYEE NAME 👨🏻: %s\n",str[i].name);
        printf("EMPLOYEE EMAIL  📩: %s\n",str[i].email);
        printf("EMPLOYEE SALARY 💰: %g\n",str[i].salary);
        printf("\n");
    }
}

/* id search function */
void idsearch ( struct employee* str , int n , int find )
{
    int i;
    int flag = 0;
    for (  i = 0 ; i < n ; i++ )
    {
        if ( str[i].id == find )
        {
            flag = 1;
            break;
        }
    }
    if ( flag == 0 )
    {
        printf("-----------------------------------------\n");
        printf("❌ INVALID ! THERES NO ID ❌\n");
        return;
    }
    printf("\n");
    printf("-----------------------------------------\n");
    printf("FOUNDED ✅\n");
    printf("\n");
    printf("EMPLOYEE ID    🔰: %d \n",find);
    printf("EMPLOYEE NAME👨🏻: %s\n",str[i].name);
    printf("EMAIL ADDRESS   📩: %s\n",str[i].email);
    printf("EMPLOYEE SALARY 💰: %g\n",str[i].salary);
}

void compare (  struct employee* str , int n , char* namefind )
{
    int flag = 0;
    int i ;

    for (  i = 0 ; i <  n ; i++ )
    {
        if( strcmp(str[i].name,namefind)==0 )
        {
            flag = 1;
            break;
        }
    }

    if ( flag == 0 )
    {
        printf("❌ Invalid This Name is Not Present ❌\n");
    }
    else
    {

        printf("\n");
        printf("-----------------------------------------\n");
        printf("FOUNDED ✅\n");
        printf("\n");
        printf("EMPLOYEE  %s  DETAILS:\n",namefind);
        printf("EMPLOYEE NAME 👨🏻: %s\n",str[i].name);
        printf("EMPLOYEE ID     🔰: %d\n",str[i].id);
        printf("EMAIL ADDRESS   📩: %s\n",str[i].email);
        printf("EMPLOYEE SALARY 💰: %g\n",str[i].salary);
    }
}


int main()
{
    int n;
    int m1 , m2;
    printf("Enter the number of employees 👥 : ");
    scanf("%d",&n);
    printf("\n");
    struct employee str[n]; //declaring an var 
    read(str,n);

    printf("-----------------------------------------\n");
    printf("-----------------MENU--------------------\n");
    while(1)
    {
    printf("-----------------------------------------\n");
        printf("\n");
        printf("1) Print all  employees info 📜 \n");
        printf("2) Find employee through particular info🧐\n");
        printf("3) EXIT 🚪 \n");
        printf("Choose any one option❓: ");
        scanf("%d",&m1);
        if(m1 == 1 )
        {
            write(str,n);
        }
        else if ( m1 == 2 )
        {
            while(1)
            {

                printf("\n");
                printf("-----------------SUB MENU----------------\n");
                printf("1) Seach by ID 🔎\n");
                printf("2) Search by name 🔎 \n");
                printf("3) Go Back 🔙  \n");
                printf("4) EXIT! 🚪 \n");
                printf("Choose an option❓: ");
                scanf("%d",&m2);
                printf("\n");

                if ( m2 == 1 )
                {
                    int find;
                    printf("-----------------------------------------\n");
                    printf("Enter the ID to Search 🔎 : ");
                    scanf("%d",&find);
                    idsearch(str,n,find);
                }
                else if ( m2 == 2 )
                {
                    char namefind[20];
                    printf("-----------------------------------------\n");
                    printf("Enter the Name of the employee❓: ");
                    scanf("%s",namefind);
                    compare(str,n,namefind);
                }
                else if ( m2 == 3 )
                {
                    break;
                }
                else if ( m2 == 4 )
                {
                    return 0;
                }
                else
                {
                    printf("-----------------------------------------\n");

                    printf("❌ INVALID !\n");
                }

            }

        }
        else if ( m1 == 3 )
        {
            return 0;
        }
        else
        {

            printf("-----------------------------------------\n");
            printf("❌ INVALID ! ❌\n");
        }
    }
}
