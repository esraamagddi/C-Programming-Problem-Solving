#include <stdio.h>
#include <conio.h>
#include <windows.h>


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
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    const int maxLineLength = 80;
    char line[maxLineLength];
    int cursorPos = 0;
    int lineLength = 0;
    int ch;

    while (1) {
        system("cls");

        printf("Line Editor (Press Enter to finish)\n");
        printf("------------------------------------------------\n");


        printf("Line: %s\n", line);


        printf("Cursor Position: %d\n", cursorPos);

        // move to current position
        gotoxy(cursorPos, 2);

        // user input
        ch = getch();

        if (ch == 13) {
            // Enter key - finish editing
            break;
        } else if (ch == 8) {
            // backspace-->delete
            if (cursorPos > 0) {
                for (int i = cursorPos - 1; i < lineLength; i++) {
                    line[i] = line[i + 1];
                }
                lineLength--;
                cursorPos--;
            }
        } else if (ch == 127) {
            // delete
            if (cursorPos < lineLength) {
                for (int i = cursorPos; i < lineLength; i++) {
                    line[i] = line[i + 1];
                }
                lineLength--;
            }
        } else {
            // insert
            if (lineLength < maxLineLength) {
                for (int i = lineLength; i > cursorPos; i--) {
                    line[i] = line[i - 1];
                }
                line[cursorPos] = ch;
                lineLength++;
                cursorPos++;
            }
        }
    }

    system("cls"); // Clear the screen
    printf("Edited Line: %s\n", line);

    return 0;
}
