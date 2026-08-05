#include <stdio.h>
void bin (int a)
{
    if (a > 1)
    {
        bin(a/2);
    printf("%d",a%2);
    }
    else
    {
        printf("1");
    }

}

void hex (int a)
{
    int check;
    if (a >= 1)
    {
        hex(a/16);

        check = a % 16;
        switch(check)
        {
            case 10:
                {
                    printf("A");
                    break;
                }
            case 11:
                {
                    printf("B");
                    break;
                }
            case 12:
                {
                    printf("C");
                    break;
                }
            case 13:
                {
                    printf("D");
                    break;
                }
            case 14:
                {
                    printf("E");
                    break;
                }
            case 15:
                {
                    printf("F");
                    break;
                }

            default:
                {
                    printf("%d",check);
                }
        }

    }
    else
    {
        printf("0x");
    }

}
void oct (int a)
{
    if (a >= 1)
    {
        oct(a/8);
    printf("%d",a%8);
    }
    else
    {
        printf("0");
    }

}


int main()
{
    int n = 5;
    int c = 0;
    printf("\n");
    printf("Enter What Type of Conversion You Need :\n 1. Binary \n 2.Octal \n 3. Hexadecimal\n");
    printf("Enter 1 or 2 or 3 --> : ");
    scanf("%d",&c);
    printf("\n");
    printf("Enter an Decimal value : ");
    scanf("%d",&n);
    printf("\n");
    switch(c)
    {
        case 1 :
            {
                printf("Converted to binary as --> :");
                printf("0b");
                bin(n);
                printf("\n");
                break;
            }
        case 2 :
            {
                printf("Converted to Octal as --> :");
                oct(n);
                printf("\n");
                break;
            }
        case 3 :
            {
                printf("Converted to Hexadecimal as --> :");
                hex(n);
                printf("\n");
                break;
            }
        default :
            {
                printf("ENTER AN VALID OPTION (1,2,3)\n");
            }
    }



    printf("\n");

}

