#include<stdio.h>
nt main()
{const char a[] = "%c";
  int x = 0;
  int *ptr = &x;
  scanf(a, ptr);
  *ptr = 'a';
  printf("%d\n", x);
}
