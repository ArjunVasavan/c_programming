#include<stdio.h>
#include<ctype.h>

void wc_count(int *char_count,int *word_count, int *line_count)
{
     int ch;

     int backup = 0;
      if((ch = getchar()) != EOF)
      {
          (*char_count)++;

          if(ch == '\n')
          {
              (*line_count)++;
          }
          else if( isspace(ch) )
          {
              backup = 0;
          }
          else if ( backup == 0)
          {

              (*word_count)++;
              backup = 1;
          }
      }
}
int main()
{

    int char_count = 0, word_count = 0, line_count = 0;

    wc_count(&char_count,&word_count,&line_count);

    printf("Character count : %d\n",char_count);
    printf("Line count : %d\n",line_count);
    printf("Word count : %d\n",word_count);

    return 0;

}
