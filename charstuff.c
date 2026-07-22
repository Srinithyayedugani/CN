#include <stdio.h>
#include <string.h>
#define SFLAG '$'  
#define EFLAG '#'
#define ESC  '@' 
int main() {
    char data[100];
    char stuffed[200]; 
    int i = 0, j = 0;
    printf("Enter data to send: ");
    scanf("%s",data);
    stuffed[j++] = SFLAG;
    while (data[i] != '\0') {
       if (data[i] == SFLAG || data[i] == ESC) {
            stuffed[j++] = ESC; 
        }
        if (data[i] == EFLAG || data[i] == ESC) {
            stuffed[j++] = ESC; 
        }
        stuffed[j++] = data[i++];
    }
    stuffed[j++] = EFLAG;
    stuffed[j] = '\0'; 
    printf("Original Data: %s\n", data);
    printf("Stuffed Data : %s\n", stuffed);
    return 0;
}

