#include<stdio.h>

struct bill 
{
  int si;
  char name[20];
  int qty;
  float price;
  float cost;
  float amount;
};

int main()
{
  int n;

  printf("Enter the number of groceries : ");
  scanf("%d",&n);
  printf("\f");
  struct bill store[n];

  for ( int  i = 0 ; i < n ; i++ )
  {
    printf("Enter Name of Product : ");
    scanf(" %[^\n]",store[i].name);
    printf("Enter Quantity : ");
    scanf(" %d",&store[i].qty);
    printf("Enter the Price : ");
    scanf(" %f",&store[i].price);
    printf("\f");
    store[i].cost = (store[i].price) * (store[i].qty);

  }
  
  printf("\f");

  int i, j;
  for (i = 0; i <= 100; i++) {
    printf("\rLoading: [");
    for (int k = 0; k < i; k++) printf("#");
    for (int k = i; k < 100; k++) printf(" ");
    printf("] %d%%", i);
    for (j = 0; j < 100000000; j++);
  }
  for (j = 0; j < 100000000; j++);
  printf("\n \t \t \t \t \t  \t  Completed Successfully!\n");


  printf("\f");


  printf("============================BILL============================\n");
  printf("Si.No\t|\tName\t|\tPrice\t|\tQty\n");
  for ( int i = 0 ; i < n ; i ++ )
  {
    printf("%-d\t|\t%s\t|\t%.2f\t|\t%d\n",i,store[i].name,store[i].price,store[i].qty);
  }

  printf("============================================================\n");

  float amount = 0;

  for ( int i = 0 ; i < n ; i++ )
  {
    amount+=store[i].cost;
  }
  printf("TOTAL AMOUNT : %.2f\n",amount);

  printf("============================================================\n");
}
