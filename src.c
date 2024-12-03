#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#define A4 440.0
#define TEMPO 50
#define MAX_USERS 10
#define MAX_NOTES 5


void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// Structure to represent a note
typedef struct
{
    char note; // Note character (A, B, C, etc.)
    int semitoneOffset;
    int octaves; // Semitone offset relative to A4
} Note;

// Array of notes for each octave
Note note1[29] = {
    {'A', -48, 0},
    {'&', -47, 0},
    {'B', -46, 0},
    {'C', -45, 1},
    {'#', -44, 1},
    {'D', -43, 1},
    {'*', -42, 1},
    {'E', -41, 1},
    {'F', -40, 1},
    {'!', -39, 1},
    {'G', -38, 1},
    {'%', -37, 1},
    {'A', -36, 1},
    {'A', -36, 1},
    {'&', -35, 1},
    {'B', -34, 1},
    {'C', -33, 2},
    {'#', -32, 2},
    {'D', -31, 2},
    {'*', -30, 2},
    {'E', -29, 2},
    {'!', -27, 2},
    {'F', -28, 2},
    {'G', -26, 2},
    {'%', -25, 2},
    {'A', -24, 2},
    {'&', -23, 2},
    {'B', -22, 2},
    {'C', -21, 3},
    {'#', -20, 3}};
Note note2[29] = {
    {'D', -19, 3},
    {'*', -18, 3},
    {'E', -17, 3},
    {'F', -16, 3},
    {'!', -15, 3},
    {'G', -14, 3},
    {'%', -13, 3},
    {'A', -12, 3},
    {'A', -12, 3},
    {'&', -11, 3},
    {'B', -10, 3},
    {'C', -9, 4},
    {'#', -8, 4},
    {'D', -7, 4},
    {'*', -6, 4},
    {'E', -5, 4},
    {'F', -4, 4},
    {'!', -3, 4},
    {'G', -2, 4},
    {'%', -1, 4},
    {'A', 0, 4},
    {'&', 1, 4},
    {'B', 2, 4},
    {'C', 3, 5},
    {'#', 4, 5},
    {'D', 5, 5},
    {'*', 6, 5},
    {'E', 7, 5},
    {'F', 8, 5},
    {'!', 9, 5}};
Note note3[30] = {
    {'G', 10, 5},
    {'%', 11, 5},
    {'A', 12, 5},
    {'&', 13, 5},
    {'B', 14, 5},
    {'C', 15, 6},
    {'#', 16, 6},
    {'D', 17, 6},
    {'*', 18, 6},
    {'E', 19, 6},
    {'F', 20, 6},
    {'!', 21, 6},
    {'G', 22, 6},
    {'%', 23, 6},
    {'A', 24, 6},
    {'&', 25, 6},
    {'B', 26, 6},
    {'C', 27, 7},
    {'#', 28, 7},
    {'D', 29, 7},
    {'*', 30, 7},
    {'E', 31, 7},
    {'F', 32, 7},
    {'!', 33, 7},
    {'G', 34, 7},
    {'%', 35, 7},
    {'A', 36, 7},
    {'&', 37, 7},
    {'B', 38, 7},
    {'C', 39, 8}};
double getFrequency(char note, int octave, int choice)
{
    int i;
    if (choice == 1)
    {
        for (i = 0; i < 29; i++)
        {
            if (note1[i].note == note)
            {
                int semitoneOffset = note1[i].semitoneOffset;
                return A4 * pow(2.0, (semitoneOffset + (octave - 4) * 12) / 12.0);
            }
        }
        return A4;
    }
    if (choice == 2)
    {
        for (i = 0; i < 29; i++)
        {
            if (note2[i].note == note)
            {
                int semitoneOffset = note2[i].semitoneOffset;
                return A4 * pow(2.0, (semitoneOffset + (octave - 4) * 12) / 12.0);
            }
        }
        return A4;
    }
    if (choice == 3)
    {
        for (i = 0; i < 30; i++)
        {
            if (note3[i].note == note)
            {
                int semitoneOffset = note3[i].semitoneOffset;
                return A4 * pow(2.0, (semitoneOffset + (octave - 4) * 12) / 12.0);
            }
        }
        return A4;
    }
}

