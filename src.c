#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

#define A4 440.0
#define TEMPO 100

double getFrequency(char note, int octave) {
    int semitoneOffset;
    if(octave == 0){
    switch (note) {
        case 'A': semitoneOffset = -48; break;
        case '&': semitoneOffset = -47; break;//A#
        case 'B': semitoneOffset = -46; break;}
    }
    if(octave == 1){
    switch (note) {
        case 'C': semitoneOffset = -45; break;
        case '#': semitoneOffset = -44; break;//C#
        case 'D': semitoneOffset = -43; break;
        case '*': semitoneOffset = -42; break;
        case 'E': semitoneOffset = -41; break;
        case 'F': semitoneOffset = -40; break;
        case '!': semitoneOffset = -39; break;
        case 'G': semitoneOffset = -38; break;
        case '%': semitoneOffset = -37; break;
        case 'A': semitoneOffset = -36; break;
        case '&': semitoneOffset = -35; break;//A#
        case 'B': semitoneOffset = -34; break;
        default: semitoneOffset = 0; break;
    }}
    if(octave == 2){
    switch (note) {
        case 'C': semitoneOffset = -33; break;
        case '#': semitoneOffset = -32; break;//C#
        case 'D': semitoneOffset = -31; break;
        case '*': semitoneOffset = -30; break;
        case 'E': semitoneOffset = -29; break;
        case 'F': semitoneOffset = -28; break;
        case '!': semitoneOffset = -27; break;
        case 'G': semitoneOffset = -26; break;
        case '%': semitoneOffset = -25; break;
        case 'A': semitoneOffset = -24; break;
        case '&': semitoneOffset = -23; break;//A#
        case 'B': semitoneOffset = -22; break;
        default: semitoneOffset = 0; break;
    }
    }
    if(octave == 3){
    switch (note) {
        case 'C': semitoneOffset = -21; break;
        case '#': semitoneOffset = -20; break;//C#
        case 'D': semitoneOffset = -19; break;
        case '*': semitoneOffset = -18; break;
        case 'E': semitoneOffset = -17; break;
        case 'F': semitoneOffset = -16; break;
        case '!': semitoneOffset = -15; break;
        case 'G': semitoneOffset = -14; break;
        case '%': semitoneOffset = -13; break;
        case 'A': semitoneOffset = -12; break;
        case '&': semitoneOffset = -11; break;//A#
        case 'B': semitoneOffset = -10; break;
        default: semitoneOffset = 0; break;
    }
}   if(octave == 4){
    switch (note) {
        case 'C': semitoneOffset = -9; break;
        case '#': semitoneOffset = -8; break;//C#
        case 'D': semitoneOffset = -7; break;
        case '*': semitoneOffset = -6; break;
        case 'E': semitoneOffset = -5; break;
        case 'F': semitoneOffset = -4; break;
        case '!': semitoneOffset = -3; break;
        case 'G': semitoneOffset = -2; break;
        case '%': semitoneOffset = -1; break;
        case 'A': semitoneOffset = 0; break;
        case '&': semitoneOffset = 1; break;//A#
        case 'B': semitoneOffset = 2; break;
        default: semitoneOffset = 0; break;
    }
}
    if(octave == 5){
    switch (note) {
        case 'C': semitoneOffset = 3; break;
        case '#': semitoneOffset = 4; break;//C#
        case 'D': semitoneOffset = 5; break;
        case '*': semitoneOffset = 6; break;//D#
        case 'E': semitoneOffset = 7; break;
        case 'F': semitoneOffset = 8; break;
        case '!': semitoneOffset = 9; break;//F#
        case 'G': semitoneOffset = 10; break;
        case '%': semitoneOffset = 11; break;//G#
        case 'A': semitoneOffset = 12; break;
        case '&': semitoneOffset = 13; break;//A#
        case 'B': semitoneOffset = 14; break;
        default: semitoneOffset = 0; break;
    }
    }
    if(octave == 6){
    switch (note) {
        case 'C': semitoneOffset = 15; break;
        case '#': semitoneOffset = 16; break;//C#
        case 'D': semitoneOffset = 17; break;
        case '*': semitoneOffset = 18; break;//D#
        case 'E': semitoneOffset = 19; break;
        case 'F': semitoneOffset = 20; break;
        case '!': semitoneOffset = 21; break;//F#
        case 'G': semitoneOffset = 22; break;
        case '%': semitoneOffset = 23; break;//G#
        case 'A': semitoneOffset = 24; break;
        case '&': semitoneOffset = 25; break;//A#
        case 'B': semitoneOffset = 26; break;
        default: semitoneOffset = 0; break;
    }
    }
    if(octave == 7){
    switch (note) {
        case 'C': semitoneOffset = 27; break;
        case '#': semitoneOffset = 28; break;//C#
        case 'D': semitoneOffset = 29; break;
        case '*': semitoneOffset = 30; break;//D#
        case 'E': semitoneOffset = 31; break;
        case 'F': semitoneOffset = 32; break;
        case '!': semitoneOffset = 33; break;//F#
        case 'G': semitoneOffset = 34; break;
        case '%': semitoneOffset = 35; break;//G#
        case 'A': semitoneOffset = 36; break;
        case '&': semitoneOffset = 37; break;//A#
        case 'B': semitoneOffset = 38; break;
        default: semitoneOffset = 0; break;
    }
    }
    if(octave == 8){
    switch (note) {
        case 'C': semitoneOffset = 39; break;
        default: semitoneOffset = 0; break;
    }
    }
    return A4 * pow(2.0, (semitoneOffset + (octave - 4) * 12) / 12.0);
}

