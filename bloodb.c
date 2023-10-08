#include <stdio.h>
#include <string.h>


struct Donor {
    char name[50];
    char bloodGroup[5];
    int age;
    char phoneNumber[15];
};


void addDonor();
void displayDonors();
void searchByBloodGroup();


struct Donor donors[100]; // can store data for 100 donors
int count = 0;

int main() {
    int choice;
    do {
        printf("\nBlood Bank Management System\n");
        printf("1. Add Donor\n");
        printf("2. Display Donors\n");
        printf("3. Search by Blood Group\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addDonor(); break;
            case 2: displayDonors(); break;
            case 3: searchByBloodGroup(); break;
            case 4: printf("Thank you for using the system!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}

void addDonor() {
    if(count < 100) {
        printf("\nEnter donor name: ");
        scanf("%s", donors[count].name);
        printf("Enter blood group: ");
        scanf("%s", donors[count].bloodGroup);
        printf("Enter age: ");
        scanf("%d", &donors[count].age);
        printf("Enter phone number: ");
        scanf("%s", donors[count].phoneNumber);
        count++;
    } else {
        printf("\nDatabase full! Cannot add more donors.\n");
    }
}

void displayDonors() {
    printf("\nList of Donors:\n");
    for(int i = 0; i < count; i++) {
        printf("Name: %s, Blood Group: %s, Age: %d, Phone: %s\n", donors[i].name, donors[i].bloodGroup, donors[i].age, donors[i].phoneNumber);
    }
}

void searchByBloodGroup() {
    char group[5];
    printf("\nEnter the blood group to search: ");
    scanf("%s", group);
    printf("\nDonors with blood group %s:\n", group);
    for(int i = 0; i < count; i++) {
        if(strcmp(donors[i].bloodGroup, group) == 0) {
            printf("Name: %s, Age: %d, Phone: %s\n", donors[i].name, donors[i].age, donors[i].phoneNumber);
        }
    }
}
