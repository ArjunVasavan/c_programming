// Write a program that:
//
// Keeps reading characters from the user until # is typed.
//
// While reading, it should count how many vowels (a, e, i, o, u in both cases) were typed.
//
// At the end, it should print the total count of vowels.
#include<stdio.h>
int main()
{
  int ch;

  printf("Enter character (small letter only) and it will stop when you write # : ");
  int count = 0;
  while ( ( ch = getchar() ) != '#' )
  {
    if ( ch == 'a' || ch == 'i' || ch == 'o' || ch == 'u')
    {
      count+=1;
    }
  }

  printf("result =>> %d\n",count);
}
