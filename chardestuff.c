#include <stdio.h>
#include <string.h>
#define SFLAG '$'  
#define EFLAG '#'
#define ESC  '@' 
int main() {
    char data[50];
    char stuffed_data[100];
    char destuffed[200]; 
    int i = 0, j = 0;
    printf("Enter data to send: ");
    scanf("%s",data);
    stuffed_data[j++] = SFLAG;
    while(data[i]!='\0'){
       if (data[i] == SFLAG || data[i] == ESC) {
            stuffed_data[j++] = ESC; 
        }
        if (data[i] == EFLAG || data[i] == ESC) {
            stuffed_data[j++] = ESC; 
        }
								stuffed_data[j++] = data[i++];
    }
    stuffed_data[j++] = EFLAG;
    stuffed_data[j] = '\0'; 
			i=0,j=1;	
   while (stuffed_data[j] != EFLAG) {
        if (stuffed_data[j] == ESC) {
           j++; 
        }
        destuffed[i++]= stuffed_data[j++];
    }
    destuffed[i] = '\0'; 
    printf("Stuffed Data: %s\n", stuffed_data);
    printf("Destuffed Data : %s\n", destuffed);
    return 0;
}
