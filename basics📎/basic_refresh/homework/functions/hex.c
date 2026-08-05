#include <stdio.h>
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

int main()
{
    int n = 5;

    printf("Enter an Decimal value : ");
    scanf("%d",&n);
    hex(n);
}

