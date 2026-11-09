#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Patient
{ int id,age;
  char name[40];
  char disease[50];
  char phone[20];
  char gender[10];  };
  struct Patient patients[50];
  void addpatient();
  void displaypatient();
  void searchpatient();
  void updatepatient();
  void deletepatient();
  void saverecords();
  void loadrecords();
  int findpatient(int id);
  int readinteger(char message[],int min,int max);
  void readtext(char message[],char text[],int size);

  int main()
  { 
    int choose;
    loadrecords();
    printf("'HOSPITAL MANAGEMENT SYSTEM'");
    do{
        printf("===Main Menu===");
        printf("Add new patient\n");
        printf("Display all patients\n");
        printf("Search patient\n");
        printf("Update patient\n");
        printf("Delete patient\n");
        printf("Save records\n");
        printf("Exit\n");
        choose=readinteger("enter your choice:",1,7);
        switch(choose)
        {
            case 1:
            addpatient();
            break;
            case 2:
            displaypatient();
            break;
            case 3:
            searchpatient();
            break;
            case 4:
            updatepatient();
            break;
            case 5:
            deletepatient();
            break;
            case 6:
            saverecords();
            break;
            case 7:
            printf("The program has been exited!");
            break;
        }
    }while(choose!=7);
    return 0;
  }
