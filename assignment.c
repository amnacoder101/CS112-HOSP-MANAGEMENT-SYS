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
  int patientCount;

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
            break;}
    }while(choose!=7);
    return 0;}

void updatepatient(){
    int id, index;
    printf("Enter Patient ID to update: ");
    scanf("%d", &id);
    index = findpatient(id);
    if (index == -1){
        printf("Patient not found!\n");
    }
    else{
        printf("\nEnter new patient information:\n");
        printf("Enter new name: ");
        scanf(" %[^\n]", patients[index].name);
        printf("Enter new age: ");
        scanf("%d", &patients[index].age);
        printf("Enter new gender: ");
        scanf(" %[^\n]", patients[index].gender);
        printf("Enter new disease: ");
        scanf(" %[^\n]", patients[index].disease);
        printf("Enter new phone number: ");
        scanf(" %[^\n]", patients[index].phone);
        printf("\nPatient updated successfully!\n");
 saverecords();
    }
}
void deletepatient(){
    int id, index, i;
    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);
    index = findpatient(id);
    if (index == -1){
        printf("Patient not found!\n");
    }
    else{
        for (i = index; i < patientCount - 1; i++) { 
            patients[i] = patients[i + 1];
        }
        patientCount--;
        printf("\nPatient deleted successfully!\n");
        saverecords();
    }
}
void saverecords(){
    FILE *fp;
    int i;
    fp = fopen("patients.dat", "wb");
    if (fp == NULL){
        printf("Error opening file!\n");
        return;
    }
    for (i = 0; i < patientCount; i++){ 
        fwrite(&patients[i], sizeof(struct Patient), 1, fp);
    }
  fclose(fp);
 printf("\nRecords saved successfully!\n");
}
void loadrecords(){
    FILE *fp;
    fp = fopen("patients.dat", "rb");
    if (fp == NULL)
    { patientCount = 0;
        return;
    }
    patientCount = 0;
    while (patientCount < 50 && fread(&patients[patientCount],sizeof(struct Patient), 1, fp) == 1) 
{  patientCount++;
    }
    fclose(fp);
    printf("%d records loaded successfully!\n", patientCount);
}