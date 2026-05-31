#include<stdio.h>
int main()
{
  printf("Enter The Num Value : ");
  int num;
  scanf("%d",&num);
  printf("Enter the 'm' value : ");
  int m;
  scanf("%d",&m);
  printf("Enter the 'n' value : ");
  int n;
  scanf("%d",&n);

  int val = num;
  val =  val & ( 1 << m);

  printf("When Getting M value : %d\n",val);

  val = val >> m;

  printf("M value on LSB is : %d\n",val);

  if ( val == 1 )
  {
    num = num & (~(1 << n));
  }

  printf("Num Value is : %d\n",num);
}
