#include <stdio.h>

int replace_nbits_from_pos(int, int, int, int);

int main()
{
    int num, a, b, val, res = 0;
    
    printf("Enter num, a, b, and val:");
    scanf("%d%d%d%d", &num, &a, &b, &val);
    
    res = replace_nbits_from_pos(num, a, b, val);
    
    printf("Result = %d\n", res);
}

int replace_nbits_from_pos(int num, int a, int b , int val )
{
  return ( ( val &  ( ~ ( ( (1 << (b - a + 1 ) ) - 1 ) << a ) ) ) | ( ( num & ( ( 1 << (b - a + 1)); 
}
