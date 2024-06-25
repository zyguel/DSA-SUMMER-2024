/*
	CODE BY: ZYGUEL PHILIP E. CABOGOY
	DSA SUMMER 2024
	HASHING OF STRINGS - USERNAME as KEY, User address as Value to find
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashUser.h"

int main() {
    UsrHashTable usrHT;
    initHashTable(&usrHT);

    while (1) {
        int choice;
        printf("\nMenu:\n");
        printf("1. Insert User\n");
        printf("2. Find User\n");
        printf("3. Delete User\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            UserPtr usr = (UserPtr)malloc(sizeof(User));
            usr->name = (char *)malloc(100 * sizeof(char));
            usr->address = (char *)malloc(100 * sizeof(char));
            printf("Enter user name: ");
            scanf("%s", usr->name);
            printf("Enter user address: ");
            scanf("%s", usr->address);
            insert(&usrHT, usr);
            getchar();
        } else if (choice == 2) {
            char name[100];
            printf("Enter user name to find: ");
            scanf("%s", name);
            UserPtr usr = find(&usrHT, name);
            if (usr != NULL) {
                printf("User found: Name = %s, Address = %s\n", usr->name, usr->address);
            } else {
                printf("User not found\n");
            }
            getchar();
        } else if (choice == 3) {
            char name[100];
            printf("Enter user name to delete: ");
            scanf("%s", name);
            delete_usr(&usrHT, name);
            getchar();
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