// Structure to store user info
typedef struct {
    char name[50];
    char notes[MAX_NOTES][4];  // Store up to 5 notes, each note has a letter and octave 
} User;
User users[MAX_USERS];  // Array to store users
int userCount = 0;      // Keep track of the number of users

// Function to save the user data to a file
void saveUsersToFile() {
    FILE *file = fopen("users.txt", "w");
    if (file == NULL) {
        printf("Error saving users to file!\n");
        return;
    }
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s\n", users[i].name);
        for (int j = 0; j < MAX_NOTES; j++) {
            if (users[i].notes[j][0] != '\0') {
                fprintf(file, "%s ", users[i].notes[j]);
            }
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Function to load users from file
void loadUsersFromFile() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        return;  // If the file doesn't exist, no users are loaded
    }
    while (fscanf(file, "%s", users[userCount].name) != EOF) {
        for (int i = 0; i < MAX_NOTES; i++) {
            if (fscanf(file, "%s", users[userCount].notes[i]) != 1) break;
        }
        userCount++;
        if (userCount >= MAX_USERS) break;  // Prevent array overflow
    }
    fclose(file);
}

// Function to add a new user
void addUser() {
    if (userCount >= MAX_USERS) {
        printf("Maximum user limit reached!\n");
        return;
    }

    // Get the user's name
    printf("Enter user name: ");
    fgets(users[userCount].name, sizeof(users[userCount].name), stdin);
    users[userCount].name[strcspn(users[userCount].name, "\n")] = '\0';  // Remove newline character

    // Ask for the notes the user wants to store (up to MAX_NOTES)
    printf("Enter up to %d notes for %s (e.g. A1, B2, C3):\n", MAX_NOTES, users[userCount].name);
    for (int i = 0; i < MAX_NOTES; i++) {
        char note[4];  // A note can be represented by 3 characters, like 'A1#'
        printf("Note %d: ", i + 1);
        fgets(note, sizeof(note), stdin);
        note[strcspn(note, "\n")] = '\0';  // Remove newline character

        // If the user just presses Enter (empty string), stop entering notes
        if (note[0] == '\0') {
            break;
        }

        // Validate the input (it should be a valid note like "A1", "B2#", etc.)
        if (strlen(note) == 2 || (strlen(note) == 3 && note[1] == '#')) {
            // Store the note (e.g. "A1", "B2#")
            strcpy(users[userCount].notes[i], note);
        } else {
            printf("Invalid note format. Please enter a valid note.\n");
            i--;  // Decrement to allow the user to try again for the same index
        }
    }

    userCount++;
    saveUsersToFile();
    printf("User added successfully!\n");
}

// Function to view all users
void viewUsers() {
    if (userCount == 0) {
        printf("No users found!\n");
        return;
    }
    for (int i = 0; i < userCount; i++) {
        printf("User: %s\nNotes: ", users[i].name);
        for (int j = 0; j < MAX_NOTES; j++) {
            if (users[i].notes[j][0] != '\0') {
                printf("%s ", users[i].notes[j]);
            }
        }
        printf("\n");
    }
}


