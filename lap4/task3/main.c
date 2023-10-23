
//3- Receive character by character and then place the string terminator upon pressing enter, then display the string.

#include <stdio.h>

int main() {
    char input[100]; // maximum

    printf("Enter a string (press Enter to finish):\n");

    int i = 0;
    char c;

    // Receive characters until Enter is pressed
    while (1) {
        c = getchar();

        // If Enter is pressed, terminate the string
        if (c == '\n') {
            input[i] = '\0';
            return 1;
        }

        input[i] = c;
        i++;

        // Check for string length limit
        if (i >= 99) {
            printf("String limit reached.\n");
            input[i] = '\0';
            return 1;
        }
    }

    // Display the entered string
    printf("Entered string: %s\n", input);

    return 0;
}





