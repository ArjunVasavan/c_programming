/*
-------------------------------------------------------------------------------
Name        : Arjun Vasavan

Date        : 26 - 10 - 2025

Description : Read n & n person names of maxlen 20. Sort and print the names 

Sample execution: -

Test Case 1:

Enter the size: 5
Enter the 5 names of length max 20 characters in each
[0] -> Delhi
[1] -> Agra
[2] -> Kolkata
[3] -> Bengaluru
[4] -> Chennai

The sorted names are:

Agra
Bengaluru
Chennai
Delhi
Kolkata
-------------------------------------------------------------------------------
*/
#include <stdlib.h>
#include <stdio.h>

void read(int size, char arr[size][20]) // this function is to read
{
  for (int i = 0; i < size; i++)
  {
    printf("[%d] -> ", i);
    scanf("%19s", arr[i]); // read space-separated strings
  }
}

void write(int size, char arr[size][20]) // this is to print the output
{
  for (int i = 0; i < size; i++)
  {
    printf("%s\n", arr[i]);
  }
}

int my_strcmp(const char *str1, const char *str2) // this is to compare
{
  int i = 0;
  while (str1[i] == str2[i] && str1[i] != '\0') 
  {
    i += 1;
  }
  return str1[i] - str2[i];
}

void my_strcpy(char *str1, const char *str2) // for copying strings
{
  int i = 0;
  while (str2[i] != '\0')
  {
    str1[i] = str2[i];
    i += 1;
  }
  str1[i] = '\0';
}

void sort_names(char (*arr)[20], int size) // using bubble sort logic here
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (my_strcmp(arr[j], arr[j + 1]) > 0)
      {
        char temp[20];
        my_strcpy(temp, arr[j]);
        my_strcpy(arr[j], arr[j + 1]);
        my_strcpy(arr[j + 1], temp);
      }
    }
  }
}

int main()
{
  int size;
  printf("Enter the size: ");
  scanf("%d", &size);
  printf("Enter the %d names of length max 20 characters in each\n", size);
  char(*arr)[20] = malloc(size * sizeof(char[20])); // pointer to an array
  
  read(size, arr);
  sort_names(arr, size);
  
  printf("The sorted names are:\n"); 
  write(size, arr);
  
  free(arr); //  Free allocated memory
  
  return 0;
}
