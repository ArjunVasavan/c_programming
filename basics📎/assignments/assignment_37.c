#include <stdio.h>
int replace_nbits_from_pos(int num,int a,int b,int value)
{
  // num = 11;
  // a = 3;
  // b = 5;
  // value = 174;


  int n = ((b - a) + 1); // which is the formula

  int mask = ( (( 1 << n ) - 1 ) );
  mask = ~(mask << a) ;
  value = (value & mask);

  mask = ( (1 << n )-1 ) ;
  num = ( num & mask); 

  num = (num << a); // so what  mistake i done here is that i left shifted before
  // so what heppens here is eg: 11111000 => 1000 0111 this is what i expected but
  // when i left shift early it goes as 1100 0000 because of that i fucking wasted 1 hour
  // so first 0000 0111 this number should be left shifted like 0111 0000 and after only that 
  // use compliment or else youll waste your fucking time

  value = (value | num);



  return value;

}
int main()
{
  int num,a,b,value;

  printf("Enter the number : ");
  scanf("%d",&num);
  printf("Enter the 'a' : ");
  scanf("%d",&a);
  printf("Enter the 'b' : ");
  scanf("%d",&b);
  printf("Enter the value : ");
  scanf("%d",&value);


  printf("RESULT : %d\n",replace_nbits_from_pos(num,a,b,value));

}
