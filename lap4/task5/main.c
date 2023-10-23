#include <stdio.h>

int main() {
    //5- C Program to take firstName and lastName from user, then displays fullName.
    char firstName[50];
    char lastName[50];

    printf("Enter your first name: ");
    scanf("%s", firstName);

    printf("Enter your last name: ");
    scanf("%s", lastName);

    printf("Full name: %s %s\n", firstName, lastName);

    return 0;
}
