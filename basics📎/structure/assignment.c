/*
--------------------------------------------------------------------------------  

Name        : Arjun Vasavan

Date        : 21 - 10 - 2025

Description : Program to Implement the student record using array of structures


Sample Execution : 

Enter the number of Students : 2
Enter the number of subjects : 2
Enter the name of subject 1 : Maths
Enter the name of subject 2 : Physics
---------------------Enter the student details----------------------------------
Enter the student Roll no.: 1
Enter the student 1 name : Arjun
Enter Maths marks : 80
Enter Physics marks : 78
---------------------Enter the student details----------------------------------
Enter the student Roll no.: 2
Enter the student 2 name : Karthik
Enter Maths marks : 78
Enter Physics marks : 65

--------------------------DISPLAY MENU------------------------------------------
1.All student details
2.Particular student details 
3.Exit
1
Roll No.  Name      Maths     Physics   Average   Grade     
1         Arjun     80        78        79        B         
2         Karthik   78        65        71        B         

--------------------------DISPLAY MENU------------------------------------------
1.All student details
2.Particular student details 
3.Exit
2

------------------Menu for Particular students----------------------------------
1.Name
2.Roll No.
Enter your choice : 2
Enter the roll number of Student : 1
Roll No.  Name      Maths     Physics   Average   Grade     
1         Arjun     80        78        79        B         

--------------------------DISPLAY MENU------------------------------------------
1.All student details
2.Particular student details 
3.Exit
3
------------------You Have Successfully Exited----------------------------------


--------------------------------------------------------------------------------  
*/
#include <stdio.h>
#include <strings.h>

struct db 
{
  char name[20];
  int rollno;

};

char grade_check(int average)
{
  if ( average >= 90 && average <= 100 )
  {
    return 'A';
  }
  else if (average >= 70 && average < 90 )
  {
    return 'B';
  }
  else if ( average >= 60 && average < 70 ) 
  {
    return 'C';
  }
  else if ( average >= 40 && average < 60 )
  {
    return 'D';
  }
  return 'F';
}

void all (struct db* database,int numberofsubjects,int students,int marks[students][numberofsubjects],char subjects[numberofsubjects][20])
{
  printf("%-10s%-10s","Roll No.","Name");

  for ( int i = 0 ; i < numberofsubjects ; i++ )
  {
    printf("%-10s",subjects[i]);
  }
  printf("%-10s%-10s","Average","Grade");
  printf("\n");
  for ( int i = 0 ; i < students ; i++ )
  {
    int average = 0;
    printf("%-10d%-10s",database[i].rollno,database[i].name);
    for ( int j = 0 ; j < numberofsubjects ; j++ )
    {
      average+=(marks[i][j]);
      printf("%-10d",marks[i][j]);
    }

    printf("%-10d%-10c",average/numberofsubjects,grade_check(average/numberofsubjects));

    printf("\n");
  }
}


void particular (struct db* database,int numberofsubjects,int students,int marks[students][numberofsubjects],char subjects[numberofsubjects][20])
{

  printf("\n------------------Menu for Particular students---------------------\n");

  printf("1.Name\n");
  printf("2.Roll No.\n");

  int choice;

  printf("Enter your choice : ");
  scanf("%d",&choice);

  switch (choice) 
  {
    case 1:
      {

        char find[20];
        printf("Enter the name of the Student : ");
        getchar();
        scanf("%[^\n]",find);

        for ( int i = 0 ; i < students ; i++ )
        {
          if ( strcasecmp(find,database[i].name) == 0 )
          {
            printf("%-10s%-10s","Roll No.","Name");

            for ( int i = 0 ; i < numberofsubjects ; i++ )
            {
              printf("%-10s",subjects[i]);
            }
            printf("%-10s%-10s","Average","Grade");
            printf("\n");
            int average = 0;
            printf("%-10d%-10s",database[i].rollno,database[i].name);
            for ( int j = 0 ; j < numberofsubjects ; j++ )
            {
              average+=(marks[i][j]);
              printf("%-10d",marks[i][j]);
            }

            printf("%-10d%-10c",average/numberofsubjects,grade_check(average));

            printf("\n");

          }
        }

        break;
      }
    case 2:
      {

        printf("Enter the roll number of Student : ");
        int find;
        scanf("%d",&find);

        for ( int i = 0 ; i < students ; i++ )
        {
          if ( database[i].rollno == find )
          {
            printf("%-10s%-10s","Roll No.","Name");

            for ( int i = 0 ; i < numberofsubjects ; i++ )
            {
              printf("%-10s",subjects[i]);
            }
            printf("%-10s%-10s","Average","Grade");
            printf("\n");
            int average = 0;
            printf("%-10d%-10s",database[i].rollno,database[i].name);
            for ( int j = 0 ; j < numberofsubjects ; j++ )
            {
              average+=(marks[i][j]);
              printf("%-10d",marks[i][j]);
            }

            printf("%-10d%-10c",average/numberofsubjects,grade_check(average));
            printf("\n");

          }
        }

        break;
      }
    default:
      {
        printf("Error !\n");
      }
  
  }

}


int main()
{

  int students;
  int numberofsubjects;

  printf("Enter the number of Students : ");
  scanf("%d",&students);
  struct db database[students];

  printf("Enter the number of subjects : ");
  scanf("%d",&numberofsubjects);

  char subjects[numberofsubjects][20];

  for ( int i = 0 ; i < numberofsubjects ; i++ )
  {
    printf("Enter the name of subject %d : ",i+1);
    scanf("%s",subjects[i]);
  }

  int marks[students][numberofsubjects];

  for ( int i = 0 ; i < students ; i++ )
  {
    printf("---------------------Enter the student details---------------------\n");
    printf("Enter the student Roll no.: ");
    scanf("%d",&database[i].rollno);

    printf("Enter the student %d name : ",database[i].rollno);
    getchar();
    scanf("%[^\n]",database[i].name);

    for ( int j = 0 ; j < numberofsubjects ; j++ )
    {
      printf("Enter %s marks : ",subjects[j]);
      scanf("%d",&marks[i][j]);
    }
  }


  int choice;

  do 
  {
    printf("\n--------------------------DISPLAY MENU---------------------------\n");

    printf("1.All student details\n");
    printf("2.Particular student details \n");
    printf("3.Exit\n");

    scanf("%d",&choice);

    switch (choice) {

      case 1:
      {

          all(database,numberofsubjects,students,marks,subjects);
          break;
      }
      case 2:
      {

          particular(database,numberofsubjects,students,marks,subjects);
          break;
      }
      case 3:
      {
          
          printf("------------------You Have Successfully Exited---------------\n");
      }
    
    }

  }while( choice != 3 );

}
