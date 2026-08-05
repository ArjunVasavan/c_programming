#include <stdio.h>

int replace_nbits_from_pos(int, int, int, int);

int main()
{
    int num, a, b, val, res = 0;
    
    printf("Enter num, a, b, and val:\n");
    scanf("%d%d%d%d", &num, &a, &b, &val);
    
    res = replace_nbits_from_pos(num, a, b, val);
    
    printf("Result = %d\n", res);
}

int replace_nbits_from_pos(int num, int a, int b, int val)
{
    int gap = (b - a + 1);
    int lsb = num & ((1 << gap) - 1);
    lsb = lsb << a;
    
    int mask = ((1 << gap) - 1) << a;
    val = val & (~mask);
    
    val = (val | lsb);
    
    return val;
}
