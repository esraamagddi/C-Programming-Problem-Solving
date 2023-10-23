#include <stdio.h>

int main() {
    char text[100];

    printf("Enter a line of text (with spaces): ");
    scanf(" %[^\n]", text);
    printf("You entered: %s\n", text);

    return 0;
}