void playNote(char note, int octave, int duration, int choice)
{
    double frequency = getFrequency(note, octave, choice);
    Beep((int)frequency, duration);
}
void handleKeyPress(int choice, char key)
{
    if (choice == 1)
    {

        switch (key)
        {
        case 'q':
            playNote('A', 0, TEMPO, 1);
            break;
        case '2':
            playNote('&', 0, TEMPO, 1);
            break;
        case 'w':
            playNote('B', 0, TEMPO, 1);
            break;
        case 'e':
            playNote('C', 1, TEMPO, 1);
            break;
        case '4':
            playNote('#', 1, TEMPO, 1);
            break;
        case 'r':
            playNote('D', 1, TEMPO, 1);
            break;
        case '5':
            playNote('*', 1, TEMPO, 1);
            break;
        case 't':
            playNote('E', 1, TEMPO, 1);
            break;
        case 'y':
            playNote('F', 1, TEMPO, 1);
            break;
        case '7':
            playNote('!', 1, TEMPO, 1);
            break;
        case 'u':
            playNote('G', 1, TEMPO, 1);
            break;
        case '8':
            playNote('%', 1, TEMPO, 1);
            break;
        case 'i':
            playNote('A', 1, TEMPO, 1);
            break;
        case '9':
            playNote('&', 1, TEMPO, 1);
            break;
        case 'o':
            playNote('B', 1, TEMPO, 1);
            break;
        case 'z':
            playNote('C', 2, TEMPO, 1);
            break;
        case 's':
            playNote('#', 2, TEMPO, 1);
            break;
        case 'x':
            playNote('D', 2, TEMPO, 1);
            break;
        case 'd':
            playNote('*', 2, TEMPO, 1);
            break;
        case 'c':
            playNote('E', 2, TEMPO, 1);
            break;
        case 'v':
            playNote('F', 2, TEMPO, 1);
            break;
        case 'g':
            playNote('!', 2, TEMPO, 1);
            break;
        case 'b':
            playNote('G', 2, TEMPO, 1);
            break;
        case 'h':
            playNote('%', 2, TEMPO, 1);
            break;
        case 'n':
            playNote('A', 2, TEMPO, 1);
            break;
        case 'j':
            playNote('&', 2, TEMPO, 1);
            break;
        case 'm':
            playNote('B', 2, TEMPO, 1);
            break;
        case ',':
            playNote('C', 3, TEMPO, 1);
            break;
        case 'l':
            playNote('#', 3, TEMPO, 1);
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
        }
    }
    if (choice == 2)
    {
        switch (key)
        {
        case 'q':
            playNote('D', 3, TEMPO, 2);
            break;
        case '2':
            playNote('*', 3, TEMPO, 2);
            break;
        case 'w':
            playNote('E', 3, TEMPO, 2);
            break;
        case 'e':
            playNote('F', 3, TEMPO, 2);
            break;
        case '4':
            playNote('!', 3, TEMPO, 2);
            break;
        case 'r':
            playNote('G', 3, TEMPO, 2);
            break;
        case '5':
            playNote('%', 3, TEMPO, 2);
            break;
        case 't':
            playNote('A', 3, TEMPO, 2);
            break;
        case '6':
            playNote('&', 3, TEMPO, 2);
            break;
        case 'Y':
            playNote('B', 3, TEMPO, 2);
            break;
        case 'u':
            playNote('C', 4, TEMPO, 2);
            break;
        case '8':
            playNote('#', 4, TEMPO, 2);
            break;
        case 'i':
            playNote('D', 4, TEMPO, 2);
            break;
        case '9':
            playNote('*', 4, TEMPO, 2);
            break;
        case 'o':
            playNote('E', 4, TEMPO, 2);
            break;
        case 'z':
            playNote('F', 4, TEMPO, 2);
            break;
        case 's':
            playNote('!', 4, TEMPO, 2);
            break;
        case 'x':
            playNote('G', 4, TEMPO, 2);
            break;
        case 'd':
            playNote('%', 4, TEMPO, 2);
            break;
        case 'c':
            playNote('A', 4, TEMPO, 2);
            break;
        case 'v':
            playNote('&', 4, TEMPO, 2);
            break;
        case 'g':
            playNote('B', 4, TEMPO, 2);
            break;
        case 'b':
            playNote('C', 5, TEMPO, 2);
            break;
        case 'h':
            playNote('#', 5, TEMPO, 2);
            break;
        case 'n':
            playNote('D', 5, TEMPO, 2);
            break;
        case 'j':
            playNote('*', 5, TEMPO, 2);
            break;
        case 'm':
            playNote('E', 5, TEMPO, 2);
            break;
        case ',':
            playNote('F', 5, TEMPO, 2);
            break;
        case 'l':
            playNote('!', 5, TEMPO, 2);
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
        }
    }

    if (choice == 3)
    {
        switch (key)
        {
        case 'q':
            playNote('G', 5, TEMPO, 3);
            break;
        case '2':
            playNote('%', 5, TEMPO, 3);
            break;
        case 'w':
            playNote('A', 5, TEMPO, 3);
            break;
        case 'e':
            playNote('&', 5, TEMPO, 3);
            break;
        case '4':
            playNote('B', 5, TEMPO, 3);
            break;
        case 'r':
            playNote('C', 6, TEMPO, 3);
            break;
        case '5':
            playNote('#', 6, TEMPO, 3);
            break;
        case 't':
            playNote('D', 6, TEMPO, 3);
            break;
        case 'y':
            playNote('*', 6, TEMPO, 3);
            break;
        case '7':
            playNote('E', 6, TEMPO, 3);
            break;
        case 'u':
            playNote('F', 6, TEMPO, 3);
            break;
        case '8':
            playNote('!', 6, TEMPO, 3);
            break;
        case 'i':
            playNote('G', 6, TEMPO, 3);
            break;
        case '9':
            playNote('%', 6, TEMPO, 3);
            break;
        case 'o':
            playNote('A', 6, TEMPO, 3);
            break;
        case '0':
            playNote('&', 6, TEMPO, 3);
            break;
        case 'z':
            playNote('B', 6, TEMPO, 3);
            break;
        case 'x':
            playNote('C', 7, TEMPO, 3);
            break;
        case 'd':
            playNote('#', 7, TEMPO, 3);
            break;
        case 'c':
            playNote('D', 7, TEMPO, 3);
            break;
        case 'f':
            playNote('*', 7, TEMPO, 3);
            break;
        case 'v':
            playNote('E', 7, TEMPO, 3);
            break;
        case 'b':
            playNote('F', 7, TEMPO, 3);
            break;
        case 'h':
            playNote('!', 7, TEMPO, 3);
            break;
        case 'n':
            playNote('G', 7, TEMPO, 3);
            break;
        case 'j':
            playNote('%', 7, TEMPO, 3);
            break;
        case 'm':
            playNote('A', 7, TEMPO, 3);
            break;
        case 'k':
            playNote('&', 7, TEMPO, 3);
            break;
        case ',':
            playNote('B', 7, TEMPO, 3);
            break;
        case '.':
            playNote('C', 8, TEMPO, 3);
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
        }
    }
}
void printkeyboard(int choice1)
{
         if (choice1==1){
printf("\t\t\t\t+--------------------------------------------------------------------------------------------------------+\n");
printf("\t\t\t\t| `       |  1     A#0     3     C#1     D#     6     F#     G#     A#1     0     -     =      Backspace |\n");
printf("\t\t\t\t|--------------------------------------------------------------------------------------------------------|\n");
printf("\t\t\t\t| Tab     |     A0     B0     C1     D1     E1     F1     G1     A1     B1     P     [     ]     \     | |\n");
printf("\t\t\t\t|--------------------------------------------------------------------------------------------------------|\n");
printf("\t\t\t\t| Caps    |     A     C#2     D#2     F     F#2     G#2     A#2     K     C#3     ;     '     Enter      |\n");
printf("\t\t\t\t|--------------------------------------------------------------------------------------------------------|\n");
printf("\t\t\t\t| Shift   |     C2     D2     E2     F2     G2     A2     B2     C3     .     /     |     Shift          |\n");
printf("\t\t\t\t|--------------------------------------------------------------------------------------------------------|\n");
printf("\t\t\t\t| Ctrl    |     Alt     |     Spacebar     |     Alt     |     Ctrl                                      |\n");
printf("\t\t\t\t+--------------------------------------------------------------------------------------------------------+\n");
          }
    if (choice1 == 2)
    {
printf("\t\t\t\t+--------------------------------------------------------------------------------------------------------+\n");
printf("\t\t\t\t| `       |  1     D#3     3     F#3     G#3     A#3     7     C#4     D#4     0     -     =    Backspace|\n");
printf("\t\t\t\t|--------------------------------------------------------------------------------------------------------|\n");
printf("\t\t\t\t| Tab     |     D3     E3     F3     G3     A3     B3     C4     D4     E4     P     [     ]     \       | |\n");
printf("\t\t\t\t|--------------------------------------------------------------------------------------------------------|\n");
printf("\t\t\t\t| Caps    |     A     F#4     G#4     A#4     G     C#5     D#5     K     F#5     ;     '     Enter      |\n");
printf("\t\t\t\t|--------------------------------------------------------------------------------------------------------|\n");
printf("\t\t\t\t| Shift   |     F4     G4     A4     B4     C5     D5     E5     F5     .     /     |     Shift          |\n");
printf("\t\t\t\t|--------------------------------------------------------------------------------------------------------|\n");
printf("\t\t\t\t| Ctrl    |     Alt     |     Spacebar     |     Alt     |     Ctrl                                      |\n");
printf("\t\t\t\t+--------------------------------------------------------------------------------------------------------+\n");

           }
    if (choice1 == 3)
    {

printf("\t\t\t\t+--------------------------------------------------------------------------------------------------------+\n");
printf("\t\t\t\t| `       |  1     G#5     3     A#5     C#6     D#6     7     F#6     G#6     A#6     -     =   Backspace |\n");
printf("\t\t\t\t|----------------------------------------------------------------------------------------------------------|\n");
printf("\t\t\t\t| Tab     |     G5     A5     B5     C6     D6     E6     F6     G6     A6     P     [     ]     \      |  |\n");
printf("\t\t\t\t|--------------------------------------------------------------------------------------------------------- |\n");
printf("\t\t\t\t| Caps    |     A     S     C#7     D#7     G     F#7     G#7     A#7     L     ;     '     Enter          |\n");
printf("\t\t\t\t|----------------------------------------------------------------------------------------------------------|\n");
printf("\t\t\t\t| Shift   |     B6     C7     D7     E7     F7     G7     A7     B7     C8     /     |     Shift           |\n");
printf("\t\t\t\t|----------------------------------------------------------------------------------------------------------|\n");
printf("\t\t\t\t| Ctrl    |     Alt     |     Spacebar     |     Alt     |     Ctrl                                        |\n");
printf("\t\t\t\t+----------------------------------------------------------------------------------------------------------+\n");
    }
}
void play()
{
    int choice1;
    printf("                                         Enter your choice ");
    printf("\n                                             KEYS \n");
    printf("                                            1. A0-C#3\n");
    printf("                                            2. D3-F#5\n");
    printf("                                            3. G5-C8\n");
    scanf("%d", &choice1);
    printkeyboard(choice1);

    while (1)
    {
        if (_kbhit())
        {
            char key = _getch();
            handleKeyPress(choice1, key);
        }
    }
}
void about()
{
    printf("\nVirtual Piano Program\n");
    printf("\n");
    printf("       This is a simple virtual piano program where you can play musical notes using your keyboard.\n");
    printf("                            You can add new users for a personalized experience.\n\n");
    printf("\n");
    setColor(12);
    printf("                      Developed by: Hammad Younus (24K-0689)\n");
    setColor(11);
    printf("                                    Jeevan Kumar  (24K-0689)\n");
    setColor(13);
    printf("                                    Zahran Ali  (24K-0689)\n");
    printf("\n");
    printf("Press any key to return to the menu.\n");
    _getch(); // Wait for user input before returning to menu
}

