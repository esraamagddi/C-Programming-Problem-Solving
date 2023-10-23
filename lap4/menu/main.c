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

// Define the student structure
struct student {
    char name[50];
    int age;
    int id;
    char gender;
};

// Insert with space validation
int insert(struct student students[], int count) {
    if (count < 100) {
        printf("Enter name (or press 'Esc' to cancel): ");
        int ch;
        int nameIndex = 0;
        students[count].name[0] = '\0'; // Initialize the name
        while (1) {
            ch = getch();
            if (ch == 13) {
                if (nameIndex == 0) {
                    printf("\nName is required. Press 'Esc' to cancel or enter a name.\n");
                    continue;
                }
                break; // Enter key pressed, finish entering the name
            } else if (ch == 27) {
                return 0; // Escape key pressed, cancel the insertion
            } else if (ch == 8 && nameIndex > 0) {
                nameIndex--;
                students[count].name[nameIndex] = '\0';
                printf("\b \b");
            } else if (nameIndex < 49) {
                students[count].name[nameIndex] = ch;
                nameIndex++;
                students[count].name[nameIndex] = '\0';
                printf("%c", ch);
            }
        }

        printf("\nEnter age: ");
        scanf("%d", &students[count].age);
        printf("Enter ID: ");
        scanf("%d", &students[count].id);

        // gender validation
        do {
            printf("Enter Gender (M/F) only: ");
            scanf(" %c", &students[count].gender);
            students[count].gender = toupper(students[count].gender); // Convert to uppercase
        } while (students[count].gender != 'M' && students[count].gender != 'F');

        printf("Student added.\n");
        return 1; // Successfully added a student
    } else {
        printf("You can't add more than 100.\n");
        return 0; // Failed to add a student
    }
}

// Display students records
void display(struct student students[], int count) {
    if (count > 0) {
        printf("Student Records:\n");
        for (int i = 0; i < count; i++) {
                //check empty
            if (strlen(students[i].name) > 0) {
                printf("Name: %s, Age: %d, ID: %d, Gender: %c\n",
                       students[i].name,
                       students[i].age,
                       students[i].id,
                       students[i].gender
                );
            } else {
                printf("Empty record found at index %d\n", i);
            }
        }
    } else {
        printf("No student records to display.\n");
    }
}

void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    int choice = 1;
    char key;
    int numItems = 3; // Number of menu items
    int count = 0; // count v

    struct student students[100]; // Array of student records

    while (1) {
        system("cls"); // system call ---> clear screen

        printf("Main Menu:\n\n");

        for (int i = 1; i <= numItems; i++) {
            if (i == choice) {
                SetColor(4); // Red for selected item
                printf("-> ");
            } else {
                SetColor(15); // White for unselected items
                printf("   ");
            }

            if (i == 1) {
                printf("New\n");
            } else if (i == 2) {
                printf("Display\n");
            } else if (i == 3) {
                printf("Exit\n");
            }
        }

        key = getch(); // Get a character from the user

        switch (key) {
            case 72: // Up arrow key
                choice--;
                if (choice < 1) choice = numItems;
                break;
            case 80: // Down arrow key
                choice++;
                if (choice > numItems) choice = 1;
                break;
            case 13: // Enter key
                system("cls"); // Clear the screen
                printf("You selected: ");
                if (choice == 1) {
                    printf("New\n");
                    int result = insert(students, count); // Calling the insert function
                    if (result) {
                        count++; // Increment the count of students
                    }
                } else if (choice == 2) {
                    printf("Display\n");
                    display(students, count); // Call the display function
                } else if (choice == 3) {
                    printf("Exit\n");
                    exit(0);
                }
                printf("Press Enter to continue...");
                getch(); // Wait for the user to press Enter
                break;
            case 27: // Escape key
                if (choice == 1) {
                    // User attempted to exit the insertion process
                    printf("New (Cancelled)\n");
                }
                break;
        }
    }

    return 0;
}
