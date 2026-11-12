#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
struct Patient
{
    int id, age;
    char name[40];
    char disease[50];
    char phone[20];
    char gender[10];
};
struct Patient patients[MAX];
int patientCount;
void addpatient();
void displaypatient();
void searchpatient();
void updatepatient();
void deletepatient();
void saverecords();
void loadrecords();
int findpatient(int id);
int readinteger(char message[], int min, int max);
void readtext(char message[], char text[], int size);
int main()
{
    int choose;
    loadrecords();
    printf("HOSPITAL MANAGEMENT SYSTEM\n");
    do {
        printf("\n===Main Menu===\n");
        printf("1. Add new patient\n");
        printf("2. Display all patients\n");
        printf("3. Search patient\n");
        printf("4. Update patient\n");
        printf("5. Delete patient\n");
        printf("6. Save records\n");
        printf("7. Exit\n");
        choose = readinteger("Enter your choice: ", 1, 7);
        switch (choose)
        {
            case 1: addpatient();     break;
            case 2: displaypatient(); break;
            case 3: searchpatient();  break;
            case 4: updatepatient();  break;
            case 5: deletepatient();  break;
            case 6: saverecords();    break;
            case 7: printf("The program has been exited!\n"); break;
        }
    } while (choose != 7);
    return 0;
}
int findpatient(int id)
{
    int i;
    for (i = 0; i < patientCount; i++)
        if (patients[i].id == id)
            return i;
    return -1;
}
int readinteger(char message[], int min, int max)
{
    int v;
    do {
        printf("%s", message);
        if (scanf("%d", &v) != 1) {
            while (getchar() != '\n');
            v = min - 1;
        }
    } while (v < min || v > max);
    while (getchar() != '\n');   /* clear leftover Enter */
    return v;
}
void readtext(char message[], char text[], int size)
{
    printf("%s", message);
    if (fgets(text, size, stdin) != NULL)
        text[strcspn(text, "\n")] = '\0';
    else
        text[0] = '\0';
}
void updatepatient()
{
    int id, index;
    id = readinteger("Enter Patient ID to update: ", 1, 999999);
    index = findpatient(id);
    if (index == -1) {
        printf("Patient not found!\n");
    }
    else {
        printf("\nEnter new patient information:\n");
        readtext("Enter new name: ", patients[index].name, sizeof(patients[index].name));
        patients[index].age = readinteger("Enter new age: ", 1, 120);
        readtext("Enter new gender: ", patients[index].gender, sizeof(patients[index].gender));
        readtext("Enter new disease: ", patients[index].disease, sizeof(patients[index].disease));
        readtext("Enter new phone number: ", patients[index].phone, sizeof(patients[index].phone));
        printf("\nPatient updated successfully!\n");
        saverecords();
    }
}
void deletepatient()
{
    int id, index, i;
    id = readinteger("Enter Patient ID to delete: ", 1, 999999);
    index = findpatient(id);
    if (index == -1) {
        printf("Patient not found!\n");
    }
    else {
        for (i = index; i < patientCount - 1; i++)
            patients[i] = patients[i + 1];
        patientCount--;
        printf("\nPatient deleted successfully!\n");
        saverecords();
    }
}
void saverecords()
{
    FILE *fp;
    int i;
    fp = fopen("patients.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (i = 0; i < patientCount; i++)
        fwrite(&patients[i], sizeof(struct Patient), 1, fp);
    fclose(fp);
    printf("\nRecords saved successfully!\n");
}
void loadrecords()
{
    FILE *fp;
    fp = fopen("patients.dat", "rb");
    patientCount = 0;
    if (fp == NULL)
        return;
    while (patientCount < MAX &&
           fread(&patients[patientCount], sizeof(struct Patient), 1, fp) == 1)
        patientCount++;
    fclose(fp);
    printf("%d records loaded successfully!\n",patientCount);
}
void addpatient()
{
    int id;
    if (patientCount >= MAX) {
        printf("Storage is full\n");
        return;
    }
    printf("ADD NEW ENTRY\n");
    id = readinteger("Enter Patient ID: ", 1, 999999);

    if (findpatient(id) != -1) {
        printf("ID already registered\n");
        return;
    }
    patients[patientCount].id = id;
    readtext("Enter Patient Name: ", patients[patientCount].name,
         sizeof(patients[patientCount].name));
    patients[patientCount].age = readinteger("Enter Patient Age: ", 1, 120);
    readtext("Enter Gender: ", patients[patientCount].gender,
        sizeof(patients[patientCount].gender));
    readtext("Enter Phone Number: ", patients[patientCount].phone,
        sizeof(patients[patientCount].phone));
    readtext("Enter Disease: ", patients[patientCount].disease,
         sizeof(patients[patientCount].disease));
    patientCount++;
    saverecords();
    printf("\nPatient record created\n");
}
void displaypatient()
{
    int i;
    printf("\nPATIENT RECORDS\n");
    if (patientCount == 0) {
        printf("No patient records available.\n");
        return;
    }
    for (i = 0; i < patientCount; i++) {
        struct Patient *p = &patients[i];
        printf("\nPatient %d\n", i + 1);
        printf("ID      : %d\n", p->id);
        printf("Name    : %s\n", p->name);
        printf("Age     : %d\n", p->age);
        printf("Gender  : %s\n", p->gender);
        printf("Phone   : %s\n", p->phone);
        printf("Disease : %s\n", p->disease);
        printf("-------------------\n");
    }
}
void searchpatient()
{
    int id, index;
    printf("\nSEARCH PATIENT\n");
    id = readinteger("Enter Patient ID: ", 1, 999999);
    index = findpatient(id);
    if (index == -1) {
        printf("\nNo matching records\n");
    }
    else {
        printf("\nPatient Found!\n");
        printf("ID      : %d\n", patients[index].id);
        printf("Name    : %s\n", patients[index].name);
        printf("Age     : %d\n", patients[index].age);
        printf("Gender  : %s\n", patients[index].gender);
        printf("Phone   : %s\n", patients[index].phone);
        printf("Disease : %s\n", patients[index].disease);
    }
}