void displayMenu()
{
    printf("\n                                       Virtual Piano Interface\n");
    printf("                                            1. Play Piano\n");
    printf("                                            2. View About\n");
    printf("                                            3. Add New User\n");
    printf("                                            4. View Users\n");
    printf("                                            5. Exit\n");
    printf("\n");
    printf("                                         Please choose an option: \n");
}

int main()
{
int choice;
    loadUsersFromFile();  // Load saved users on start

    setColor(11);
    printf("        *****************************************************************************************************************************************\n");
    printf("        *                 *                                                                                                  *                  *\n");
    printf("        *                 *                          ********************************************                            *                  *\n");
    printf("        *                 *                          *  **************************************  *                            *                  *\n");
    printf("        *                 *                          *  *                                    *  *                            *                  *\n");
    printf("        *                 *                          *  *         Piano Simulator            *  *                            *                  *\n");
    printf("        *                 *                          *  *                                    *  *                            *                  *\n");
    printf("        *                 *                          *  **************************************  *                            *                  *\n");
    printf("        *                 *                          ********************************************                            *                  *\n");
    printf("        *                 *                                                                                                  *                  *\n");
    printf("        *****************************************************************************************************************************************");
    printf("\n");
    printf("\n");
    while (1)
    {
        displayMenu();
        choice = _getch() - '0'; // Get user input for menu option

        if (choice == 5)
        {
            break; // Exit the program
        }

        switch (choice)
        {
        case 1:
            play(); // playing sounds
            break;

        case 2:
            about(); // Display program information
            break;

         case 3:
             addUser(); // Add a new user
             break;

         case 4:
             viewUsers(); // View all added users
             break;

        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}
