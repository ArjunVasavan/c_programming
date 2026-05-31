/*
-------------------------------------------------------------------------------

Name : Arjun Vasavan

Date : 06 - 10 - 2025

Description : Program to practise signed and unsigned right shift.


Sample execution : 


Enter the number for signed variable : -56

Enter the number of shifts to be performed : 5

After performing signed right shift : -2

Enter the number for unsigned number : -56

Enter the number of shifts to be performed : 5

After performing unsigned right shift : 134217726



-------------------------------------------------------------------------------
*/
#include<stdio.h>
#define RIGHTSHIFT(num,shifts) num = (( num ) >> ( shifts ))// function like or
//                                                          Argument like MACRO
int main()
{
  printf("Enter the number for signed variable : ");
  int snum; //signed number variable
  scanf("%d",&snum);

  printf("Enter the number of shifts to be performed : ");
  int shifts;
  scanf("%d",&shifts);

  printf("After performing signed right shift : %d \n",RIGHTSHIFT(snum,shifts));

  printf("Enter the number for unsigned variable : ");
  unsigned int unum;
  scanf("%d",&unum); //unsigned number variable

  printf("Enter the number of shifts to be performed : ");
  scanf("%d",&shifts);

  printf("After performing signed right shift : %d \n",RIGHTSHIFT(unum,shifts));

}