void playNote(char note, int octave, int duration) {
    double frequency = getFrequency(note, octave);
    Beep((int)frequency, duration);
}

void handleKeyPress(int choice,char key) {
    if(choice == 1){
    switch (key) {
        case 'q': playNote('A', 0, TEMPO); break;
        case '2': playNote('&', 0, TEMPO); break;
        case 'w': playNote('B', 0, TEMPO); break;
        case 'e': playNote('C', 1, TEMPO); break;
        case '4': playNote('#', 1, TEMPO); break;
        case 'r': playNote('D', 1, TEMPO); break;
        case '5': playNote('*', 1, TEMPO); break;
        case 't': playNote('E', 1, TEMPO); break;
        case 'y': playNote('F', 1, TEMPO); break;
        case '7': playNote('!', 1, TEMPO); break;
        case 'u': playNote('G', 1, TEMPO); break;
        case '8': playNote('%', 1, TEMPO); break;
        case 'i': playNote('A', 1, TEMPO); break;
        case '9': playNote('&', 1, TEMPO); break;
        case '0': playNote('B', 1, TEMPO); break;
        case 'z': playNote('C', 2, TEMPO); break;
        case 's': playNote('#', 2, TEMPO); break;
        case 'x': playNote('D', 2, TEMPO); break;
        case 'd': playNote('*', 2, TEMPO); break;
        case 'c': playNote('E', 2, TEMPO); break;
        case 'v': playNote('F', 2, TEMPO); break;
        case 'g': playNote('!', 2, TEMPO); break;
        case 'b': playNote('G', 2, TEMPO); break;
        case 'h': playNote('%', 2, TEMPO); break;
        case 'n': playNote('A', 2, TEMPO); break;
        case 'j': playNote('&', 2, TEMPO); break;
        case 'm': playNote('B', 2, TEMPO); break;
        case ',': playNote('C', 3, TEMPO); break;
        case 'l': playNote('#', 3, TEMPO); break;    
        case 27: exit(0); break; 
        default: break;
    }
}
    if(choice == 2){
    switch (key) {
        case 'q': playNote('D', 3, TEMPO); break;
        case '2': playNote('*', 3, TEMPO); break;
        case 'w': playNote('E', 3, TEMPO); break;
        case 'e': playNote('F', 3, TEMPO); break;
        case '4': playNote('!', 3, TEMPO); break;
        case 'r': playNote('G', 3, TEMPO); break;
        case '5': playNote('%', 3, TEMPO); break;
        case 't': playNote('A', 3, TEMPO); break;
        case 'y': playNote('&', 3, TEMPO); break;
        case '7': playNote('B', 3, TEMPO); break;
        case 'u': playNote('C', 4, TEMPO); break;
        case '8': playNote('#', 4, TEMPO); break;
        case 'i': playNote('D', 4, TEMPO); break;
        case '9': playNote('*', 4, TEMPO); break;
        case '0': playNote('E', 4, TEMPO); break;
        case 'z': playNote('F', 4, TEMPO); break;
        case 's': playNote('!', 4, TEMPO); break;
        case 'x': playNote('G', 4, TEMPO); break;
        case 'd': playNote('%', 4, TEMPO); break;
        case 'c': playNote('A', 4, TEMPO); break;
        case 'v': playNote('&', 4, TEMPO); break;
        case 'g': playNote('B', 4, TEMPO); break;
        case 'b': playNote('C', 5, TEMPO); break;
        case 'h': playNote('#', 5, TEMPO); break;
        case 'n': playNote('D', 5, TEMPO); break;
        case 'j': playNote('*', 5, TEMPO); break;
        case 'm': playNote('E', 5, TEMPO); break;
        case ',': playNote('F', 5, TEMPO); break;
        case 'l': playNote('!', 5, TEMPO); break;    
        case 27: exit(0); break; 
        default: break;
    }
}
 if(choice == 3){
    switch (key) {
        case 'q': playNote('G', 5, TEMPO); break;
        case '2': playNote('%', 5, TEMPO); break;
        case 'w': playNote('A', 5, TEMPO); break;
        case 'e': playNote('&', 5, TEMPO); break;
        case '4': playNote('B', 5, TEMPO); break;
        case 'r': playNote('C', 6, TEMPO); break;
        case '5': playNote('#', 6, TEMPO); break;
        case 't': playNote('D', 6, TEMPO); break;
        case 'y': playNote('*', 6, TEMPO); break;
        case '7': playNote('E', 6, TEMPO); break;
        case 'u': playNote('F', 6, TEMPO); break;
        case '8': playNote('!', 6, TEMPO); break;
        case 'i': playNote('G', 6, TEMPO); break;
        case '9': playNote('%', 6, TEMPO); break;
        case '0': playNote('A', 6, TEMPO); break;
        case 'z': playNote('&', 6, TEMPO); break;
        case 's': playNote('B', 6, TEMPO); break;
        case 'x': playNote('C', 7, TEMPO); break;
        case 'd': playNote('#', 7, TEMPO); break;
        case 'c': playNote('D', 7, TEMPO); break;
        case 'v': playNote('*', 7, TEMPO); break;
        case 'g': playNote('E', 7, TEMPO); break;
        case 'b': playNote('F', 7, TEMPO); break;
        case 'h': playNote('!', 7, TEMPO); break;
        case 'n': playNote('G', 7, TEMPO); break;
        case 'j': playNote('%', 7, TEMPO); break;
        case 'm': playNote('A', 7, TEMPO); break;
        case ',': playNote('&', 7, TEMPO); break;
        case 'l': playNote('B', 7, TEMPO); break;
        case '.': playNote('C', 8, TEMPO); break;    
        case 27: exit(0); break; 
        default: break;
    }
}
}
int main() {
    int choice;
    printf("Wnter what octaves do you want : \n1.A0-C#3\n2.D3-F#5\n3.G5-C8");
    scanf("%d",&choice);
    printf("Press keys z-m for notes C4-B4, s-k for notes C5-B5. Press ESC to exit.\n");
    while (1) {
        if (_kbhit()) {
            char key = _getch();
            handleKeyPress(choice,key);
        }
    }
    return 0;
}
