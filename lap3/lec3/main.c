#include <stdio.h>

int main() {
    int x;
//error ha
    if (scanf("%d", &x) == 1) {
        printf("Correct, you entered an integer: %d\n", x);
    } else {
        printf("Please enter a valid integer.\n");
    }

    return 0;
}
