#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define MAX_LINE_LENGTH 100

void SetColor(int ForgC) {
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    char line[MAX_LINE_LENGTH];
    int cursorPos = 0;
    int lineLength = 0;
    int ch;
    int inputX = 5; // cursor pos

    while (1) {
        system("cls");

        printf("Line Editor (Press Enter to finish)\n");//row1
        printf("----------------------------------\n");//row2

        // Display the line
        gotoxy(0, 2);
        printf("Line: %s", line);// iteration starts from the fifth charatcter

        // current input position ((5))
        gotoxy(inputX, 2);

        // User input
        ch = getch();

        if (ch == 13) {
            // Enter key -> finish editing
            break;
        } else if (ch == 224) {
            // Extended key -->(arrow key)
            ch = getch();
            if (ch == 77) { // Right arrow key
                cursorPos = (cursorPos < lineLength) ? cursorPos + 1 : cursorPos;
                inputX++; // Move cursor right
            } else if (ch == 75) { // Left arrow key
                cursorPos = (cursorPos > 0) ? cursorPos - 1 : cursorPos;
                inputX--; // Move cursor left
            } else if (ch == 83) { // Delete key
                if (cursorPos < lineLength) {
                    for (int i = cursorPos; i < lineLength; i++) {
                        line[i] = line[i + 1];
                    }
                    lineLength--;
                }
            }
        } else if (ch == 8) {
            // Backspace
            if (cursorPos > 0) {
                for (int i = cursorPos - 1; i < lineLength; i++) {
                    line[i] = line[i + 1];
                }
                lineLength--;
                cursorPos--;
                inputX--; // Move cursor left
            }
        } else {
            // Insert
            if (lineLength < MAX_LINE_LENGTH) {
                for (int i = lineLength; i > cursorPos; i--) {
                    line[i] = line[i - 1];
                }
                line[cursorPos] = ch;
                lineLength++;
                cursorPos++;
                inputX++; // Move cursor right
            }
        }
    }

    system("cls"); // Clear the screen
    printf("Edited Line: %s\n", line);

    return 0;
}
