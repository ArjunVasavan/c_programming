/* 
-------------------------------------------------------------------------------
Name        : Arjun Vasavan

Date        : 27 - 10 - 2025

Description : Provide a menu to manipulate or display the value of variable of 
              type t

Sample execution : 

Menu : 
1. Add elements
2. Remove elements
3. Display elements
4. Exit from the program
Choice =>> 1

Enter the type you have to insert:
1. int
2. char
3. short
4. double
Choice =>> 1
Enter the integer you want to add : 
[4] =>> 67
------------Successfully added the element------------
Menu : 
1. Add elements
2. Remove elements
3. Display elements
4. Exit from the program
Choice =>> 1

Enter the type you have to insert:
1. int
2. char
3. short
4. double
Choice =>> 2
Which Character you want to add ? 
1. character_1 
2. character_2 
Choice =>> 1
Enter the character 1 : 
[0] =>> A
------------Successfully added the element------------
Menu : 
1. Add elements
2. Remove elements
3. Display elements
4. Exit from the program
Choice =>> 1

Enter the type you have to insert:
1. int
2. char
3. short
4. double
Choice =>> 2
Which Character you want to add ? 
1. character_1 
2. character_2 
Choice =>> 2
Enter the character 2 : 
[1] =>> R
------------Successfully added the element------------
Menu : 
1. Add elements
2. Remove elements
3. Display elements
4. Exit from the program
Choice =>> 1

Enter the type you have to insert:
1. int
2. char
3. short
4. double
Choice =>> 3
Enter the short : 
[2] =>> 5
------------Successfully added the element------------
Menu : 
1. Add elements
2. Remove elements
3. Display elements
4. Exit from the program
Choice =>> 3
[0] =>> A
[1] =>> R
[2] =>> 5
[4] =>> 67
Menu : 
1. Add elements
2. Remove elements
3. Display elements
4. Exit from the program
Choice =>> 2
0 -> A
1 -> R
2 -> 5
4 -> 67
Enter the index value to be deleted: 2
Index 2 successfully deleted.
Menu : 
1. Add elements
2. Remove elements
3. Display elements
4. Exit from the program
Choice =>> 1

Enter the type you have to insert:
1. int
2. char
3. short
4. double
Choice =>> 1
-----This particular memory is already allocated------

Menu : 
1. Add elements
2. Remove elements
3. Display elements
4. Exit from the program
Choice =>> 4

[Process exited 0]

-------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
int flags[5] = {0}; // flag structure  [char1][char2][short][int][double]
                    //                 [  0  ][  1  ][  2  ][ 3 ][  4   ] 
int add_element_function(void *pointer,int choice,int* flags);

int main()
{
  int  choice = 0;
  void* pointer = malloc(8); // creating an 8 byte memory
  do           
  {
    printf("Menu : \n");
    printf("1. Add elements\n");
    printf("2. Remove elements\n");
    printf("3. Display elements\n");
    printf("4. Exit from the program\n");
    printf("Choice =>> ");
    scanf("%d",&choice);

    switch (choice) 
    {
      case 1:
        {
          printf("\nEnter the type you have to insert:\n");
          printf("1. int\n");
          printf("2. char\n");
          printf("3. short\n");
          printf("4. double\n");
          printf("Choice =>> ");
          scanf("%d",&choice);

          if(add_element_function(pointer,choice,flags) == 0)
          {
            printf("-----This particular memory is already allocated------\n");
            printf("\n");
          }
          else 
          {
          
            printf("------------Successfully added the element------------\n");
          }
          break;
        }
      case 2:
        {
          // Display current elements with their indices
          int has_elements = 0;
          
          if ( flags[0] == 1 )
          {
            printf("%d -> %c\n", 0, *((char*)pointer));
            has_elements = 1;
          }
          if ( flags[1] == 1 )
          {
            printf("%d -> %c\n", 1, *((char*)pointer+1));
            has_elements = 1;
          }
          if ( flags[2] == 1 )
          {
            printf("%d -> %hd\n", 2, *((short*)((char*)pointer+2)));
            has_elements = 1;
          }
          if ( flags[3] == 1 )
          {
            printf("%d -> %d\n", 4, *((int*)((char*)pointer+4)));
            has_elements = 1;
          }
          if ( flags[4] == 1 )
          {
            printf("%d -> %lf\n", 0, *((double*)pointer));
            has_elements = 1;
          }

          if (!has_elements)
          {
            printf("No elements to delete!\n");
            break;
          }

          printf("Enter the index value to be deleted: ");
          int index;
          scanf("%d", &index);

          // Delete based on index
          if (index == 0 && flags[0] == 1)
          {
            flags[0] = 0;
            printf("Index %d successfully deleted.\n", index);
          }
          else if (index == 1 && flags[1] == 1)
          {
            flags[1] = 0;
            printf("Index %d successfully deleted.\n", index);
          }
          else if (index == 2 && flags[2] == 1)
          {
            flags[2] = 0;
            printf("Index %d successfully deleted.\n", index);
          }
          else if (index == 4 && flags[3] == 1)
          {
            flags[3] = 0;
            printf("Index %d successfully deleted.\n", index);
          }
          else if (index == 0 && flags[4] == 1)
          {
            flags[4] = 0;
            printf("Index %d successfully deleted.\n", index);
          }
          else
          {
            printf("Error: Index %d not found or already empty!\n", index);
          }

          break;
        }
      case 3: 
        // here each printing will be shown on where the memory starts 
        // from that pointer memory
        {
          if ( flags[0] == 1 )
          {
            printf("[%d] =>> %c\n",0,*((char*)pointer));
          }
          if ( flags[1] == 1 )
          {
            printf("[%d] =>> %c\n",1,*((char*)pointer+1));
          }
          if ( flags[2] == 1 )
          {
            printf("[%d] =>> %hd\n",2,*((short*)((char*)pointer+2)));
          }
          if ( flags[3] == 1 )
          {
            printf("[%d] =>> %d\n",4,*((int*)((char*)pointer+4)));
          }
          if ( flags[4] == 1 )
          {
            printf("[%d] =>> %lf\n",0,*((double*)pointer));
          }
          break;
        }

    }

  }while ( choice != 4 );
  
  free(pointer);
  return 0;
}

int add_element_function(void *pointer,int choice,int* flags)
{
  switch (choice) 
  {
    case 1:
      {
        if ( flags[3] == 1 ) return 0;
        printf("Enter the integer you want to add : \n");
        printf("[%d] =>> ",4);
        scanf("%d",(int*)((char*)pointer+4));
        flags[3] = 1;
        break;
      }
    case 2:
      {
        printf("Which Character you want to add ? \n");
        printf("1. character_1 \n");
        printf("2. character_2 \n");
        printf("Choice =>> ");
        scanf("%d",&choice);

        if ( choice == 1 )
        {
          if ( flags[0] == 1 ) return 0;
          printf("Enter the character 1 : \n");
          printf("[%d] =>> ",0);
          scanf(" %c",(char*)pointer);
          flags[0] = 1;
        }

        if ( choice == 2 )
        {
          if ( flags[1] == 1 ) return 0;
          printf("Enter the character 2 : \n");
          printf("[%d] =>> ",1);
          scanf(" %c",(char*)(pointer+1));
          flags[1] = 1;
        }
        break;
      }
    case 3:
      {
        if ( flags[2] == 1) return 0;

        printf("Enter the short : \n");
        printf("[%d] =>> ",2);
        scanf("%hd",(short*)((char*)pointer+2));
        flags[2] = 1;

        break;
      }
    case 4:
      {
        for ( int i = 0 ; i < 5 ; i++ )
        {
          if ( flags[i] == 1 )
          {
            return 0;
          }
        }
        printf("Enter the double : \n");
        printf("[%d] =>> ",0);
        scanf("%lf",(double*)pointer);
        flags[4] = 1;
        break;
      }
  }

  return 1;
}
