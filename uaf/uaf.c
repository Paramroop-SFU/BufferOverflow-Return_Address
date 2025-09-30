#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADMIN 1
#define USER  2

typedef struct {
    int role;       // role: USER or ADMIN
    char name[16];  // username (15 chars + null)
} User;

User *defaultUser = NULL;   // global pointers for simplicity
User *another = NULL;

void addUser() {
    if (another == NULL) {
        another = (User *)malloc(sizeof(User));
        printf("[+] Created user at %p\n", another);

        // safer input for name
        printf("Enter name for another user (max 15 chars): ");
        fgets(another->name, sizeof(another->name), stdin);
        another->name[strcspn(another->name, "\n")] = '\0'; // strip newline

        // student is asked to set the role
        printf("Enter numeric role for another user: ");
        scanf("%d", &another->role);
        getchar(); // consume newline

    } else {
        printf("[-] No more space for users.\n");
    }
}

void deleteUser() {
    int choice;
    printf("Delete which user? (1 = defaultUser, 2 = another): ");
    scanf("%d", &choice);
    getchar(); // consume newline

    if (choice == 1 && defaultUser != NULL) {
        free(defaultUser);
        printf("[!] Delete defaultUser.\n");
    } else if (choice == 2 && another != NULL) {
        free(another);
        another = NULL;
        printf("[!] Delete another user.\n");
    } else {
        printf("[-] Invalid choice or already freed.\n");
    }
}

void checkPrivileges() {
    if (defaultUser != NULL && defaultUser->role == ADMIN) {
        printf("\n[+] Privilege escalation! defaultUser is now admin!\n");
    } else {
        printf("\n[-] Still a normal user.\n");
    }
}

int main() {
    int option;

    defaultUser = (User *)malloc(sizeof(User));
    strncpy(defaultUser->name, "Alice", 15);
    defaultUser->name[15] = '\0';
    defaultUser->role = USER;
    printf("[+] defaultUser at %p\n", defaultUser);

    while (1) {
        printf("\n=== MENU ===\n");
        printf("1. Add User\n");
        printf("2. Delete User\n");
        printf("3. Check Privileges\n");
        printf("4. Exit\n");
        printf("> ");
        scanf("%d", &option);
        getchar(); // consume newline

        switch (option) {
            case 1: addUser(); break;
            case 2: deleteUser(); break;
            case 3: checkPrivileges(); break;
            case 4: return 0;
            default: printf("[-] Invalid choice\n");
        }
    }
}

