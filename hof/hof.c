#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADMIN 0x1334
#define USER 0x1333

typedef struct {
    int role;    // role: "user" or "admin"
    char name[16];   // user's name
} User;

int main() {
    // Allocate two users on the heap
    User *normalUser = (User *)malloc(sizeof(User));
    User *anotherUser = (User *)malloc(sizeof(User));

    // Initialize values
    strcpy(normalUser->name, "Alice");
    normalUser->role = USER;

    strcpy(anotherUser->name, "Bob");
    anotherUser->role = USER;

    // Ask for input
    printf("\nEnter new name for User1: ");
    gets(normalUser->name);

    printf("\nEnter new name for User2: ");
    gets(anotherUser->name);


    // Check privilege on victim user
    if (normalUser->role == ADMIN || anotherUser->role == ADMIN) {
        printf("\n[+] Congrats! You are now admin!\n");
    } else {
        printf("\n[-] Nah, regular user.\n");
    }

    free(normalUser);
    free(anotherUser);
    return 0;
}
