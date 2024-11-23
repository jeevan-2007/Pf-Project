#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

#define A4 440.0
#define TEMPO 100

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
        case 'y':
            playNote('&', 3, TEMPO, 2);
            break;
        case '7':
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
            case '0':
                playNote('A', 6, TEMPO, 3);
                break;
            case 'z':
                playNote('&', 6, TEMPO, 3);
                break;
            case 's':
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
            case 'v':
                playNote('*', 7, TEMPO, 3);
                break;
            case 'g':
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
            case ',':
                playNote('&', 7, TEMPO, 3);
                break;
            case 'l':
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
}
int main()
{
    int choice;
    printf("Enter the octave range you want:\n1. A0-C#3\n2. D3-F#5\n3. G5-C8\n");
    scanf("%d", &choice);
    printf("Press keys z-m for notes C4-B4, s-k for notes C5-B5. Press ESC to exit.\n");

    while (1)
    {
        if (_kbhit())
        {
            char key = _getch();
            handleKeyPress(choice, key);
        }
    }

    return 0;
}
