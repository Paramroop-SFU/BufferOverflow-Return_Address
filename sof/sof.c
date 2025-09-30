#include <stdio.h>
#include <string.h>

void vulnerable_function() {
    char buffer[10];  // small buffer (10 bytes)
    printf("Enter some text: ");

    gets(buffer);
    printf("You entered: %s\n", buffer);
}

void targe_function() {
    printf("Yes! You did it!\n");
}

int main() {
    vulnerable_function();
    printf("Sorry, you failed.\n");
    return 0;
}
